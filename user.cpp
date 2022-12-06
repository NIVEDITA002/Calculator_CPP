#include "user.h"
#include<iostream>
#include<stdio.h>
#include"view.h"
#include<windows.h>

using namespace std;

User::User()
{
    cout << "\n\t\tCALENDAR" << endl;
    cout << "\n\tCREATE USER ACCOUNT" << endl;
    fflush(stdin);
    cout << "\nEnter your name : ";
    getline(cin , name);
    fflush(stdin);
    cout << "\nEnter your phone number : ";
    getline(cin , phone_number);
    fflush(stdin);
    cout << "\nEnter your e-mail id : ";
    getline(cin , e_mail);
    cout << "\n\n\n\n\n\n\n";
    system("pause");
    system("CLS");
}

void User::sendShareRequest()
{
    ShareToUsers = new User();
    fflush(stdin);
    cout << "\nEnter the name of the user : ";
    getline(cin , ShareToUsers->name);
    fflush(stdin);
    cout << "\nEnter the phone number : ";
    getline(cin , ShareToUsers->phone_number);
    fflush(stdin);
    cout << "\nEnter the mail-id of the user whom you want to send the calendar : ";
    getline(cin , ShareToUsers->e_mail);
    cout << "\nYour share request is successfully sent to " << ShareToUsers->e_mail << endl;
}

void User::replyShareRequest(User* u)
{
    char ch;
    ShareFromUsers = u;
    cout << "\nYou have received a share request from " << ShareFromUsers->e_mail << " (Name : " <<  ShareFromUsers->name << ")" << endl;
    cout << "\nEnter (A/a) for accept (or) (D/d) for decline : ";
    fflush(stdin);
    cin >> ch;
}
