
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
using namespace std;
class Time
{
    public:
        Time();
        ~Time();

        void SetTime(int hours, int minutes);
        string GetTime() const;

    private:
        string m_time;


};

ostream & operator <<( ostream & os, const Time & time);
istream & operator >>( istream & input, Time & time);

#endif // RESULT_H
