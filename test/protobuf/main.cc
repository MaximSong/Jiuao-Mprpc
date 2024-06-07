#include "test.pb.h"
#include <iostream>
using namespace fixbug;

int main()
{
    // LoginResponse resp;
    // ResultCode *rc = resp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("fail");
    // std::string send_str;
    // if (resp.SerializeToString(&send_str))
    // {
    //     std::cout << "send_str: " << send_str.c_str() << std::endl;
    // }
    // else
    // {
    //     std::cout << "serialize to string failed" << std::endl;
    // }
    GetFriendResponse resp;
    ResultCode *rc = resp.mutable_result();
    rc->set_errcode(0);
    User *user1 = resp.add_friend_list();
    user1->set_name("zhangsan");
    user1->set_age(20);
    user1->set_sex(User::Man);
    std::cout << resp.friend_list_size() << std::endl;
    // {
    //     LoginRequest req;
    //     req.set_name("zhangsan");
    //     req.set_password("123456");
    //     std::string send_str;
    //     if (req.SerializeToString(&send_str))
    //     {
    //         std::cout << "send_str: " << send_str.c_str() << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "serialize to string failed" << std::endl;
    //     }
    //     LoginRequest reqB;
    //     if (reqB.ParseFromString(send_str))
    //     {
    //         std::cout << "name: " << reqB.name() << std::endl;
    //         std::cout << "password: " << reqB.password() << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "parse from string failed" << std::endl;
    //     }
}