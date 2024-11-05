#ifndef RESULT_H
#define RESULT_H

#include "unit.h"
#include "date.h"
#include <iostream>

class Result {
public:
    Result();
    Result(const Unit& unit, const Date& date, float mark);

    const Unit& GetUnit() const;
    void SetUnit(const Unit& unit);

    const Date& GetDate() const;
    void SetDate(const Date& date);

    float GetMark() const;
    void SetMark(float mark);



private:
    Unit unit;
    Date date;
    float mark;
};

    ostream & operator <<( ostream & os, const Result& Re);
    istream & operator >>( istream & input, Result& Re );

#endif // RESULT_H
