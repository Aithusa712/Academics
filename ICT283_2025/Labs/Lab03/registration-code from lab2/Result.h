#ifndef RESULT_H
#define RESULT_H

#include "Unit.h"
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
        const Unit& GetUnit() const;

        friend ostream & operator <<( ostream & os, const Result & result);
        friend istream & operator >>( istream & input, Result & result);


    private:
        float m_mark;
        Unit m_unit;
};

#endif // RESULT_H
