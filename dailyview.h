#ifndef DAILYVIEW_H
#define DAILYVIEW_H

#include<iostream>
#include<list>

#include"event.h"

using namespace std;

class DailyView
{
    public:
        void switchDay(); //day view of a calendar
        void createEvent(string d); //create an event for a day
        void selectEvent(string day); //select an event in a day

    protected:

    private:
        int year;
        string monthName;
        int day;
        Event events;
};

#endif // DAILYVIEW_H
