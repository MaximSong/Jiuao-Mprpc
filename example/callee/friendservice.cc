#include <iostream>
#include <string>
#include "../friend.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include <vector>
#include "logger.h"
class FriendService : public fixbug::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendList(uint32_t user_id)
    {
        std::cout << "do GetFriendList userid" << user_id << std::endl;
        std::vector<std::string> friend_list;
        for (int i = 0; i < 3; i++)
        {
            friend_list.push_back("zhang san" + std::to_string(i));
        }
        return friend_list;
    }
    void GetFriendsList(::google::protobuf::RpcController *controller,
                        const ::fixbug::GetFriendsListRequest *request,
                        ::fixbug::GetFriendsListResponse *response,
                        ::google::protobuf::Closure *done)
    {
        uint32_t userid = request->id();
        // std::cout << "do GetFriendsList, userid:" << userid << std::endl;
        std::vector<std::string> friends_list = GetFriendList(userid);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for (std::string &name : friends_list)
        {
            response->add_friends(name);
        }
        done->Run();
    }
};
int main(int argc, char **argv)
{
    M_RPC_LOG_INFO("first log message!");
    M_RPC_LOG_ERR("%s:%s:%d", __FILE__, __FUNCTION__, __LINE__);
    MprpcApplication::Init(argc, argv);
    // 把UserService对象发布到RpcProvider
    RpcProvider provider;
    provider.NotifyService(new FriendService());
    provider.Run();
    return 0;
}