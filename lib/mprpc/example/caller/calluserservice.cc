#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"
int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    // 调用远程Login服务
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    // rpc方法的请求参数
    fixbug::LoginRequest request;
    fixbug::LoginResponse response;
    request.set_username("zhang san");
    request.set_password("123456");
    stub.Login(nullptr, &request, &response, nullptr);
    if (response.result().errcode() == 0)
    {
        std::cout << "rpc login response success:" << response.success() << std::endl;
    }
    else
    {
        std::cout << "rpc login response error:" << response.result().errmsg() << std::endl;
    }
    // 调用远程Register服务
    fixbug::RegisterRequest req;
    fixbug::RegisterResponse rsp;
    req.set_id(2000);
    req.set_username("mprpc");
    req.set_password("123456");
    stub.Register(nullptr, &req, &rsp, nullptr);
    if (rsp.result().errcode() == 0)
    {
        std::cout << "rpc register response success:" << rsp.success() << std::endl;
    }
    else
    {
        std::cout << "rpc register response error:" << rsp.result().errmsg() << std::endl;
    }
    return 0;
}