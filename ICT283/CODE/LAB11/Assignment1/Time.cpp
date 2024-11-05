/*
 * Time.cpp
 * This file contains the functions of the Time Class
 */

#include "Time.h"
/*
 * Constructor for Date. Initializes m_time as an empty string.
 */
Time::Time()
{

    m_time ="";
}

/*
 * Destructor for the Time class
 */
Time::~Time() {}

/*
 * Sets the time by taking in two paramaters
 * hours the hour
 * minutes the minutes
 */
void Time::SetTime(string hours, string minutes)
{
    string temp = "";
    m_time = hours + ":" + minutes;
    temp = hours + minutes;
    m_timeInt = stoi(temp);
}
/*
 * Gets the time stored in m_time.
 */
string Time::GetTime() const
{
    return m_time;
}


bool Time::operator<(const Time& other) const {
    return m_timeInt < other.m_timeInt;
}

bool Time::operator>(const Time& other) const {
    return m_timeInt > other.m_timeInt;
}

bool Time::operator==(const Time& other) const {
    return m_timeInt == other.m_timeInt;
}
