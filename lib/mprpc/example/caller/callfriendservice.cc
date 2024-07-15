#include <iostream>
#include "mprpcapplication.h"
#include "friend.pb.h"

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    // 调用远程Login服务
    fixbug::FriendServiceRpc_Stub stub(new MprpcChannel());
    // rpc方法的请求参数
    fixbug::GetFriendsListRequest request;
    fixbug::GetFriendsListResponse response;
    request.set_id(1000);
    MprpcController controller;
    stub.GetFriendsList(&controller, &request, &response, nullptr);
    if (controller.Failed())
    {
        std::cout << "rpc getfriendlist response error:" << controller.ErrorText() << std::endl;
    }
    else
    {
        if (response.result().errcode() == 0)
        {
            std::cout << "rpc getfriendlist response success:" << std::endl;
            int size = response.friends_size();
            for (int i = 0; i < size; i++)
            {
                std::cout << response.friends(i) << std::endl;
            }
        }
        else
        {
            std::cout << "rpc getfriendlist response error:" << response.result().errmsg() << std::endl;
        }
    }

    return 0;
}