#include "Unit.h"

// Default Constructor

Unit::Unit() {
  m_unitName = " ";
  m_unitId = " ";
  m_credits = 0;
}

// Getters

string Unit::GetUnitName() const { return m_unitName; }

string Unit::GetUnitId() const { return m_unitId; }

int Unit::GetCredits() const { return m_credits; }

// Setters

void Unit::SetUnitName(const string unitName) {
  m_unitName = unitName;

  // For Loop to replace underscores into whitespaces
  for (char &c : m_unitName) {
    if (c == '_') {
      c = ' ';
    }
  }
}

void Unit::SetUnitId(const string unitId) {
  m_unitId = unitId;

  // For Loop to replace underscores into whitespaces
  for (char &c : m_unitId) {
    if (c == '_') {
      c = ' ';
    }
  }
}
void Unit::SetCredits(const int credits) { m_credits = credits; }

// Operator Overloading

istream &operator>>(istream &input, Unit &unit) {
  string tempUnitName;
  string tempUnitId;
  int tempCredits;
  input >> tempUnitName >> tempUnitId >> tempCredits;

  unit.SetUnitName(tempUnitName);
  unit.SetUnitId(tempUnitId);
  unit.SetCredits(tempCredits);
  return input;
}

ostream &operator<<(ostream &os, const Unit &unit) {
  os << "  Unit ID:  " << unit.GetUnitId() << '\n'
     << "  Unit Name: " << unit.GetUnitName() << '\n'
     << "  Credits: " << unit.GetCredits() << '\n';
  return os;
}
