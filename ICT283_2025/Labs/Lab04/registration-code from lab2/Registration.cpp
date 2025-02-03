// REGISTRATION.CPP - Registration class implementation.

#include "Registration.h"

Registration::Registration() { count = 0; }

unsigned Registration::GetCredits() const {
  unsigned sum = 0;
  for (unsigned i = 0; i < count; i++)
    sum += result[i].GetCredits();

  return sum;
}

long Registration::GetStudentId() const{
return studentId;
}
unsigned Registration::GetSemester() const{
return semester;
}

unsigned Registration::GetCount() const { return count; }

Result Registration::GetResult(int idx) const { return result[idx]; }

void Registration::SetResult(unsigned idx, Result &res) { result[idx] = res; }


void Registration::SetCount(unsigned count){
  this->count = count;
}

void Registration::SetSemester(unsigned semester){
  this->semester = semester;
}

void Registration::SetStudentId(long studentId){
  this->studentId = studentId;
}
// The following routine does not belong to the Registration class, so it is NOT
// a method You can see that the prefix Registration:: isn't there. So it is
// general routine, just a function that you would have learnt in ict159, but
// this one has an unusual name.
ostream &operator<<(ostream &os, const Registration& registration) {
  os << "Student ID: " << registration.GetStudentId() << '\n'
     << "Semester:   " << registration.GetSemester() << '\n';

  for (unsigned i = 0; i < registration.GetCount(); i++)
    os << registration.GetResult(i) << '\n';

  return os;
}

// The following routine does not belong to the Registration class, so it is NOT
// a method You can see that the prefix Registration:: isn't there. So it is
// general routine, just a function that you would have learnt in ict159, but
// this one has an unusual name.

istream &operator>>(istream &input, Registration& registration) {

  long tempStudentId=0;
  unsigned tempSemester=0;
  unsigned tempCount=0;
  input >> tempStudentId >> tempSemester >> tempCount;
  
  registration.SetStudentId(tempStudentId);
  registration.SetSemester(tempSemester);
  registration.SetCount(tempCount);

  for (unsigned i = 0; i < registration.GetCount(); i++) {
    Result tempResult;
    input >> tempResult;
    registration.SetResult(i,tempResult);
  }
  return input;
}
