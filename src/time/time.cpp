#include "time.h"
#include <iostream>
#include <windows.h>
#define NORMAL 0
#define PARALYZED 1
#define POISONED 2
#define FULLPOWER 3
#define SICK 4

using namespace std;
Time::Time() : minutes(0),jam(6),day(1),season(0),cjam(false),cday(false),cseason(false),act(0),stime(0)//setting menit, jam season, dan counter menjadi 0
{
}

Time::Time(ifstream& fin){
    fin.read((char*)(this),sizeof(Time));
}
Time::~Time(){
}
/*  pkoknya 10 menit 6 aksi
septu_jamasoka: 1 = paralyzed
septu_jamasoka: hilang 6 aksi
septu_jamasoka: 2 = poisoned
septu_jamasoka: bgun keesokan hari
septu_jamasoka: 3 = full power
septu_jamasoka: 10 menit 12 aksi
septu_jamasoka: 4 = sick
septu_jamasoka: 10 menit 3 aksi
septu_jamasoka: untuk 3 itu cma bertahan 1 jam
septu_jamasoka: untuk sick 9 jam trus lgsung bgun keesokan hari*/
//ASUMSI WAKTU PENTING!!!
//menentukan menit berikutnya(dieksekusi saat 1 gerakan dilakukan), parameter defaultnya adalah 2
//jadi satu gerakan menghabisakan waktu 2 menit
//rentang minutes = 0-59
//dipanggil dalam looping per aksi, jadi jika saat looping ditemui bahwa aksi tersebut tidak menggunakan satu hari,nilai cjam jadi 0
//jika 1 aksi membuat perpindahan hari, maka nilai cjam jadi 1

void Time::next10Minutes(int stp)//Fungsi ini dipanggil per aksi
{
    cday = false;
  if (stp==NORMAL)//keadaan normal//
  {
      if (act+1<=6)
        act++;
      else 
      {
        nextMinutes();
        act=1;
      }
  }
  else if (stp==PARALYZED)//paralyzed, yang mempengaruhi : normal, fullpower,sick
  {
    if (stime==NORMAL)//normal
    {
      for (int i = 1; i <= 4; i++) {
		nextJam();
	  }
    }
    else if (stime==FULLPOWER)//full power
    {
      if (act+6<=72)
      {
        if ( ((act<13) && (13<=act+6)) || ((act<25) && (25<=act+6)) || ((act<37) && (37<=act+6)) || ((act<49) && (49<=act+6)) || ((act<61) && (61<=act+6)))
        {
          nextMinutes();
        }
        act+=6;
      }        
      else 
      {
        act=(act+6)%72;
        stime=NORMAL;//setting status time jadi normal
        nextMinutes();
      }
    }
    else if (stime==SICK)//sick, mempengaruhi
    {
      if (act+6<=162)
      {
        nextMinutes();
        nextMinutes();
        act+=6;
      }
      else 
      {
        stime=NORMAL;
        act=(act+6)%162;//setting aksi
        nextDay();
      }
    }
  }
  else if (stp==POISONED)//tidak mempengaruhi stime
  {
    nextDay();
    stime=NORMAL;
    act=1;
  }
  else if (stp==FULLPOWER)//full power mempengaruhi normal,poisoned
  {
    if (stime==NORMAL)
    {
      stime=FULLPOWER;
      if (act==6)
      {
        nextMinutes();
      }
      act=1;
    }
    else if (stime==FULLPOWER)
    {
      if (act+1<=72)
      {
        act++;
        if (act%12==0)
        {
          nextMinutes();
        }
      }
      else
      {
        stime=NORMAL;
        act=1;
      }
    }
    else if (stime==SICK)
    {
      if (act+1<=162)
      {
        if (act%3==0)
        {
          nextMinutes();
          act=1;
          stime=NORMAL;
        }
      }
      else 
      {
        nextDay();
        stime=NORMAL;
        act=1;
      }
    }
  }
  else if (stp==SICK)
  {
    if (stime==NORMAL)
    {
      stime=SICK;
      if (act==6)
      {
        nextMinutes();
      }
      act=1;
    }
    else if (stime==FULLPOWER)
    {
      if (act+1<=162)
      {
        if (act%3==0)
        {
          nextMinutes();
        }
      }
      act=1;
      stime=NORMAL;
    }
    else if (stime==SICK)
    {
      if (act+1<=162)
      {
        if (act%3==0)
        {
          nextMinutes();
        }
        act++;
      }
      else
      {
        nextDay();
        act=1;
        stime=NORMAL;
      }
    }
  }       
}

//setting nilai minutes, rentang minutes 0-59
void Time::nextMinutes(){
     if (minutes+10<60)
     {
       minutes+=10;
       cjam=false;
     }
     else
     {
       nextJam();
       minutes=0;
     }
}

//mengembalikan nilai dari current minutes
int Time::getMinutes(){
    return minutes;
}

//setting nilai jam,rentang nilai jam 6-18(jam 6 pagi sampai jam 6 sore)
//cday 1 jika membuat hari berubah,0 jika tidak
void Time::nextJam(){
	 cjam=true;
     minutes=0;
     { 
       if (jam<18)
       {
         ++jam;
         cday=false;
       }
       else
       {
         nextDay();
         jam=6;
       }       
     }
}

//mengembalikan nilai dari current jam
int Time::getJam(){
    return jam;
}

//setting day, 30 day merupakan 1 musim, rentang day dari 1-30
//cseason 1 jika membuat season berubah, 0 jika tidak
void Time::nextDay(){
	 cday=true;
     minutes=0;
     jam=6;
	 
     if (day<30)
     {
       ++day;
       cseason=false;
     }
     else
     {
       nextSeason();
       day=1;
     }
	 
	 if (season == 0) {
		//PlaySound(NULL,0,0);
		Sleep(1000);
		//PlaySound("02-spring.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	} else if (season == 1) {
		//PlaySound(NULL,0,0);
		Sleep(1000);
		//PlaySound("03-summer.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	} else if (season == 2) {
//		PlaySound(NULL,0,0);
		Sleep(1000);
//		PlaySound("04-fall.wav",NULL,SND_LOOP|SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	}
}

//mengembalikan nilai dari current day
int Time::getDay(){
    return day;
}

//season dalam satu tahun, ada 3,rentangnya 1-3
void Time::nextSeason(){
    cseason=true;
     minutes=0;
     jam=6;
     day=1;
     season=(season+1)%3;
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
     cjam=cday=cseason=false;
     act=0;
     stime=0;
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

void Time::setAct(int na)
{
     act=na;
}

void Time::performtime()
{
  cout << "minutes = " << minutes << ":Jam = " << jam << ":Day = " << day << ":Season = " << season << endl;
}

int Time::getSTime() {
	return stime;
}
