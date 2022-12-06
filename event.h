#ifndef EVENT_H
#define EVENT_H

#include<iostream>
#include"eventcategory.h"

using namespace std;

class Event
{
    public:

        Event();
        ~Event();
        void addEvent(int flag = 0 , string d = ""); //add an event for a day
        void editEvent(); // edit an existing event
        void deleteEvent(); //delete an existing event
        void addAlert(); //add alert to the event
        void createCategory(); //add category to the event
        void share(); //share an event to a user
        void setRepitition(); //set repitition for an event

    protected:

    private:
        string name;
        string date;
        string startTime;
        string endTime;
        string description;
        EventCategory *category;
        bool shareable;
};

#endif // EVENT_H
