#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;
class Date
{
    public:
        Date();
        ~Date();


        void SetDate(int day, int month, int year);
        string GetDate() const;


    private:
        string m_date;

};

ostream & operator <<( ostream & os, const Date & date);
istream & operator >>( istream & input, Date & date);

#endif // RESULT_H
