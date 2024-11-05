// PatternLight.cpp

#include "PatternLight.h"

void PatternLight::Clear ()
{
	cout << "Clearing Pattern Light" << endl;
	Light::Clear();
	m_shape = NO_SHAPE;
}

bool PatternLight::Set (int shape)
{
	if (shape >= NO_SHAPE && shape <= MAX_SHAPE)
	{
		m_shape = shape;
		return true;
	}
	else
	{
		return false;
	}
}


ostream& operator << (ostream &ostr, const PatternLight &light)
{
	ostr << static_cast<Light>(light);

	if (light.m_on && light.m_shape != NO_SHAPE)
	{
		ostr << ", showing ";
		switch (light.m_shape)
		{
			case LEFT_ARROW:
				ostr << "left arrow";
				break;
			case RIGHT_ARROW:
				ostr << "right arrow";
				break;
		}
	}

	return ostr;
}

