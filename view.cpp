#include "view.h"
#include<windows.h>
#include<iostream>

using namespace std;

void View::switchView()
{
    int choice;
    cout << "\n\tCALENDAR" << endl;
    cout << "\n\tMENU" << endl;
    cout << "\n1.Monthly view" << endl;
    cout << "\n2.Weekly view" << endl;
    cout << "\n3.Daily view" << endl;
    cout << "\n4.Agenda view" << endl;
    cout << "\nHow do you want to view the calendar?" << endl;
    cout << "Enter your choice : " << endl;
    cin >> choice;
    cout << "\n\n\n\n\n\n";
    system("pause");
    system("CLS");
    switch(choice)
    {
        case 1:
            month.switchMonth();
            break;

        case 2:
            week.switchWeek();
            break;

        case 3:
            day.switchDay();
            break;

        case 4:
            agenda.selectEvent();
            break;

        default:
            cout << "\nInvalid choice" << endl;

    }
}

void View::buildEventList()
{
    int n;
    cout << "\nEnter the number of events to be created : ";
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        agenda.createEvent();
    }
}
