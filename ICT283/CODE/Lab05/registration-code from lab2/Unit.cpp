#include "Unit.h"
#include <string>

Unit::Unit()
{
    m_unitName = "";
    m_unitId ="";
    m_credits = 0;
}

void Unit::SetunitName(string unitName)
{
    m_unitName = unitName;
    for (char& c : m_unitName)
    {
        if (c == '_')
        {
            c = ' ';
        }
    }

}
void Unit::SetunitId(string unitId)
{
    m_unitId = unitId;
    for (char& c : m_unitId)
    {
        if (c == '_')
        {
            c = ' ';
        }
    }
}
void Unit::SetCredits(unsigned credits)
{
    m_credits = credits;
}
string Unit::GetUnitName() const
{
    return m_unitName;
}
string Unit::GetUnitId() const
{
    return m_unitId;
}
unsigned Unit::GetCredits() const
{
    return m_credits;
}

istream & operator >>( istream & input, Unit & unit )
{

    string unitName = "";
    string unitId = "";
    unsigned credits = 0;

    input >> unitName >> unitId >> credits;
    unit.SetunitName(unitName);
    unit.SetunitId(unitId);
    unit.SetCredits(credits);
    return input;
}

ostream & operator <<( ostream & os, const Unit & unit)
{
    os << "  Unit:  " << unit.GetUnitName() << '\n'
       << "  Unit ID: " << unit.GetUnitId()<< '\n'
       << "  Credits: " << unit.GetCredits() << '\n';
    return os;
}
