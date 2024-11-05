
#include "Time.h"

Time::Time()
{

    m_time ="";
}
Time::~Time() {}

void Time::SetTime(int hours, int minutes)
{
    string sHours = "";
    string sMin = "";

    sHours = to_string(hours);
    sMin = to_string(minutes);


    m_time = sHours + ":" + sMin;
}
string Time::GetTime() const
{
    return m_time;
}

istream & operator >>( istream & input, Time & time)
{
    string stime;
    int nHours;
    int nMin;
    input >> stime;
    string sHours = stime.substr(0, 2);
    string sMin = stime.substr(3, 2);

    nHours = stoi(sHours);
    nMin = stoi(sMin);

    time.SetTime(nHours, nMin);

    return input;
}

ostream & operator <<( ostream & os, const Time & time)
{

    os << "  Time: "<< time.GetTime() << '\n';
    return os;
}
