// Triangle.h

// Version
// 01 - Nicola Ritter
// 02 - smr
//-------------------------------------------------------------------

#ifndef TRIANGLE
#define TRIANGLE

//-------------------------------------------------------------------

#include <iostream> // why??????  Should it be here? Where should the #include be?
#include "Shape.h"

using namespace std;

//-------------------------------------------------------------------

class Triangle : public Shape
{
public:
    Triangle()
    {
        m_description = "triangle";
    }; // for illustration only - move IMPLEMENTATION to cpp
    virtual ~Triangle () {};

    virtual void Draw () const; // for documentation only. Parent has declared this virtual already.

private:

};

#endif

