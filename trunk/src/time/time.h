#ifndef time_H
#define time_H

class Time
{
public :
       Time();
       virtual ~Time();
       void next10Minutes();
       int getMinutes();
       void nextJam();
       int getJam();
       void nextSeason();
       int getSeason();
       void nextDay();
       int getDay();
       void setZero();
       void setAct();
private :
        int minutes;
        int jam;
        int day;
        int season;
        int act;
};

#endif
