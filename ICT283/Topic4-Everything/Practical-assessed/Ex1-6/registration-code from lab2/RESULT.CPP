#include "result.h"

Result::Result() : unit(""), date(0), mark(0.0f) {}

Result::Result(const Unit& unit,const Date& date, float mark) : unit(unit),date(date) mark(mark) {}


const Unit& Result::GetUnit() const {
    return unit;
}

void Result::SetUnit(const Unit& unit) {
    this->unit = unit;
}

const Date& Result::GetDate() const {
    return date;
}

void Result::SetDate(const Date& date) {
    this->date = date;
}

float Result::GetMark() const {
    return mark;
}

void Result::SetMark(float mark) {
    this->mark = mark;
}

// Input and Output stream operators for Result class
istream& operator>>(istream& input, Result& Re)
{
  input >> Re.unit >> Re.mark >> Re.date;
  return input;
}


std::ostream& operator<<(std::ostream& os, const Result& Re) {
    os << Re.GetUnit();
    os << "Marks: " << Re.GetMark() << '\n';
    os << "Date: " << Re.GetDate() << '\n';
    return os;
}
