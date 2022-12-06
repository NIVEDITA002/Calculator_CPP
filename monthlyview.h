#ifndef MONTHLYVIEW_H
#define MONTHLYVIEW_H

#include<iostream>
#include<list>

#include"event.h"

using namespace std;

class MonthlyView
{
    public:
        void switchMonth(); //monthly view of a calendar
        void selectDay(); //select a day in a month
        void createEvent(string day); //create an event for a day
        void selectEvent(string day); //select an event in a day

    protected:

    private:
        int year;
        string monthName;
        int monthDays;
        Event events;
};

#endif // MONTHLYVIEW_H
