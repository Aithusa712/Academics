// Constructions
//Topic 5 Lec-14.ppt
// smr

#include "Light.h"

#include <vector> // STL vector to demonstrate what happens when objects get added to the data structure

using namespace std;

const int NLights = 10;

void InputLight (Light &light);
Light InputLight ();

int test0 ();  // No vec. light is inside for loop, light assigned
int test0o ();  // No vec. light is outside for loop, light assigned
int test0a ();  // No vec. light is inside for loop, call by reference
int test0b ();  // No vec. light is outside for loop, call by reference

// vec of Light used in the following
int test1 ();  // light is inside for loop. InputLight (light);
int test2 ();  // light is outside for loop. InputLight (light);
int test3 (); // light is outside for loop. light = InputLight ();
int test4 (); // light is inside for loop. light = InputLight ();
int test5 (); // light is inside for loop. Light light = InputLight (). initialisation

void InputLight (Light &light)
{
	cout << "Input " << endl;
	light.Set(20.0);
	light.Set ("red");
}

Light InputLight ()
{
	cout << "Input " << endl;

	Light light; // local
	light.Set(20.0);
	light.Set ("red");

	return light;
}


int main(){

    test0 ();  // No vec. light is inside for loop, light assigned
    resetcount();

    test0o ();  // No vec. light is outside for loop, light assigned
    resetcount();

    test0a ();  // No vec. light is inside for loop, call by reference
    resetcount();

    test0b ();  // No vec. light is outside for loop, call by reference
    resetcount();

//cout << "\n vec of Light used in the following" << endl;
//    test1(); // light is inside for loop. InputLight (light);
//    resetcount();
//
//    test2(); // light is outside for loop. InputLight (light);
//    resetcount();
//
//    test3 (); // light is outside for loop. light = InputLight ();
//    resetcount();
//
//    test4 (); // light is inside for loop. light = InputLight ();
//    resetcount();
//
//    test5();
//    resetcount();

    cout << endl;
	return 0;
}

// No vec, light is inside for loop, light assigned
int test0(){
	cout << "\n****test0 ()  // No vec. light is inside for loop, light assigned" << endl;

	for (int index = 0; index < NLights; index++)
	{
	    Light light;  // default constructor called
		light = InputLight (); // this is assignment
	}

	cout << endl;
	return 0;
}

// No vec. light is outside for loop, light assigned
int test0o(){
	cout << "\n****test0o ()  // No vec. light is outside for loop, light assigned" << endl;

    Light light;  // default constructor called
	for (int index = 0; index < NLights; index++)
	{
		light = InputLight (); // this is assignment
	}

	cout << endl;
	return 0;
}


// No vec, light is inside for loop, call by reference
int test0a(){
	cout << "\n****test0a ()  // No vec. light is inside for loop, call by reference" << endl;

	for (int index = 0; index < NLights; index++)
	{
	    Light light;
		InputLight (light); // call by reference - see parameter declaration
	}

	cout << endl;
	return 0;
}

// No vec. light is outside for loop, call by reference
int test0b(){
	cout << "\n****test0b ()  // No vec. light is outside for loop, call by reference" << endl;

    Light light;
	for (int index = 0; index < NLights; index++)
	{
		InputLight (light);
	}

	cout << endl;
	return 0;


}


int test1 ()  // light is local to for loop
{
	cout << "\n****test1 ()  // light is local to for loop" << endl;

	vector<Light> lights;

	for (int index = 0; index < NLights; index++)
	{
	    Light light;
		InputLight (light);
		lights.push_back (light);
	}

	cout << endl;
	return 0;

}

int test2 ()  // light is outside for loop. InputLight (light);
{
    cout << "\n****test2 ()  // light is outside for loop" << endl;

	vector<Light> lights;
	Light light;

   	for (int index = 0; index < NLights; index++)
	{
	   InputLight (light);
		lights.push_back (light);
	}

	cout << endl;
	return 0;

}

int test3 () // light is outside for loop. light = InputLight ();
{
    cout << "\n****test3 () // light is outside for loop. light = InputLight ()" << endl;

	vector<Light> lights;
	Light light;

	for (int index = 0; index < NLights; index++)
	{
		light = InputLight (); // assignment
		lights.push_back (light);
	}

	cout << endl;
	return 0;

}

int test4 () // light is inside for loop. light = InputLight ();
{
    cout << "\n****test4 () // light is inside for loop. light = InputLight ()" << endl;
	vector<Light> lights;

	for (int index = 0; index < NLights; index++)
	{
        Light light;
		light = InputLight (); // assignment
		lights.push_back (light);
	}

	cout << endl;
	return 0;

}

int test5 () // light is inside for loop. Light light = InputLight (). initialisation
{
    cout << "\n****test5 () // light is inside for loop. Light light = InputLight (). initialisation" << endl;
	vector<Light> lights;

	for (int index = 0; index < NLights; index++)
	{
        Light light = InputLight (); // copy construction, not assignment

		lights.push_back (light);
	}

	cout << endl;
	return 0;

}

