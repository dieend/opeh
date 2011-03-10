#ifndef time_H
#define time_H
// kelas waktu untuk menentukan waktu di world
class Time
{
public :
       Time();//ctor time
       virtual ~Time();//dtor time
       void nextMinutes(int=2);//menentukan menit berikutnya(dieksekusi saat 1 gerakan dilakukan), parameter defaultnya adalah 2
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
private :
        int minutes;
        int jam;
        int day;
        int season;
        bool cjam;
        bool cday;
        bool cseason;
};

#endif
