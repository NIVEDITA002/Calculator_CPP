#include"dailyview.h"
#include"event.h"
#include<iostream>
#include<stdio.h>
#include<sstream>
#include<fstream>
#include<windows.h>

using namespace std;

void DailyView::switchDay()
{
    cout << "\n\tDAILY VIEW" << endl;
    cout << "\nEnter the year : ";
    cin >> year;
    cout << "\nEnter the month : ";
    fflush(stdin);
    getline(cin , monthName);
    cout << "\nEnter the day : ";
    cin >> day;
    string d = "Event date : ";
    stringstream dy;
    dy << day;
    string sday;
    dy >> sday;
    d = d + sday;
    string mon;
    if(monthName == "January")
    {
        mon = "/01/";
    }
    else if(monthName == "February")
    {
        mon = "/02/";
    }

    else if(monthName == "March")
    {
        mon = "/03/";
    }

    else if(monthName == "April")
    {
        mon = "/04/";
    }

    else if(monthName == "May")
    {
        mon = "/05/";
    }

    else if(monthName == "June")
    {
        mon = "/06/";
    }

    else if(monthName == "July")
    {
        mon = "/07/";
    }

    else if(monthName == "August")
    {
        mon = "/08/";
    }

    else if(monthName == "September")
    {
        mon = "/09/";
    }

    else if(monthName == "October")
    {
        mon = "/10/";
    }

    else if(monthName == "November")
    {
        mon = "/11/";
    }
    else
    {
        mon = "/12/";
    }
    d = d + mon;
    stringstream yr;
    yr << year;
    string ab;
    yr >> ab;
    d = d + ab;
    fstream f;
    f.open("Events.txt" , ios::in);
    char s[100];
    char s2[100];
    int flag = 0;
    while(!f.eof())
    {
        f.getline(s , 100 , '\n');
        if(s[6] == 'n')
        {
            f.getline(s2 , 100 , '\n');
            if(s2 == d)
            {
                flag += 1;
                cout << s << endl;
                cout << "\n";
            }
        }
    }
    f.close();
    if(flag == 0)
    {
        cout << "\nThere is no event in this day" << endl;
    }
    char choice;
    cout << "\nDo you want to create an event in this day?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
        createEvent(d);
    cout << "\nDo you want to select an event in this day?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
        selectEvent(d);
    cout << "\n\n\n\n\n\n\n";
    system("pause");
    system("CLS");
}

void DailyView::createEvent(string d)
{
    events.addEvent(1 , d);
}

void DailyView::selectEvent(string day)
{
    string name = "Event name : ";
    string n;
    cout << "\nEnter the event name you want to display : ";
    fflush(stdin);
    getline(cin , n);
    name = name + n;
    fstream f;
    f.open("Events.txt" , ios::in);
    char s[100];
    char s2[100];
    cout << "\n";
    int flag = 0;
    while(!f.eof())
    {
        f.getline(s , 100 , '\n');
        if(s == name)
        {
            f.getline(s2 , 100 , '\n');
            if(s2 == day)
            {
                flag += 1;
                cout << s << endl;
                cout << s2 << endl;
                for(int i = 0 ;i < 6 ; i++)
                {
                    f.getline(s2 , 100 , '\n');
                    cout << s2 << endl;
                }
            }
        }
    }
    if(flag == 0)
        cout << "\nThere is no event in this day" << endl;
    f.close();
}
