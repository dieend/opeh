#ifndef time_H
#define time_H
// kelas waktu untuk menentukan waktu di world
class Time
{
public :
       Time();//ctor time
       virtual ~Time();//dtor time
       int nextMinutes(int=2);//menentukan menit berikutnya(dieksekusi saat 1 gerakan dilakukan), parameter defaultnya adalah 2
       int getMinutes();
       void nextJam();
       int getJam();
       void nextSeason();//season dalam satu tahun, ada 4 season,0 untuk spring, 1 untuk summmer,2 untuk autumn, 3 untuk winter
       int getSeason();//mengembalikan nilai season sekarang
       void nextDay();
       int getDay();
       void setZero();
       void setAct(int);
private :
        int minutes;
        int jam;
        int day;
        int season;
        int act;
};

#endif
