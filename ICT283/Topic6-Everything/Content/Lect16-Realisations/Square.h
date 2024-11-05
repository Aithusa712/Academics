// Square.h

// Version
// 01 - Nicola Ritter
// 02 - smr
//-------------------------------------------------------------------

#ifndef SQUARE
#define SQUARE

//-------------------------------------------------------------------

#include "Shape.h"
#include <iostream> // needed here? why???? Do not expose/include anything not needed.
					// ***MOVE*** to .cpp

using namespace std; // needed here or in the .cpp?
					  // do not open the namespace in the header
					  // so should this line go?

//-------------------------------------------------------------------

class Square : public Shape
{
public:
	Square() {m_description = "square";} // for illustration only, SETTING PARENT DATA - move IMPLEMENTATION to cpp
	virtual ~Square () {};

	virtual void Draw () const; // for documentation only. Parent has declared this virtual already. one of the requirements for dynamic polymorphism

private:

};

#endif

