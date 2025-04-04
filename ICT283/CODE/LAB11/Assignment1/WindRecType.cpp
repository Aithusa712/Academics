#include "WindRecType.h"

//Set date
void WindRecType::setDate(const Date& date)
{
    m_date = date;
}
//Set time
void WindRecType::setTime(const Time& time)
{
    m_time = time;
}
//Set set speed
void WindRecType::setSpeed(float speed)
{
    m_speed = speed;
}
//Set set temperature
void WindRecType::setTemperature(float temperature)
{
    m_temperature = temperature;
}
//Set solar radiation
void WindRecType::setSolarRadiation(float solarRadiation)
{
    m_solarRadiation = solarRadiation;
}

//get instance of date
Date WindRecType::getDate() const
{
    return m_date;
}
//get instance of time
Time WindRecType::getTime() const
{
    return m_time;
}
//get speed stored in m_speed
float WindRecType::getSpeed() const
{
    return m_speed;
}
//get temperature stored in m_temperature
float WindRecType::getTemperature() const
{
    return m_temperature;
}
//get solar radiation stored in m_solarRadiation
float WindRecType::getSolarRadiation() const
{
    return m_solarRadiation;
}

bool WindRecType::operator<(const WindRecType& other) const {
    // Compare only by date (year and month)
    if (m_date < other.m_date) {
        return true;
    }
    return false;
}

bool WindRecType::operator>(const WindRecType& other) const {
    return other < *this;
}

bool WindRecType::operator==(const WindRecType& other) const {
    // Compare only by year and month in the date
    return m_date == other.m_date;
}
std::ostream& operator<<(std::ostream& os, const WindRecType& record) {
    os << record.m_date.GetDate() << record.m_time.GetTime()<< endl;
    return os;
}
