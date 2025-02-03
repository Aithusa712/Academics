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

const Unit& Result::GetUnit() const
{
    return m_unit;
}

istream & operator >>( istream & input, Result & result)
{
    input >> result.m_unit >> result.m_mark;
    result.SetUnit(result.m_unit);
    result.SetMark(result.m_mark);

    return input;
}

ostream & operator <<( ostream & os, const Result & result)
{
    os << result.GetUnit() <<
        "  Marks: "<< result.GetMark() << '\n';
    return os;
}
