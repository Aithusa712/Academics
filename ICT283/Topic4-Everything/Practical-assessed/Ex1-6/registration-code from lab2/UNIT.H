// COURSE.H - Course class definition/interface
// author KRI
// modified smr

// A .h file is also known as the header file. It is the Interface.
// It should only contain type declarations and prototypes of routines, similar
// to what was done in ict159.

// The implementation will go into the corresponding .cpp file. Implementation is the
// body of the routines.

#ifndef UNIT_H
#define UNIT_H
#include <string>
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
  Unit( const string& unitName, const string& unitID, unsigned cred );  // nam is a pointer to char, revise ict159
  // Construct a course from a name, section letter,
  // and number of credits.

  unsigned GetCredits() const;
  // Get the number of credits.

  void SetCredits( unsigned cred );
  // Set the number of credits.

  const string& GetUnitName() const;

  void SetUnitName(const string& unitName);

  const string& GetUnitID() const;

  void SetUnitID(const string& unitID);

  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.


//private:
    string unitName;   // course name
    string unitID;     // section (letter)
    unsigned credits;       // number of credits
};

// No implementation (code body) should be found after the line }; above.
// See topic 1 reading “Absolute C++. Pages 284-293. Separate
// Implementation/Interface. Structs vs Classes” available from My Unit Readings

// A .h file is interface or header file. Implementation should exist in
// the implementation file. Implemention file have .cpp extensions.
// Implementation is the body of the routine/method
// Concept is the same as what you did in ict159.
// So the following implementation needs to be moved to the corresponding
// implementation file (course.cpp)

// The method is inlined only if you have empirical evidence that inline would
// improve the run-time execution speed.

ostream& operator<<(ostream& os, const Unit& U);
istream& operator>>(istream& input, Unit& U);





#endif
