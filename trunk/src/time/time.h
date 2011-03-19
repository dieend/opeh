#ifndef time_H
#define time_H
// kelas waktu untuk menentukan waktu di world
class Time
{
public :
       Time();//ctor time
       virtual ~Time();//dtor time
       void next10Minutes(int);
       void nextMinutes();//menenentukan menit berikutnya, menambah 10 ke menit, dan mengecek apapak mempengaruhi jam,day,season
       int getMinutes();
       void nextJam();
       int getJam();
       void nextDay();
       int getDay();
       void nextSeason();//season dalam satu tahun, ada 4 season,0 untuk spring, 1 untuk summmer,2 untuk autumn, 3 untuk winter
       int getSeason();//mengembalikan nilai season sekarang
       void setZero();
       bool iscJam();//true jika jam baru berubah(setelah 1 aksi), false jika tidak
       bool iscDay();//true jika day baru berubah(setelah 1 aksi), false jika tidak
       bool iscSeason();//true jika season baru berubah(setelah 1 aksi), false jika tidak
       void setAct(int);
       void performtime();
	   int getSTime();
private :
        int minutes;
        int jam;
        int day;
        int season;
        bool cjam;
        bool cday;
        bool cseason;
        int act;
        int stime;//status waktu current, tergantung si player, awalnya 0/normal
};

#endif
