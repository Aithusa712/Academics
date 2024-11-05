// PatternLightTest.cpp

#include "PatternLight.h"
#include <iostream>
using namespace std;


int main()
{
	PatternLight light;
	cout << light << endl;

	light.Set (LEFT_ARROW);
	cout << light << endl;

	light.Switch ();
	cout << light << endl;

	cout << endl;
	return 0;
}
