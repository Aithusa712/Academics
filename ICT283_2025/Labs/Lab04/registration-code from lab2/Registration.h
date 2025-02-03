// REGISTRATION.H - Registration class definition/interface
// author KRI
// modified smr

#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Result.h" //#include your own files first

#include <algorithm>
#include <cwchar>
#include <iostream>


using namespace std;

const unsigned MaxResults = 10;

class Registration {
public:
  Registration();

  unsigned GetCredits() const;
  long GetStudentId() const;
  unsigned GetSemester() const;
  unsigned GetCount() const;
  Result GetResult(int idx) const;

  void SetResult(unsigned idx, Result& res);
  void SetCount(unsigned count);
  void SetSemester(unsigned semester);
  void SetStudentId(long studentId);
  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  

private:
  long studentId;             // student ID number
  unsigned semester;          // semester year, number
  unsigned count;             // number of courses
  Result result[MaxResults]; // array of courses
};

// No implementation (code body) should be found after the line }; above.
// See topic 1 reading “Absolute C++. Pages 284-293. Separate 
// Implementation/Interface. Structs vs Classes” available from My Unit Readings
 
// A .h file is interface or header file. Implementation should exist in
// the implementation file. Implementation file have .cpp extensions.
// Implementation is the body of the routine/method
// Concept is the same as what you did in ict159.
// So the following implementation needs to be moved to the corresponding
// implementation file (Registration.cpp)

// The method is inlined only if you have empirical evidence that inline would
// improve the run-time execution speed.

ostream & operator <<( ostream & os, const Registration & registration);
istream & operator >>( istream & input, Registration & registration );
#endif

