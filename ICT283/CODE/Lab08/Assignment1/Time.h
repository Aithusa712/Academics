#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
using namespace std;

/**
 * \file Time.h
 * \brief Header file for the Date class.
 */

/**
 * \class Time
 * \brief Date class contains the time
 */
class Time
{
public:
    /**
    * \brief Constructor for Date. Initializes m_time as an empty string.
    */
    Time();
    /**
    * \brief Destructor for the Time class
    */
    ~Time();
    /**
    * \brief Sets the time by taking in two paramaters
    * \param hours the hour
    * \param minutes the minutes
    */
    void SetTime(string hours, string minutes);

    /**
    * \brief Gets the time stored in m_time.
    */
    string GetTime() const;

private:
    string m_time;  /**< Contains the time in hh:mm format */


};


#endif // RESULT_H
