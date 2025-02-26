// Triangle.cpp
// how about iostream? Where should the #include be?

#include "Triangle.h"

//-------------------------------------------------------------------

void Triangle::Draw () const // does the actual drawing. what does const mean in this context?
{
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < row+1; col++)
		{
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
}

//-------------------------------------------------------------------
