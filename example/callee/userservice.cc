#include <iostream>
#include <string>
#include "../user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
/*
UserService provides local service, offering two functions: Login and GetFriend.
*/
class UserService : public fixbug::UserServiceRpc // on the callee side
{
public:
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "doing local service: Login" << std::endl;
        std::cout << "name: " << name << std::endl;
        return true;
    }
    // rewrite the virtual function to implement the service
    void Login(::google::protobuf::RpcController *controller,
               const ::fixbug::LoginRequest *request,
               ::fixbug::LoginResponse *response,
               ::google::protobuf::Closure *done)
    {
        // 框架给业务上报了请求参数，业务只需要实现业务逻辑即可
        std::string name = request->username();
        std::string pwd = request->password();
        bool login_result = Login(name, pwd);
        // 框架给业务返回响应
        fixbug::ResultCode *rc = response->mutable_result();
        rc->set_errcode(0);
        rc->set_errmsg("");
        response->set_success(login_result);
        done->Run();
    }
};
int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    // 把UserService对象发布到RpcProvider
    RpcProvider provider;
    provider.NotifyService(new UserService());
    provider.Run();
    return 0;
}