#ifndef WEEKLYVIEW_H
#define WEEKLYVIEW_H
#include<iostream>
#include"event.h"

using namespace std;

class WeeklyView
{
    public:
        void switchWeek(); //weekly view of calendar
        void selectDay(); //select a day in a week
        void createEvent(string date); //create an event for a day of a week
        void selectEvent(string day); //select an event in a day

    protected:

    private:
        int year;
        string monthName;
        int monthDays;
        int startDay;
        Event events;
};

#endif // WEEKLYVIEW_H
