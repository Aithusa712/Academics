// Rectangle.h

// Version
// 01 - Nicola Ritter
// 02 - smr
//-------------------------------------------------------------------

#ifndef RECTANGLE
#define RECTANGLE

//-------------------------------------------------------------------


#include "Shape.h"

#include <iostream> //is this needed here?


using namespace std; // does the std namespace need to be exposed in this header file?

//-------------------------------------------------------------------

class Rectangle : public Shape
{
public:
	Rectangle();
	virtual ~Rectangle () {};

	virtual void Draw () const; // for documentation only. Parent has declared this virtual already.
	virtual void Input (); // "virtual" for documentation only. Parent has declared this virtual already.


private:
	int m_width;
};

#endif

