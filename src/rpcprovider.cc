#include "rpcprovider.h"
#include "mprpcapplication.h"
#include "rpcheader.pb.h"
#include "logger.h"
#include "zookeeperutil.h"
/*
    service_name => service描述对象
*/
void RpcProvider::NotifyService(google::protobuf::Service *service)
{
    ServiceInfo serviceInfo;
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();
    // 获取服务的名字
    std::string serviceName = pserviceDesc->name();
    // 获取服务的方法的数量
    int methodCnt = pserviceDesc->method_count();
    // std::cout << "service name:" << serviceName << " method cnt:" << methodCnt << std::endl;
    M_RPC_LOG_INFO("service name:%s", serviceName.c_str());
    for (int i = 0; i < methodCnt; i++)
    {
        // 获取服务的方法的描述
        const google::protobuf::MethodDescriptor *pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        serviceInfo.m_methodMap.insert({method_name, pmethodDesc});
        // std::cout << "method name:" << method_name << std::endl;
        M_RPC_LOG_INFO("method name:%s", method_name.c_str());
    }
    serviceInfo.m_service = service;
    m_serviceMap.insert({serviceName, serviceInfo});
}
void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);
    // 创建TcpServer对象
    muduo::net::TcpServer server(&m_eventLoop, address, "RpcProvider");
    // 绑定连接回调和消息读写回调方法 分离了网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::OnMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    server.setThreadNum(4); // 设置muduo库的线程数量
    std::cout << "service start ip:" << ip << " port:" << port << std::endl;
    ZkClient ZkCli;
    ZkCli.Start();
    for (auto &sp : m_serviceMap)
    {
        std::string servicePath = "/" + sp.first;
        ZkCli.Create(servicePath.c_str(), nullptr, 0, 0);
        for (auto &mp : sp.second.m_methodMap)
        {
            std::string methodPath = servicePath + "/" + mp.first;
            char method_path_data[128] = {0};
            sprintf(method_path_data, "%s:%d", ip.c_str(), port);
            // 服务方法都是临时节点
            ZkCli.Create(methodPath.c_str(), method_path_data, strlen(method_path_data), ZOO_EPHEMERAL);
        }
    }
    server.start();
    m_eventLoop.loop();
    // 设置muduo库的线程数量
}
void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        conn->shutdown();
    }
}
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    // 网络上接收的远程rpc调用请求的字符流 ServiceName MethodName args
    std::string recvBuf = buffer->retrieveAllAsString();
    // 从字符流中读取前4个字节（一个整数）
    uint32_t header_size = 0;
    recvBuf.copy((char *)&header_size, 4, 0);
    // 根据header_size读取数据头的原始字符流
    std::string rpc_header_str = recvBuf.substr(4, header_size);
    mprpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    if (rpcHeader.ParseFromString(rpc_header_str))
    {
        // 数据头反序列化成功
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();
    }
    else
    {
        std::cout << "rpc header parse error" << std::endl;
        return;
    }
    std::string args_string = recvBuf.substr(4 + header_size, args_size);
    // std::cout<<"service_name:"<<service_name<<" method_name:"<<method_name<<" args_size:"<<args_size<<std::endl;
    std::cout << "service_name:" << service_name << " method_name:" << method_name << " args_string:" << args_string << std::endl;
    // 获取service对象和method对象
    auto it = m_serviceMap.find(service_name);
    // 判断服务是否存在
    if (it == m_serviceMap.end())
    {
        std::cout << "service_name:" << service_name << " is not exist!" << std::endl;
        return;
    }
    google::protobuf::Service *service = it->second.m_service; // 获取服务对象
    auto mit = it->second.m_methodMap.find(method_name);
    // 判断方法是否存在
    if (mit == it->second.m_methodMap.end())
    {
        std::cout << "method_name:" << method_name << " is not exist!" << std::endl;
        return;
    }
    const google::protobuf::MethodDescriptor *method = mit->second; // 获取方法对象
    // 生成rpc方法调用的请求和响应response
    google::protobuf::Message *request = service->GetRequestPrototype(method).New();
    if (!request->ParseFromString(args_string))
    {
        std::cout << "request parse error" << std::endl;
        return;
    }
    google::protobuf::Message *response = service->GetResponsePrototype(method).New();
    // 给下面的method方法的调用绑定一个closure的回调函数
    google::protobuf::Closure *done = google::protobuf::NewCallback<RpcProvider, const muduo::net::TcpConnectionPtr &, google::protobuf::Message *>(this, &RpcProvider::sendRpcResponse, conn, response);
    // 在框架上根据远端rpc请求，调用当前rpc节点上发布的方法
    service->CallMethod(method, nullptr, request, response, done);
}
void RpcProvider::sendRpcResponse(const muduo::net::TcpConnectionPtr &conn, google::protobuf::Message *response)
{
    // 组装rpc的响应字符流
    std::string response_str;
    if (response->SerializeToString(&response_str))
    {

        conn->send(response_str);
    }
    else
    {
        std::cout << "serialize response_str error" << std::endl;
    }
    conn->shutdown();
}