#include "time.h"
#include <iostream>
using namespace std;
Time::Time() : minutes(0),jam(0),season(0),act(0)//setting menit, jam season, dan counter menjadi 0
{
}

Time::~Time(){
}
//ASUMSI WAKTU PENTING!!!
//menentukan menit berikutnya(dieksekusi saat 1 gerakan dilakukan), parameter defaultnya adalah 2
//jadi satu gerakan menghabisakan waktu 2 menit
//rentang minutes = 0-59
//dipanggil dalam looping per aksi, jadi jika saat looping ditemui bahwa aksi tersebut tidak menggunakan satu hari,return value 0
//jika 1 aksi membuat perpindahan hari, maka return value 1, dengan nilai waktu yaitu menit 0 ditambah sisa waktu
int Time::nextMinutes(int nm){
     if (minutes+nm<60)
     {
       minutes+=nm;
       return 0;
     }
     else
     {
       nextJam();
       minutes=(minutes+nm)%60;
       return 1;
     }
}

//mengembalikan nilai dari current minutes
int Time::getMinutes(){
    return minutes;
}

//setting nilai jam,rentang nilai jam 0-23
void Time::nextJam(){
     if (jam<23)
       ++jam;
     else
     {
       nextDay();
       jam=0;
     }       
}

//mengembalikan nilai dari current jam
int Time::getJam(){
    return jam;
}

//setting day, 30 day merupakan 1 musim, rentang day dari 1-30
void Time::nextDay(){
    if (day<30){
        ++day;
    } else {
        nextSeason();
        day=1;
    }
}

//mengembalikan nilai dari current day
int Time::getDay(){
    return day;
}

//season dalam satu tahun, ada 3,rentangnya 1-3
void Time::nextSeason(){
     season=(season%3)+1;
}

//mengembalikan nilai season sekarang
int Time::getSeason(){
    return season;
}


void Time::setZero(){
     minutes=0;
     jam=0;
     day=0;
     season=0;
     act=0;
}

void Time::setAct(int na){
     act=na;
}
