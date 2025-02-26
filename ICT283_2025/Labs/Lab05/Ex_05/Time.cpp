/**
 * @brief A class representing time in hours and minutes
 */
#include "Time.h"

/**
 * @brief Default constructor
 * @details Initializes time to 00:00
 */
Time::Time() {
  m_hours = 0;
  m_minutes = 0;
}

/**
 * @brief Get the hours component of the time
 * @return The hours value (0-23)
 */
int Time::GetHours() const { return m_hours; }

/**
 * @brief Get the minutes component of the time
 * @return The minutes value (0-59)
 */
int Time::GetMinutes() const { return m_minutes; }

/**
 * @brief Set the minutes component of the time
 * @param minutes The minutes value to set (0-59)
 */
void Time::SetMinutes(int minutes) { m_minutes = minutes; }

/**
 * @brief Set the hours component of the time
 * @param hours The hours value to set (0-23)
 */
void Time::SetHours(int hours) { m_hours = hours; }
