// Light.h
// Class representing a light
//
// Version
// 01 - Nicola Ritter, 05/02/2007
// 02 - Nicola Ritter, 06/02/2007
//      Added in Set and Get methods
//--------------------------------------------------------------------

#ifndef LIGHT_H
#define LIGHT_H

//--------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//--------------------------------------------------------------------

class Light
{
public:
	Light ();
	Light (const Light &other);
	virtual ~Light () {};

	virtual void Clear ();

	void Set (const string &colour) {m_colour = colour;}
	bool Set (float radius);
	void Switch ();

	void Get (string &colour) const {colour = m_colour;}

	Light& operator=(const Light & rhs);

	friend ostream& operator << (ostream &ostr, const Light &light);

protected:
	// Any string giving a colour is acceptable
	string m_colour;
	// In centimeters
	float  m_radius;
	bool   m_on;
};

//--------------------------------------------------------------------

#endif
