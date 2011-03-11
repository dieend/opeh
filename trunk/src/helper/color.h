#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Utilities{
private:
    Utilities();
    int color;
};

inline std::ostream& dinding(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
                BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
    return s;
}

inline std::ostream& lahan_plowed(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
                BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    return s;
}
inline std::ostream& lahan_watered(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY);
    return s;
}

inline std::ostream& lahan(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, BACKGROUND_GREEN);
    return s;
}

inline std::ostream& lantai(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
              BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    return s;
}

inline std::ostream& judul(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
              BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    return s;
}

inline std::ostream& toko(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
         FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& white(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
       FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    return s;
}

inline std::ostream& blue(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
       FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    return s;
}

struct color {
    color(WORD attribute):m_color(attribute){};
    WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem,_Traits>& 
      operator<<(std::basic_ostream<_Elem,_Traits>& i, color& c)
{
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout,c.m_color);
    return i;
}

// Copyleft Vincent Godin
