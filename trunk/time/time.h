#ifndef time_H
#define time_H

class time
{
public :
       time();
       virtual ~time();
       void next10minutes();
       int getminutes();
       void nextjam();
       int getjam();
       void nextseason();
       int getseason();
       void nextday();
       int getday();
       void setzero();
       void setact();
private :
        int minutes;
        int jam;
        int day;
        int season;
        int act;
};

#endif