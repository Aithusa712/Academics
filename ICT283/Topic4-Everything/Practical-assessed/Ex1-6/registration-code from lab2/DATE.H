#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
    Date();
    Date(int day, int month, int year);

    int getDay() const;
    void setDay(int day);

    int getMonth() const;
    void setMonth(int month);

    int getYear() const;
    void setYear(int year);

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);

private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
