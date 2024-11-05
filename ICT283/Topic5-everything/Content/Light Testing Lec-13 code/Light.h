// Light.h
// Class representing a light
//
// Version
// original - Nicola Ritter
// modified - smr
//
//--------------------------------------------------------------------

#ifndef LIGHT_H
#define LIGHT_H

//--------------------------------------------------------------------

#include <iostream>   // <---------- WHEN YOU SEE SOMETHING LIKE THIS IN A .h FILE, it you indicate
						// a design issue. Why? Hint: MVC
#include <string>

using namespace std;

//--------------------------------------------------------------------

// not part of the Light class. Used only for demonstration
void resetcount();


// SHOULD THE IMPLEMENTATION BE INLINE?
// Which rule in the coding standards book advice about this?
// Make the necessary changes in the code for practice.
class Light
{
public:
	Light ();
	Light (const Light &other);  // what kind of constructor is this? Is it essential to have it? Why?
	virtual ~Light () {};        // Why would this be virtual

	virtual void Clear ();
	
			// implementation in the interface for demo purposes only. MOVE IMPLEMENTATION TO .cpp
	void Set (const string &colour) {m_colour = colour;}  
	bool Set (float radius);
	void Switch ();

	void Get (string &colour) const {colour = m_colour;} // implementation in the interface for demo purposes only

	friend ostream& operator << (ostream &ostr, const Light &light);  // for debugging only. shouldn't normally be friend

protected:
	// Any string giving a colour is acceptable
	string m_colour;
	// In centimeters
	float  m_radius;
	bool   m_on;
};

//--------------------------------------------------------------------

#endif
