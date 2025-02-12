#include "Registration.h"
#include "Result.h"

// Default Constructor

Registration::Registration() {
  m_count = 0;
  m_semester = 0;
  m_studentId = 0;

  // Loop to initialize all Result objects in the array
  for (int i = 0; i < MaxResults; i++) {
    m_result[i] = Result();
  }
}

// Getters

int Registration::GetCredits() const {
  int sum = 0;
  for (int i = 0; i < m_count; i++)
    sum += m_result[i].GetCredits();

  return sum;
}

long Registration::GetStudentId() const { return m_studentId; }

int Registration::GetSemester() const { return m_semester; }

int Registration::GetCount() const { return m_count; }

Result Registration::GetResult(int idx) const { return m_result[idx]; }

// Setters

void Registration::SetResult(int idx, Result &res) { m_result[idx] = res; }

void Registration::SetCount(int count) { m_count = count; }

void Registration::SetSemester(int semester) { m_semester = semester; }

void Registration::SetStudentId(long studentId) { m_studentId = studentId; }

// Operator Overloading

ostream &operator<<(ostream &os, const Registration &registration) {
  os << "Student ID: " << registration.GetStudentId() << '\n'
     << "Semester:   " << registration.GetSemester() << '\n';

  for (int i = 0; i < registration.GetCount(); i++)
    os << registration.GetResult(i) << '\n';

  return os;
}

istream &operator>>(istream &input, Registration &registration) {

  long tempStudentId = 0;
  int tempSemester = 0;
  int tempCount = 0;
  input >> tempStudentId >> tempSemester >> tempCount;

  registration.SetStudentId(tempStudentId);
  registration.SetSemester(tempSemester);
  registration.SetCount(tempCount);

  for (int i = 0; i < registration.GetCount(); i++) {
    Result tempResult;
    input >> tempResult;
    registration.SetResult(i, tempResult);
  }
  return input;
}


ostream &operator<<(ostream &os, const Result &R) {

  int day = R.GetDate().GetDay();
  int month = R.GetDate().GetMonth();
  int year = R.GetDate().GetYear();
  string date = R.ConvertDate(day, month, year); // Call Helper function to convert integer date values into string value

  os << R.GetUnit();
  os << "  Mark: " << R.GetMarks() << '\n';
  os << "  Date: " << date << '\n';
  return os;
}

istream &operator>>(istream &input, Result &R) {

  Unit tempUnit;
  Date tempDate;
  int tempMarks;

  input >> tempUnit >> tempMarks >> tempDate;

  R.SetUnit(tempUnit);
  R.SetMarks(tempMarks);
  R.SetDate(tempDate);
  return input;
}
