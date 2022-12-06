#include "eventcategory.h"
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void EventCategory::add()
{
    fstream f;
    f.open("Events.txt" , ios::app);
    cout << "\nEnter the event category name (work / home) : ";
    fflush(stdin);
    getline(cin , name);
    f << "\nEvent category name : " << name ;
    if(name == "work")
        f << "\nColor : 5";
    else
        f << "\nColor : 1";
    f.close();
}


void EventCategory::edit()
{
    fstream f;
    f.open("Events.txt" , ios::ate);
    fflush(stdin);
    cout << "\nEdit the event category name(work/home) : ";
    getline(cin , name);
    f << "\nEvent category name : " << name;
    if(name == "work")
        f << "\nColor : 5";
    else
        f << "\nColor : 1";
    f.close();
}
