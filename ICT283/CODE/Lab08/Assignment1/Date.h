#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

/**
 * \file Date.h
 * \brief Header file for the Date class.
 */

/**
 * \class Date
 * \brief Date class contains the date
 */
class Date
{
public:
    /**
    * \brief Constructor for Date. Initializes m_date as an empty string.
    */
    Date();
    /**
    * \brief Destructor for the Date class.
    */
    ~Date();
    /**
    * \brief Sets the date by converting the int paramaters into string and storing the full date into m_date
    * \param day - the day of the month.
    * \param month - the month of the year expressed by numbers (1-12).
    * \param year - the year.
    */
    void SetDate(string day, string month, string year);
    /**
    * \brief Gets the date by retrieving the string m_date
    */
    string GetDate() const;
    /**
    * \brief Gets the date by retrieving the string m_month
    */
    string GetMonth() const;
    /**
    * \brief Gets the year by retrieving the string m_year
    */
    string GetYear() const;

private:
    string m_date;  /**< Date string contains the date in dd month yyyy format */
    string m_year;  /**< Year string contains the month */
    string m_month; /**< Month string contains the year */
};


#endif // RESULT_H