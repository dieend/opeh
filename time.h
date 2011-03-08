#ifndef time_H
#define time_H

//class Time yang digunakan di sini, berformatkan 60 minutes(0-59), tiap 10 minutes dilakukan act aksi(act adalah integer,private dari kelas Time)
//24 jam(0-23)
//365 day(0-364)
//3 season(0-2), bisa diganti sesuai kebutuhan
class Time
{
public :
       Time();
       virtual ~Time();
       void next10minutes();
       int getminutes();
       void nextjam();
       int getjam();
       void nextseason();
       int getseason();
       void nextday();
       int getday();
       void setzero();
       void setact(int=6);
       int getact();
private :
        int minutes;
        int jam;
        int day;
        int season;
        int act;
};

#endif
