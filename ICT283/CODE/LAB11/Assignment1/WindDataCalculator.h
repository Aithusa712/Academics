#ifndef WINDDATACALULATOR
#define WINDDATACALULATOR_H
#include <string>
#include "WindRecType.h"

using namespace std;

/**
 * \file WindDataCalculator.h
 * \brief Header file for the Date class.
 */

/**
 * \class WindDataCalculator
 * \brief WindDataCalculator handles all the calculation process of the program
 */


class WindDataCalculator
{
public:
    /**
    * @brief  Gets the monthly record of wind data
    *
    * This function returns a record of only the month and year defined by the year and month parameter.
    * @param wind_data - the record to be processed
    * @param year - the year of the record the user wants to retrieve
    * @param month - the month of the record the user wants to retrieve
    * @return WindlogType
    */

    void getBst(const WindlogType& wind_data);
    WindlogType GetAllMonthlyData(const WindlogType& wind_data, const string& month);
    WindlogType GetMonthlyData(const WindlogType& wind_data, const string& year, const string& month);
    /**
    * @brief  Calculate the average wind speed
    *
    * This function will calculate and printout the average wind speed of the month and year the user wants
    * @param wind_data - record of data the user wants to retrieve from
    * @return void
    */
    void calculateAvgSpeed(const WindlogType& wind_data);
    /**
    * @brief  Calculate the average temperature
    *
    * This function will calculate and printout the average wind temperature of all the month of the year the user wants
    * @param wind_data - record of data the user wants to retrieve from
    * @return void
    */
    void calculateAvgTemp(const WindlogType& wind_data);
    /**
    * @brief  Calculate the average solar radiation
    *
    * TTis function will calculate and printout the average wind solar radiation of all the month of the year the user wants
    * @param wind_data - record of data the user wants to retrieve from
    * @return void
    */
    void calculateAvgSR(const WindlogType& wind_data);
    /**
    * @brief  Calculate the average wind speed, temperature, and solar radiation
    *
    * This function will calculate and printout to a csv file the average wind speed, temperature, solar radiation all the month of the year the user wants
    * @param wind_data - record of data the user wants to retrieve from
    * @return void
    */
    void calculateAll(const WindlogType& wind_data);
    /**
    * @brief  Calculate average
    *
    * This function does the actual average calculation for all the other functions
    * @param wind_data - record of data the user wants to retrieve from
    * @param option - chooses which wind data to calculate the average from int 1 = speed, int 2 = temperature, int 3 = solar radiation
    * @return float
    */
    float calculateAvg(const WindlogType& wind_data, int option);
    /**
    * @brief  Calculate standard deviation
    *
    * This function does the actual standard deviation calculation for all the other functions
    * @param wind_data - record of data the user wants to retrieve from
    * @param avg - the average. This is required to calculate the standard deviation
    * @param option - chooses which wind data to calculate the average from int 1 = speed, int 2 = temperature
    * @return float
    */
    float calculateStd(const WindlogType& wind_data, float avg, int option);
    /**
    * @brief  Checks the month
    *
    * This function just checks if the string matches the correct format of months
    * @param monthInput- the month that the user entered
    * @return bool
    */
    bool checkMonth(string& monthInput);
    /**
    * @brief  Rounds off numbers
    *
    * This function rounds off float values by 2 decimal points
    * @param num - the number to be rounded off
    * @return float
    */
    float roundOff(float num);

    float calculateSPCC(const WindlogType& wind_data, int option1, int option2);

    void calculateSPCCForMonth(const WindlogType& wind_data);

    float calculateMAD(const WindlogType& wind_data, float avg, int option);

    bool checkMonthExists(const std::string& year, const std::string& month);

private:
    WindlogBst m_wind_data_bst;
    WindRecType m_test;
};



#endif // WINDDATACALULATOR_H
