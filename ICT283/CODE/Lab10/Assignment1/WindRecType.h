#ifndef WINDRECTYPE_H
#define WINDRECTYPE_H
#include "Date.h"
#include "Time.h"
#include "vector.h"


/**
 * \file WindRecType.h
 * \brief Header file for the WindRecTyoe struct.
 */

/**
 * \struct WindRecType
 * \brief WindRecType contains the records of Wind Data
 */

struct WindRecType
{

public:



    /**
    * @brief  Set the Date object in the struct
    *
    * This function accepts a date object in the parameter and sets the value of m_date to the parameter value
    * @param date - an object of the Date Class
    * @return void
    */
    void setDate(const Date& date);
    /**
    * @brief  Set the Time object in the struct
    *
    * This function accepts a time object in the parameter and sets the value of m_time to the parameter value
    * @param time - an object of the Time Class
    * @return void
    */
    void setTime(const Time& time);
    /**
    * @brief  Set the value for Speed in the struct
    *
    * This function accepts a float number in the parameter and sets the value of m_speed to the parameter value
    * @param speed - the speed recorded in the Wind Recorded Logs
    * @return void
    */
    void setSpeed(float speed);
    /**
    * @brief  Set the value for temperature in the struct
    *
    * This function accepts a float number in the parameter and sets the value of m_temp to the parameter value
    * @param temp - the temperature recorded in the Wind Recorded Logs
    * @return void
    */
    void setTemperature(float temp);
    /**
    * @brief  Set the value for solar Radiation in the struct
    *
    * This function accepts a float number in the parameter and sets the value of m_solarRadiation to the parameter value
    * @param sr - the solar radiation recorded in the Wind Recorded Logs
    * @return void
    */
    void setSolarRadiation(float sr);
    /**
    * @brief  Retrieve Date
    *
    * This function will return the instance of date from m_date
    * @return m_date
    */
    Date getDate() const;
    /**
    * @brief  Retrieve time
    *
    * This function will return the instance of time from m_time
    * @return m_time
    */
    Time getTime() const;
    /**
    * @brief  Retrieve speed value
    *
    * This function will return the speed value stored in m_speed
    * @return m_speed
    */
    float getSpeed() const;
    /**
    * @brief  Retrieve Temperature value
    *
    * This function will return the temperature value stored in m_temperature
    * @return m_temperature
    */
    float getTemperature() const;
    /**
    * @brief  Retrieve Solar Radiation value
    *
    * This function will return the Solar Radiation value stored in m_solarRadiation
    * @return m_solarRadiation
    */
    float getSolarRadiation() const;

private:
    /// This variable holds an instance of Date
    Date m_date;
    /// This variable holds an instance of time
    Time m_time;
    /// This variable holds a speed value
    float m_speed;
    /// This variable holds a temperature value
    float m_temperature;
    /// This variable holds a solar radiation value
    float m_solarRadiation;
};

typedef Vector<WindRecType> WindlogType;
#endif // WINDRECTYPE_H
