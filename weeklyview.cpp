#include "weeklyview.h"
#include<iostream>
#include<stdio.h>
#include<sstream>
#include<fstream>
#include<windows.h>

using namespace std;

void WeeklyView::switchWeek()
{
    bool is_leap;
    cout << "\n\tWEEKLY VIEW" << endl;
    cout << "\nEnter the year : ";
    cin >> year;
    cout << "\nEnter the month name : ";
    fflush(stdin);
    getline(cin , monthName);
    int key_value;
    if(monthName == "January")
    {
        monthDays = 31;
        key_value = 1;
    }
    else if(monthName == "February")
    {
        key_value = 4;
        if(year % 4 == 0)
        {
            if(year % 100 == 0)
            {
                if(year % 400 == 0)
                {
                    is_leap = true;
                    monthDays = 29;
                }
                else
                {
                    is_leap = false;
                    monthDays = 28;
                }
            }
            else
            {
                is_leap = true;
                monthDays = 29;
            }
        }
        else
        {
            is_leap = false;
            monthDays = 28;
        }
    }
    else if(monthName == "March")
    {
        monthDays = 31;
        key_value = 4;
    }
    else if(monthName == "April")
    {
        monthDays = 30;
        key_value = 0;
    }
    else if(monthName == "May")
    {
        monthDays = 31;
        key_value = 2;
    }
    else if(monthName == "June")
    {
        monthDays = 30;
        key_value = 5;
    }
    else if(monthName == "July")
    {
        monthDays = 31;
        key_value = 0;
    }
    else if(monthName == "August")
    {
        monthDays = 31;
        key_value = 3;
    }
    else if(monthName == "September")
    {
        monthDays = 30;
        key_value = 6;
    }
    else if(monthName == "October")
    {
        monthDays = 31;
        key_value = 1;
    }
    else if(monthName == "November")
    {
        monthDays = 30;
        key_value = 4;
    }
    else if(monthName == "December")
    {
        monthDays = 31;
        key_value = 6;
    }
    cout << "\nEnter the start day : ";
    cin >> startDay;
    int Gregorian_factor;
    int start_day;
    start_day = ((year % 100) / 4) + startDay + key_value + ((is_leap && (monthName == "January" || monthName == "February")) ? -1 : 0);
    Gregorian_factor = year / 100;
    if(Gregorian_factor == 19)
    {
        Gregorian_factor = 0;
    }
    else if(Gregorian_factor == 20)
    {
        Gregorian_factor = 6;
    }
    else if(Gregorian_factor == 17)
    {
        Gregorian_factor = 4;
    }
    else if(Gregorian_factor == 18)
    {
        Gregorian_factor = 2;
    }
    else
    {
        Gregorian_factor = 2*400;
    }
    start_day = start_day + Gregorian_factor + (year % 100);
    start_day = start_day % 7;
    if(start_day == 0)
    {
        start_day = 7;
    }
    cout << "\n\tYear : " << year << endl;
    cout << "\n\tMonth : " << monthName << endl;
    if(start_day == 0)
    {
        start_day = 7;
    }
    if(start_day == 1)
    {
        cout << "\n\tSun\tMon\tTues\tWed\tThu\tFri\tSat" << endl;
    }
    else if(start_day == 2)
    {
        cout << "\n\tMon\tTues\tWed\tThu\tFri\tSat\tSun" << endl;
    }
    else if(start_day == 3)
    {
        cout << "\n\tTues\tWed\tThu\tFri\tSat\tSun\tMon" << endl;
    }
    else if(start_day == 4)
    {
        cout << "\n\tWed\tThu\tFri\tSat\tSun\tMon\tTues" << endl;
    }
    else if(start_day == 5)
    {
        cout << "\n\tThu\tFri\tSat\tSun\tMon\tTues\tWed" << endl;
    }
    else if(start_day == 6)
    {
        cout << "\n\tFri\tSat\tSun\tMon\tTues\tWed\tThu" << endl;
    }
    else
    {
        cout << "\n\tSat\tSun\tMon\tTues\tWed\tThu\tFri" << endl;
    }
    cout << "\n\n\t";
    for(int c = startDay ; c <= (startDay + 7 - 1)  ; c++)
    {
        if(c%monthDays != 0)
            cout << c <<"\t";
        else
            break;
    }
    cout << "\n";
    string d;
    int flag = 0;
    for(int c = startDay ; c <= (startDay + 7 - 1) && c%monthDays != 0 ; c++)
    {
        d = "Event date : ";
        stringstream dy;
        dy << c;
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
        while(!f.eof())
        {
            f.getline(s , 100 , '\n');
            if(s[6] == 'n')
            {
                f.getline(s2 , 100 , '\n');
                if(s2 == d)
                {
                    flag += 1;
                    cout << "\n" << s2 << endl;
                    cout << "\n" << s << endl;
                    for(int i = 0 ; i < 2 ; i++)
                    {
                        f.getline(s , 100 , '\n');
                        cout << "\n" << s << endl;
                    }
                }
            }
        }
        f.close();
    }
    if(flag == 0)
    {
        cout << "\nThere is no event in this week" << endl;
    }
    selectDay();
    cout << "\n\n\n\n\n\n\n";
    system("pause");
    system("CLS");
}

void WeeklyView::selectDay()
{
    string day = "Event date : ";
    string d;
    string mon;
    string a = "/";
    cout << "\nEnter the day you wish to select : ";
    fflush(stdin);
    getline(cin , d);
    day = day + d ;
    day = day + a;
    if(monthName == "January")
    {
        mon = "01";
    }
    else if(monthName == "February")
    {
        mon = "02";
    }

    else if(monthName == "March")
    {
        mon = "03";
    }

    else if(monthName == "April")
    {
        mon = "04";
    }

    else if(monthName == "May")
    {
        mon = "05";
    }

    else if(monthName == "June")
    {
        mon = "06";
    }

    else if(monthName == "July")
    {
        mon = "07";
    }

    else if(monthName == "August")
    {
        mon = "08";
    }

    else if(monthName == "September")
    {
        mon = "09";
    }

    else if(monthName == "October")
    {
        mon = "10";
    }

    else if(monthName == "November")
    {
        mon = "11";
    }
    else
    {
        mon = "12";
    }
    day = day + mon + a;
    stringstream yr;
    yr << year;
    string ab;
    yr >> ab;
    day = day + ab;
    fstream f;
    f.open("Events.txt" , ios::in);
    char s[100];
    char s2[100];
    while(!f.eof())
    {
        f.getline(s , 100 , '\n');
        if(s[6] == 'n')
        {
            f.getline(s2 , 100 , '\n');
            if(s2 == day)
            {
                cout << s << endl;
            }
        }
    }
    f.close();
    char choice;
    cout << "\nDo you want to create an event in this day?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
        createEvent(day);
    cout << "\nDo you want to select an event in this day?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> choice;
    if(choice == 'Y' || choice == 'y')
        selectEvent(day);
}

void WeeklyView::createEvent(string date)
{
    events.addEvent(1 , date);
}

void WeeklyView::selectEvent(string day)
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
