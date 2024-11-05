// Constructors

// uncomment one main() at a time and run

// Run the program to see how many constructions happen.
// Update the construction count shown in comments using actual results.

#include "Light.h"

#include <vector> // The STL vector - cannot be used in Assignment 1

using namespace std;


///* ?? constructions
Light InputLight ()
{
	Light light;

	float radius;
	// interactive input commented out so that counters can be shown
	//cout << "Enter radius of light in centimeters: ";
	//cin >> radius;
	light.Set(30);

	string colour;
//	cout << "Enter colour of light: ";
	//cin >> colour;
	light.Set ("red");

	return light;
}

int main ()
{
	//vector<Light> lights;
	//Light light;
	for (int index = 0; index < 10; index++)
	{
		Light light;
		//light = InputLight ();
		//cout << light << endl;
		//cout << InputLight () << endl;
//		lights.push_back (light);
	}

	cout << endl;
	return 0;

}
//*/


//void InputLight (Light &light)
//{
//	static int counter = 0;
//	cout << "Input " << ++counter << endl;
//}
//
//int main ()
//{
//	vector<Light> lights;
//	Light light;
//	for (int index = 0; index < 50; index++)
//	{
//		InputLight (light);
//		lights.push_back (light);
//	}
//
//	cout << endl;
//	return 0;
//
//}

/* ?? constructions
void InputLight (Light &light)
{
	float radius;
	cout << "Enter radius of light in centimeters: ";
	cin >> radius;
	light.Set(radius);

	string colour;
	cout << "Enter colour of light: ";
	cin >> colour;
	light.Set (colour);

}

int main ()
{
	vector<Light> lights;
	Light light;
	for (int index = 0; index < 10; index++)
	{
		InputLight (light);
		lights.push_back (light);
	}

	cout << endl;
	return 0;

}
*/

/*  construction
void InputLight (Light &light)
{
	float radius;
	cout << "Enter radius of light in centimeters: ";
	cin >> radius;
	light.Set(radius);

	string colour;
	cout << "Enter colour of light: ";
	cin >> colour;
	light.Set (colour);

}

int main ()
{
	vector<Light> lights;
	Light light;
	for (int index = 0; index < 10; index++)
	{
		InputLight (light);
//		lights.push_back (light);
	}

	cout << endl;
	return 0;

}
*/

/* ?? constructions
Light InputLight ()
{
	Light light;

	float radius;
	cout << "Enter radius of light in centimeters: ";
	cin >> radius;
	light.Set(radius);

	string colour;
	cout << "Enter colour of light: ";
	cin >> colour;
	light.Set (colour);

	return light;
}

int main ()
{
	vector<Light> lights;
	Light light;
	for (int index = 0; index < 10; index++)
	{
		light = InputLight ();
//		lights.push_back (light);
	}

	cout << endl;
	return 0;

}
*/



/* ?? constructions
Light InputLight ()
{
	Light light;

	float radius;
	cout << "Enter radius of light in centimeters: ";
	cin >> radius;
	light.Set(radius);

	string colour;
	cout << "Enter colour of light: ";
	cin >> colour;
	light.Set (colour);

	return light;
}

int main ()
{
	vector<Light> lights;
	for (int index = 0; index < 10; index++)
	{
		Light light;
		light = InputLight ();
		lights.push_back (light);
	}

	cout << endl;
	return 0;

}
*/
