// LightTest.cpp
// One big main()
// how would you modularise?

//--------------------------------------------------------------------

#include "Light.h"

//--------------------------------------------------------------------

int main()
{
	Light light;
	Light light2 (light);
	cout << "Light Test Program" << endl << endl;

	cout << "Test One" << endl;
	cout << light << endl << endl;

	cout << "Test Two" << endl;
	light.Set("red");
	cout << light << endl << endl;

	cout << "Test Three" << endl;
	if (!light.Set((float)-9.3))
	{
		cerr << "Radius must be greater than 0" << endl;
	}
	cout << light << endl << endl;
	
	cout << "Test Four" << endl;
	if (!light.Set((float)9.3))
	{
		cerr << "Radius must be greater than 0" << endl;
	}
	cout << light << endl << endl;

	cout << "Test Five" << endl;
	light.Switch();
	cout << light << endl << endl;
	
	cout << "Test Six" << endl;
	light.Switch();
	cout << light << endl << endl;

	cout << "Test Seven" << endl;
	light.Switch();
	light.Clear();
	cout << light << endl << endl;

	cout << endl;
	return 0;
}

//--------------------------------------------------------------------
