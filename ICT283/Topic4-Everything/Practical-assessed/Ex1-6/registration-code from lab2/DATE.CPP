#include "DATE.H"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    this->day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    this->month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    this->year = year;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.day >> date.month >> date.year;
    return is;
}
