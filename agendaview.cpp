#include "agendaview.h"
#include<list>
#include"event.h"
#include<fstream>
#include<iostream>
#include<windows.h>

using namespace std;

void AgendaView::createEvent()
{
    events.addEvent();
}

void AgendaView::selectEvent()
{
    fstream f;
    f.open("Events.txt" , ios::in);
    char arr[100];
    cout << "\n";
    cout << "\n\tAGENDA VIEW" << endl;
    while(!f.eof())
    {
        f.getline(arr , 100 , '\n');
        cout << arr << endl;
    }
    f.close();
    cout << "\n\n\n\n\n\n\n";
    system("pause");
    system("CLS");
}
