/*
 *  Date.cpp
 *  This file contains the functions of the Date Class
 */

#include "Date.h"

/*
 *  Constructor for Date. Initializes m_date as an empty string.
 */
Date::Date()
{
    m_month ="";
    m_year = "";
    m_date ="";

    
}

/*
 * \brief Destructor for the Date class.
 */
Date::~Date() {}


/*
 * Sets the date by converting the int paramaters into string and storing the full date into m_date
 * day the day of the month.
 * month the month of the year expressed by numbers (1-12).
 * year the year.
 */
void Date::SetDate(string day, string month, string year)
{
    string Smonth = "N/A";
    int n_month = stoi(month);
    switch(n_month)
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

    }
    
    m_month = Smonth;
    m_year = year;
    m_date = day + " " + Smonth + " " + year;
}

/*
 * Gets the date by retrieving the string m_date
 */
string Date::GetDate() const
{
    return m_date;
}



string Date::GetMonth() const
{
    return m_month;
}

string Date::GetYear() const
{
    return m_year;
}