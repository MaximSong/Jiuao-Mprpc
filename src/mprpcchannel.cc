#include "mprpcchannel.h"
#include "rpcheader.pb.h"
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include "mprpcapplication.h"
void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                              google::protobuf::RpcController *controller,
                              const google::protobuf::Message *request,
                              google::protobuf::Message *response,
                              google::protobuf::Closure *done)
{
    const google::protobuf::ServiceDescriptor *service = method->service();
    std::string service_name = service->name();
    std::string method_name = method->name();
    std::string args_string;
    uint32_t args_size = 0;
    if (request->SerializeToString(&args_string))
    {
        args_size = args_string.size();
    }
    else
    {
        std::cout << "serialize request error" << std::endl;
        return;
    }
    mprpc::RpcHeader rpcHeader;
    rpcHeader.set_service_name(service_name);
    rpcHeader.set_method_name(method_name);
    rpcHeader.set_args_size(args_size);
    std::string rpc_header_str;
    uint32_t header_size = 0;
    if (rpcHeader.SerializeToString(&rpc_header_str))
    {
        header_size = rpc_header_str.size();
    }
    else
    {
        std::cout << "serialize rpc header error" << std::endl;
        return;
    }
    std::string send_str;
    send_str.insert(0, std::string((char *)&header_size, 4));
    send_str += rpc_header_str;
    send_str += args_string;
    // 打印调试信息
    std::cout << "service_name:" << service_name << " method_name:" << method_name << " args_string:" << args_string << std::endl;
    // 使用tcp编程，完成rpc方法的远程调用
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1)
    {
        std::cout << "create socket error" << std::endl;
        exit(0);
    }
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    if (-1 == connect(clientfd, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        std::cout << "connect error" << errno << std::endl;
        close(clientfd);
        exit(0);
    }
    if (-1 == send(clientfd, send_str.c_str(), send_str.size(), 0))
    {
        std::cout << "send data error" << errno << std::endl;
        close(clientfd);
        exit(0);
    }
    // 接收rpc调用的响应数据
    char buf[1024] = {0};
    int recv_size = 0;
    if (-1 == (recv_size = recv(clientfd, buf, 1024, 0)))
    {
        std::cout << "recv data error" << errno << std::endl;
        close(clientfd);
        exit(0);
    }
    // std::string response_str(buf, 0, recv_size); //bug出现问题, recv_buf中遇到\0就会停止
    if (response->ParseFromArray(buf, recv_size) == 0)
    {
        std::cout << "rpc response parse error" << buf << std::endl;
        close(clientfd);
        exit(0);
    }
    close(clientfd);
}