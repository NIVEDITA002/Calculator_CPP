#ifndef USER_H
#define USER_H

#include<iostream>

using namespace std;

class User
{
    public:
        User();
        void sendShareRequest(); //send a share request to a user
        void replyShareRequest(User* u); //reply a share request from a user

    protected:

    private:
        string name;
        string phone_number;
        string e_mail;
        User* ShareToUsers;
        User* ShareFromUsers;
};

#endif // USER_H
