#include "Result.h"

Result::Result()
{
    m_mark = 0.0f;
}

Result::~Result() {}

void Result::SetMark(float mark)
{
    m_mark = mark;
}

float Result::GetMark() const
{
    return m_mark;
}
void Result::SetUnit(const Unit& unit)
{
    m_unit = unit;
}
void Result::SetDate(const Date& date)
{
    m_date = date;
}

const Unit& Result::GetUnit() const
{
    return m_unit;
}

const Date& Result::GetDate() const
{
    return m_date;
}

istream & operator >>( istream & input, Result & result)
{
    Unit unit;
    float mark = 0.0f;
    Date date;

    input >> unit >> mark >> date;
    result.SetUnit(unit);
    result.SetMark(mark);
    result.SetDate(date);

    return input;
}

ostream & operator <<( ostream & os, const Result & result)
{
    os << result.GetUnit() <<
       "  Marks: "<< result.GetMark() << "\n"
       << result.GetDate();
    return os;
}
