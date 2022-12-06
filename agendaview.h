#ifndef AGENDAVIEW_H
#define AGENDAVIEW_H

#include<iostream>
#include<list>

#include"event.h"

using namespace std;

class AgendaView
{
    public:
        void createEvent(); //create a new event
        void selectEvent(); //display agenda view

    protected:

    private:
        Event events;
};

#endif // AGENDAVIEW_H
