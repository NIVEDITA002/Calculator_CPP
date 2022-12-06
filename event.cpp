#include "event.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<iostream>

using namespace std;

Event::Event()
{
    category = new EventCategory();
}

Event::~Event()
{
    delete category;
}

void Event::addEvent(int flag, string d)
{
    fstream f;
    f.open("Events.txt" , ios::app);
    char ch;
    if(flag == 0)
    {
        fflush(stdin);
        cout << "\nEnter the event name : ";
        getline(cin , name);
        f << "\nEvent name : " << name;
        fflush(stdin);
        cout << "\nEnter the event date in (dd/mm/yyyy) format : ";
        getline(cin , date);
        f << "\nEvent date : " << date;
    }
    else
    {
        fflush(stdin);
        cout << "\nEnter the event name : ";
        getline(cin , name);
        f << "\nEvent name : " << name;
        date = d;
        f << "\n" << date;
    }
    cout << "\nEnter the start time of the event in (hh:mm:ss) format (24 hour format) : ";
    fflush(stdin);
    getline(cin , startTime);
    f << "\nStart time : " << startTime;
    cout << "\nEnter the end time of the event in (hh:mm:ss) format (24 hour format) : ";
    getline(cin , endTime);
    f << "\nEnd time : " << endTime;
    fflush(stdin);
    cout << "\nEnter a short description about the event : ";
    getline(cin , description);
    f << "\nDescription : " << description;
    f.close();
    createCategory();
    f.open("Events.txt" , ios::app);
    cout << "Do you like to share the event to other users?";
    cout << "\nEnter (Y / y) for yes or (N / n) for no : ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        shareable = true;
        f << "\nShareable : True";
    }
    else
    {
        shareable = false;
        f << "\nShareable : False";
    }
    f.close();
    setRepitition();
    addAlert();
}

void Event::editEvent()
{
    string editName = "Event name : ";
    string editDate = "Event date : ";
    string temp;
    fflush(stdin);
    cout << "\nEnter the name of the event to be edited : ";
    getline(cin , temp);
    editName = editName + temp;
    fflush(stdin);
    cout << "\nEnter the date of the event to be edited in (dd/mm/yyyy) format : ";
    getline(cin , temp);
    editDate = editDate + temp;
    fstream f;
    f.open("Events.txt" , ios::out|ios::in);
    char t[100];
    f.seekg(0,ios::beg);
    char temp1[100];
    while(!f.eof())
    {
        f.getline(t , 100 , '\n');
        if(t == editName)
        {
            f.getline(temp1 , 100 , '\n');
            if(temp1 == editDate)
            {
                f.seekp(-6 , ios::cur);
                cout << "\nEdit the start time of the event in (hh:mm:ss) format (24 hour format) : ";
                getline(cin , startTime);
                f << "Start time : " << startTime;
                cout << "\nEdit the end time of the event in (hh:mm:ss) format (24 hour format) : ";
                getline(cin , endTime);
                f << "\nEnd time : " << endTime;
                fflush(stdin);
                cout << "\nEdit a short description about the event : ";
                getline(cin , description);
                f << "\nDescription : " << description;
                f.close();
                category->edit();
                char ch;
                cout << "Do you like to share the event to other users?";
                cout << "\nEnter (Y / y) for yes or (N / n) for no : ";
                fflush(stdin);
                cin >> ch;
                if(ch == 'Y' || ch == 'y')
                {
                    shareable = true;
                    f << "\nShareable : True";
                }
                else
                {
                    shareable = false;
                    f << "\nShareable : False";
                }
                return;
            }
        }
    }
    cout << "\nNo such event exists" << endl;
    f.close();
}

void Event::deleteEvent()
{
    string dName = "Event name : ";
    string dDate = "Event date : ";
    string temp;
    fflush(stdin);
    cout << "\nEnter the name of the event to be deleted : ";
    getline(cin , temp);
    dName = dName + temp;
    fflush(stdin);
    cout << "\nEnter the date of the event to be deleted in (dd/mm/yyyy) format : ";
    getline(cin , temp);
    dDate = dDate + temp;
    fstream tempFile;
    tempFile.open("TempF.txt" , ios::out);
    fstream f;
    f.open("Events.txt" , ios::in);
    char t[100];
    char h[100];
    int flag = 0;
    while(!f.eof())
    {
        f.getline(t , 100 , '\n');
        if(t != dName)
        {
            tempFile << "\n" << t;
        }
        else
        {
            f.getline(h , 100 , '\n');
            if(h != dDate)
            {
                tempFile << "\n" << t;
                tempFile << "\n" << h;
            }
            else
            {
                flag = 1;
                for(int i = 0 ; i < 6 ; i++)
                {
                    f.getline(t , 100 , '\n');
                }
            }
        }
    }
    if(flag == 0)
        cout << "\nThere is no such event" << endl;
    f.close();
    tempFile.close();
    remove("Events.txt");
    rename("TempF.txt" , "Events.txt");
}

void Event::createCategory()
{
    category->add();
}

void Event::addAlert()
{
    int choice;
    cout << "\n\tALERT" << endl;
    cout << "\n1.At time of event" << endl;
    cout << "\n2.30 minutes before" << endl;
    cout << "\n3.1 hour before" << endl;
    cout << "\n4.1 day before" << endl;
    cout << "\n5.1 week before" << endl;
    cout << "\n6.None" << endl;
    cout << "\nEnter your choice : ";
    cin >> choice;
}

void Event::setRepitition()
{
    int choice;
    cout<<"\n\tREPEAT\n\n1. Every Day \n\n2. Every Week \n\n3.Every Month \n\n4. Every Year \n\n5. None";
    cout << "\n\nEnter your choice : ";
    cin>>choice;
}

void Event::share()
{
    string sName = "Event name : ";
    string sDate = "Event date : ";
    string temp;
    fflush(stdin);
    cout << "\nEnter the name of the event to be shared : ";
    getline(cin , temp);
    sName = sName + temp;
    fflush(stdin);
    cout << "\nEnter the date of the event to be shared in (dd/mm/yyyy) format : ";
    getline(cin , temp);
    sDate = sDate + temp;
    fstream f;
    f.open("Events.txt" , ios::out|ios::in);
    char t[100];
    f.seekg(0,ios::beg);
    char temp1[100];
    char temp2[100];
    string temp3 = "Shareable : True";
    int flag = 0;
    while(!f.eof())
    {
        f.getline(t , 100 , '\n');
        if(t == sName)
        {
            f.getline(temp1 , 100 , '\n');
            if(temp1 == sDate)
            {
                for(int i = 0 ; i < 5 ; i++)
                {
                    f.getline(temp2 , 100 , '\n');
                }
                f.getline(temp2 , 100 , '\n');
                if(temp2 == temp3)
                {
                    flag = 1;
                    string s;
                    cout << "\nEnter the email id of the person to share : ";
                    fflush(stdin);
                    getline(cin , s);
                    cout << "\nThe event is shared" << endl;
                }
                else
                {
                    cout << "\nThe event cannot be shared" << endl;
                }
            }
        }
    }
    if(flag == 0)
        cout << "\nThere is no such event" << endl;
    f.close();
}
