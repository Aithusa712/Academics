// LightTest.cpp
// See how the calls are arranged
// Comment each call to indicate what is being tested

//--------------------------------------------------------------------

#include "Light.h"

//--------------------------------------------------------------------

void Test1 ();
void Test2 ();
void Test3 ();
void Test4 ();
void Test5 ();
void Test6 ();
void Test7 ();

//--------------------------------------------------------------------

int main()
{
	cout << "Light Test Program" << endl << endl;

	Test1 ();
	Test2 ();
	Test3 ();
	Test4 ();
	Test5 ();
	Test6 ();
	Test7 ();

	cout << endl;
	return 0;
}

//--------------------------------------------------------------------

void Test1 ()
{
	Light light;

	cout << "Test One" << endl;
	cout << light << endl << endl;
}

//--------------------------------------------------------------------

void Test2 ()
{	
	Light light;

	cout << "Test Two" << endl;
	light.Set("red");
	cout << light << endl << endl;
}


//--------------------------------------------------------------------

void Test3 ()
{
	Light light;

	light.Set("red");

	cout << "Test Three" << endl;
	if (!light.Set((float)-9.3))
	{
		cerr << "Radius must be greater than 0" << endl;
	}
	cout << light << endl << endl;
	
}


//--------------------------------------------------------------------

void Test4 ()
{	
	Light light;

	light.Set("red");

	cout << "Test Four" << endl;
	if (!light.Set((float)9.3))
	{
		cerr << "Radius must be greater than 0" << endl;
	}
	cout << light << endl << endl;

}


//--------------------------------------------------------------------

void Test5 ()
{	
	Light light;
	
	light.Set("red");

	cout << "Test Five" << endl;
	if (!light.Set((float)9.3))
	{
		cerr << "Radius must be greater than 0" << endl;
	}

	light.Switch();
	cout << light << endl << endl;
	
}


//--------------------------------------------------------------------

void Test6 ()
{	
	Light light;
	
	light.Set("red");

	cout << "Test Six" << endl;
	if (!light.Set((float)9.3))
	{
		cerr << "Radius must be greater than 0" << endl;
	}

	// Switch it on
	light.Switch();
	
	// Switch it off
	light.Switch();

	cout << light << endl << endl;

}


//--------------------------------------------------------------------

void Test7 ()
{	
	Light light;

	light.Set("red");

	cout << "Test Seven" << endl;
	if (!light.Set((float)9.3))
	{
		cerr << "Radius must be greater than 0" << endl;
	}

	// Switch it on
	light.Switch();

	// Clear it
	light.Clear();

	cout << light << endl << endl;
}

//--------------------------------------------------------------------

