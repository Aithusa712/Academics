// COURSE.H - Unit class definition/interface
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

class Unit {
public:
  Unit();
  Unit( const string unitName, const string unitId, unsigned credits );  // name is a pointer to char, revise ict159
  // Construct a course from a name, section letter,
  // and number of credits.

  string GetUnitName()const;
  string GetUnitId()const;
  unsigned GetCredits()const; // Get the number of credits.
  

  void SetUnitName(const string unitName);
  void SetUnitId(const string unitId);
  void SetCredits(const unsigned credits); // Set the number of credits.


private:
  string unitName;
  string unitId;  
  int  credits;   
};
  ostream& operator <<( ostream& os, const Unit& unit );
  istream& operator >>( istream& input, Unit& unit );



#endif
