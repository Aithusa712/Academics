// COURSE.CPP - Course class implementation

#include "course.h"

#include <string.h>  // C string library needed here for the C string routines.
                     // revise your ict159 work if forgotten.

Course::Course()
{
  name[0] = '\0'; // it is a char * string, not a C++ string object.
}

Course::Course( const char * nam, char sect,
                unsigned cred )
{
  strncpy( name, nam, CourseNameSize );  //strncpy needed from string.h
  section = sect;
  credits = cred;
}


// The following routine does not belong to the Course class, so it is NOT a method
// You can see that the prefix Course:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
istream & operator >>( istream & input, Course & C )
{
  input >> C.name >> C.section >> C.credits;
  return input;
}


// The following routine does not belong to the Course class, so it is NOT a method
// You can see that the prefix Course:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
ostream & operator <<( ostream & os, const Course & C )
{
  os << "  Course:  " << C.name << '\n'
     << "  Section: " << C.section << '\n'
     << "  Credits: " << C.credits << '\n';
  return os;
}
