#pragma once
#include "google/protobuf/service.h"
#include <memory>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/base/Logging.h>
#include <string>
#include <functional>
#include <unordered_map>
#include <google/protobuf/descriptor.h>
// 框架中提供专门服务rpc发布的服务的网络对象类
class RpcProvider
{
public:
    // 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    void NotifyService(google::protobuf::Service *service);
    // 启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();

private:
    muduo::net::EventLoop m_eventLoop;                                                                            // 每个rpc网络服务提供者对象都有一个EvenLoop事件循环对象
    void OnConnection(const muduo::net::TcpConnectionPtr &conn);                                                  // 新的socket连接回调
    void OnMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp); // 读写事件回调
    struct ServiceInfo
    {
        google::protobuf::Service *m_service;                                                    // 服务对象
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> m_methodMap; // 方法对象
    };
    std::unordered_map<std::string, ServiceInfo> m_serviceMap; // 存储注册成功的服务对象及其服务方法的所有信息
    // closure回调操作,用于序列化rpc的响应和网络发送
    void sendRpcResponse(const muduo::net::TcpConnectionPtr &conn, google::protobuf::Message *response);
};