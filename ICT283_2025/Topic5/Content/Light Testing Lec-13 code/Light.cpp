// Light.cpp
//--------------------------------------------------------------------

#include "Light.h"

// Counters and the reset are not part of the Light class.
// For demonstration purposes only to keep seen which constructors are called and how often
// Counter variables. Not part of the class. Only for demonstrations
// purposes only.
// Global variables are being used here for demonstration of the counting, and such variables are not normally allowed.
int dcounter = 0;  // default constructor counter
int ccounter = 0;  // copy constructor counter

void resetcount(){  // not part of the light class
    dcounter = 0;
    ccounter = 0;
}

//--------------------------------------------------------------------

Light::Light ()
{
	cout << "default Construction count = " << ++dcounter;   // uses global variable to keep track of counting.
               cout <<     "  Total constructions = " << dcounter+ccounter << endl;
	Clear();
}

//--------------------------------------------------------------------

Light::Light (const Light &other)
{
	cout << "    copy Construction count = " << ++ccounter;
                cout <<    "  Total constructions = " << dcounter+ccounter << endl;
	Clear ();
	m_colour = other.m_colour;
	m_radius = other.m_radius;
	m_on = other.m_on;
}

//--------------------------------------------------------------------

void Light::Clear ()
{
	//cout << "Running Light Clear" << endl;
	m_colour = "white";
	m_radius = 0;
	m_on = false;
}

//--------------------------------------------------------------------

ostream &operator << (ostream &ostr, const Light &light)
{
	ostr << light.m_radius << " cm, " << light.m_colour << " light is ";
	if (light.m_on)
	{
		ostr << "on";
	}
	else
	{
		ostr << "off";
	}

	return ostr;
}

//--------------------------------------------------------------------

bool Light::Set(float radius)
{
	if (radius > 0)
	{
		m_radius = radius;
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------

void Light::Switch ()
{
	if (m_on)
	{
		m_on = false;
	}
	else
	{
		m_on = true;
	}
}

//--------------------------------------------------------------------
