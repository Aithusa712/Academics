#include "Time.h"

Time::Time() {
  m_hours = 0;
  m_minutes = 0;
}

int Time::GetHours() const { return m_hours; }

int Time::GetMinutes() const { return m_minutes; }

void Time::SetMinutes(int minutes) { m_minutes = minutes; }

void Time::SetHours(int hours) { m_hours = hours; }
