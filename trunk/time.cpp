#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
}

Time::~Time()
{
}

//next10minutes adalah public method, setting waktu untuk maju 10 minutes kemudian
void Time::next10minutes()
{
  minutes=(minutes+10)%60;
}

//mengembalikan nilai minutes dari current Time
int Time::getminutes()
{
    return minutes;
}

//setting nilai jam ke jam berikutnya
void Time::nextjam()
{
  jam=(jam+1)%24;
}

//mengembalikan nilai jam dari current Time
int Time::getjam()
{
    return jam;
}

//setting season ke season berikutnya
void Time::nextseason()
{
  season=(season+1)%3;
}

//mengembalikan nilai season dari current Time
int Time::getseason()
{
    return season;
}

//setting day ke nilaiberikutnya
void Time::nextday()
{
  day=(day+1)%365;
}

//mengembalikan nilai hari dari current Time
int Time::getday()
{
    return day;
}

//setting semua nilai/private dari Time(exclude act) menjadi 0(hwaktu pertama kali mulai)
void Time::setzero()
{
     minutes=0;
     jam=0;
     day=0;
     season=0;
}

//setting banyak aksi yang bisa dilakukan per 10 minutes
void Time::setact(int na)
{
     act=na;
}

//mengembalikan nilai act pada currrent Time
int Time::getact()
{
    return act;
}
