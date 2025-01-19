// COURSE.H - Course class definition/interface
// author KRI
// modified smr

// A .h file is also known as the header file. It is the Interface.
// It should only contain type declarations and prototypes of routines, similar
// to what was done in ict159.

// The implementation will go into the corresponding .cpp file. Implementation is the
// body of the routines.

#ifndef COURSE_H
#define COURSE_H

#include <iostream>

// No routine from string.h is needed in this header file course.h.
// So it has been commented out.
// Do not #include files that are not needed.
// The implementation file course.cpp needs string.h, so #include there

// #include <string.h>  // C string library, DO NOT INCLUDE HEADER FILES IF NOT NEEDED HERE

// Is iostream needed in this  file. Easy to check by commenting out the line #include <iostream>

using namespace std;


// Although the usage of unsigned here is fine, usage of unsigned type can be problematic.
// Can you think of what problems can occur?

const unsigned CourseNameSize = 10;

class Course {
public:
  Course();
  Course( const char * nam, char sect, unsigned cred );  // nam is a pointer to char, revise ict159
  // Construct a course from a name, section letter,
  // and number of credits.

  unsigned GetCredits() const;
  // Get the number of credits.

  void SetCredits( unsigned cred );
  // Set the number of credits.

  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  friend ostream & operator <<( ostream & os, const Course & C );
  friend istream & operator >>( istream & input, Course & C );

private:
  char name[CourseNameSize];  // course name, C style string. not a C++ string object
  char section;   // section (letter) can be enrolment mode
  int  credits;   // number of credits
};

// No implementation (code body) should be found after the line }; above.
// See topic 1 reading “Absolute C++. Pages 284-293. Separate 
// Implementation/Interface. Structs vs Classes” available from My Unit Readings
 
// A .h file is interface or header file. Implementation should exist in
// the implementation file. Implementation file have .cpp extensions.
// Implementation is the body of the routine/method
// Concept is the same as what you did in ict159.
// So the following implementation needs to be moved to the corresponding
// implementation file (course.cpp)

// The method is inlined only if you have empirical evidence that inline would
// improve the run-time execution speed. Without this evidence, where should the
// following code be moved to?


inline unsigned Course::GetCredits() const
{
  return credits;
}

inline void Course::SetCredits( unsigned cred )
{
  credits = cred;
}

#endif
