#include<iostream>
#include"view.h"
#include"user.h"
#include"event.h"
#include<fstream>
#include"monthlyview.h"
#include<windows.h>
#include<conio.h>

using namespace std;

int main()
{
    cout << "\n\n\n\n\n\n";
    cout << "              ----------------------------------------" << endl;
    cout << "                            CALENDAR            \n";
    cout << "              ----------------------------------------" << endl;
    cout << "                                                    \n";
    cout << "                  Project by ,                      \n";
    cout << "                                                    \n";
    cout << "                        CHARAN K M (20PC11)         \n";
    cout << "                                                    \n";
    cout << "                        NIVEDITA S (20PC25)         \n";
    cout << "                                                    \n";
    cout << "                        REZIN ABDURAHIMAN (20PC28)  \n";
    cout << "                                                    \n";
    cout << "                        YOGITHA A (20PC40)          \n";
    cout << "\n\n              ----------------------------------------" << endl;
    cout << "\n\n\n\n\n\n\n";
    system("pause");
    system("CLS");
    User u1;
    View v1;
    v1.switchView();
    Event e1;
    char ch;
    cout << "\nDo you want to add an event?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        cout << "\n\tADD EVENT" << endl;
        e1.addEvent();
        cout << "\n\n\n\n\n\n\n";
        system("pause");
        system("CLS");
    }
    cout << "\nDo you want to edit an event?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        cout << "\n\tEDIT EVENT" << endl;
        e1.editEvent();
        cout << "\n\n\n\n\n\n\n";
        system("pause");
        system("CLS");
    }
    cout << "\nDo you want to delete an event?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        cout << "\n\tDELETE EVENT" << endl;
        e1.deleteEvent();
        cout << "\n\n\n\n\n\n\n";
        system("pause");
        system("CLS");
    }
    cout << "\nDo you want to share an event?\nEnter (Y/y) for yes or (N/n) for no : ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        cout << "\n\tSHARE EVENT" << endl;
        e1.share();
        cout << "\n\n\n\n\n\n\n";
        system("pause");
        system("CLS");
    }
    cout << "\nDo you want to see monthly view calendar?\nEnter (Y/y) for yes or (N/n) for no :  ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        MonthlyView m1;
        m1.switchMonth();
    }
    cout << "\nDo you want to see weekly view calendar?\nEnter (Y/y) for yes or (N/n) for no :  ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        WeeklyView w1;
        w1.switchWeek();
    }
    cout << "\nDo you want to see daily view calendar?\nEnter (Y/y) for yes or (N/n) for no :  ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        DailyView d1;
        d1.switchDay();
    }
    cout << "\nDo you want to see agenda view calendar?\nEnter (Y/y) for yes or (N/n) for no :  ";
    fflush(stdin);
    cin >> ch;
    if(ch == 'Y' || ch == 'y')
    {
        AgendaView a1;
        a1.selectEvent();
    }
}

