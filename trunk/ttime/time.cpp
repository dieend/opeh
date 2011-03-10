#include "time.h"
#include <iostream>
using namespace std;
Time::Time() : minutes(0),jam(0),day(0),season(0),cjam(false),cday(false),cseason(false)//setting menit, jam season, dan counter menjadi 0
{
}

Time::~Time(){
}
//ASUMSI WAKTU PENTING!!!
//menentukan menit berikutnya(dieksekusi saat 1 gerakan dilakukan), parameter defaultnya adalah 2
//jadi satu gerakan menghabisakan waktu 2 menit
//rentang minutes = 0-59
//dipanggil dalam looping per aksi, jadi jika saat looping ditemui bahwa aksi tersebut tidak menggunakan satu hari,nilai cjam jadi 0
//jika 1 aksi membuat perpindahan hari, maka nilai cjam jadi 1
void Time::nextMinutes(int nm){
     if (minutes+nm<60)
     {
       minutes+=nm;
       cjam=false;
     }
     else
     {
       nextJam();
       minutes=(minutes+nm)%60;
       cjam=true;
     }
}

//mengembalikan nilai dari current minutes
int Time::getMinutes(){
    return minutes;
}

//setting nilai jam,rentang nilai jam 0-23
//cday 1 jika membuat hari berubah,0 jika tidak
void Time::nextJam(){
     if (jam<23)
     {
       ++jam;
       cday=false;
     }
     else
     {
       nextDay();
       jam=0;
       cday=true;
     }       
}

//mengembalikan nilai dari current jam
int Time::getJam(){
    return jam;
}

//setting day, 30 day merupakan 1 musim, rentang day dari 1-30
//cseason 1 jika membuat season berubah, 0 jika tidak
void Time::nextDay(){
     if (day<30)
     {
       ++day;
       cseason=false;
     }
     else
     {
       nextSeason();
       day=1;
       cseason=true;
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
     cjam=cday=cseason=0;
}

bool Time::iscDay()
{
     return cday;
}

bool Time::iscJam()
{
     return cjam;
}

bool Time::iscSeason()
{
     return cseason;
}
