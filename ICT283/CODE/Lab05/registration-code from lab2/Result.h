#ifndef RESULT_H
#define RESULT_H

#include "Unit.h"
#include "Date.h"
#include <iostream>
using namespace std;
class Result
{
public:
    Result();
    ~Result();

    void SetMark(float mark);
    float GetMark() const;

    void SetUnit(const Unit& unit);
    void SetDate(const Date& date);
    const Unit& GetUnit() const;
    const Date& GetDate() const;

private:
    float m_mark;
    Unit m_unit;
    Date m_date;
};
ostream & operator <<( ostream & os, const Result & result);
istream & operator >>( istream & input, Result & result);

#endif // RESULT_H
