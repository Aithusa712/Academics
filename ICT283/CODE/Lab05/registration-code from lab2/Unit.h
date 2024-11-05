#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>

using namespace std;

class Unit
{
public:
    Unit();
    void SetunitName(string unitName);
    void SetunitId(string unitId);
    void SetCredits(unsigned credits);
    string GetUnitName() const;
    string GetUnitId() const;
    unsigned GetCredits() const;

private:
    string m_unitName;
    string m_unitId;
    int  m_credits;
};

ostream & operator <<( ostream & os, const Unit & unit );
istream & operator >>( istream & input, Unit & unit );


#endif
