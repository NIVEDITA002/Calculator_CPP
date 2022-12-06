#ifndef VIEW_H
#define VIEW_H

#include"monthlyview.h"
#include"weeklyview.h"
#include"dailyview.h"
#include"agendaview.h"


class View
{
    public:
        void switchView();
        void buildEventList();

    protected:

    private:
        MonthlyView month;
        WeeklyView week;
        DailyView day;
        AgendaView agenda;

};

#endif // VIEW_H
