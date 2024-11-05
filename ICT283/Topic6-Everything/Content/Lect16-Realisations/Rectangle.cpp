// Rectangle.cpp

#include "Rectangle.h"
// output is done here,
// so #include <iostream> here. not in .h
// namespace should not be opened up in .h unless needed there



//-------------------------------------------------------------------

Rectangle::Rectangle (): m_width(0)   // INITILIASE ITS OWN DATA
{
	m_description = "rectangle";       // SET INHERITED PARENT DATA
}

//-------------------------------------------------------------------

void Rectangle::Draw () const
{
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width * ASPECT_RATIO; col++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
}

//-------------------------------------------------------------------

void Rectangle::Input ()
{
	Shape::Input (); // Calls the parent's Input
	cout << "Enter rectangle width: ";
	cin >> m_width;
}

//-------------------------------------------------------------------

