// PatternLight
// A light that shines through a cutout giving it a particular shape
//
// Version
// 01 - Nicola Ritter
//
//--------------------------------------------------------------------

#ifndef PATTERN_LIGHT
#define PATTERN_LIGHT

//--------------------------------------------------------------------

#include "Light.h"

//--------------------------------------------------------------------
// Available shapes
//--------------------------------------------------------------------

const int NO_SHAPE = 0;
const int LEFT_ARROW = 1;
const int RIGHT_ARROW = 2;
const int MAX_SHAPE = 2;

//--------------------------------------------------------------------

class PatternLight : public Light
{
public:
	PatternLight () {Clear();}
	virtual ~PatternLight () {};

	void Clear ();

	bool Set (int shape);
	int  Get () const {return m_shape;}

	friend ostream& operator << (ostream &ostr, const PatternLight &light);


private:
	int m_shape;

};

//--------------------------------------------------------------------

#endif
