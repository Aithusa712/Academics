#include "Date.h"

Date::Date()
{

   m_date ="";
}
Date::~Date() {}

void Date::SetDate(int day, int month, int year)
{
    string Sday = "";
    string Syear = "";
    string Sdate = "";
    string Smonth = "";
    Sday = to_string(day);
    Syear = to_string(year);

    switch(month)
    {
    case 1:
        Smonth = "January";
        break;
    case 2:
        Smonth = "February";
        break;
    case 3:
        Smonth = "March";
        break;
    case 4:
        Smonth = "April";
        break;
    case 5:
        Smonth = "May";
        break;
    case 6:
        Smonth = "June";
        break;
    case 7:
        Smonth = "July";
        break;
    case 8:
        Smonth = "August";
        break;
    case 9:
        Smonth = "September";
        break;
    case 10:
        Smonth = "October";
        break;
    case 11:
        Smonth = "November";
        break;
    case 12:
        Smonth = "December";
        break;
    default:
        Smonth = "N/A";
    }

    m_date = Sday + " " + Smonth + " " + Syear;
}
string Date::GetDate() const
{
    return m_date;
}

istream & operator >>( istream & input, Date & date)
{
    string sdate;

    input >> date;
    string sDay = sdate.substr(0, 2);
    string sMonth = sdate.substr(3, 2);
    string sYear = sdate.substr(6, 4);
    int nDay = stoi(sDay);
    int nMonth = stoi(sMonth);
    int nYear  =stoi(sYear);
    date.SetDate(nDay, nMonth, nYear);

    return input;
}

ostream & operator <<( ostream & os, const Date & date)
{

    os << "  Date: "<< date.GetDate()  << '\n';
    return os;
}
