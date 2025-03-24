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
    int GetMonth() const;
    /**
    * \brief Gets the year by retrieving the string m_year
    */
    int GetYear() const;

    int GetDay() const;

    bool operator<(const Date& other) const;

    bool operator>(const Date& other) const;

    bool operator==(const Date& other) const;

    friend ostream& operator<<(std::ostream& os, const Date& date);



private:
    string m_date;  /**< Date string contains the date in dd month yyyy format */
    int m_year;  /**< Year string contains the month */
    int m_month; /**< Month string contains the year */
    int m_day;
};


#endif // RESULT_H
