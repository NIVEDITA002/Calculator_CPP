#ifndef EVENTCATEGORY_H
#define EVENTCATEGORY_H

#include<iostream>

using namespace std;


class EventCategory
{
    public:
        void add(); //add event category to an event
        void edit(); //edit event category of an event

    private:
        string name;
        int color;

};

#endif // EVENTCATEGORY_H
