// Realisations.cpp
// Version
// Original by Nicola Ritter
//      Refactored into smaller functions that will fit into
//        powerpoint.
// modified smr - demonstrates POLYMORPHISM in C++
//-------------------------------------------------------------------

// #include your own class interfaces first


// the parent class
#include "Shape.h"

// the children of Shape
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

// Then #include the system/lib files

#include <vector> // the STL vector (NOT your Assignment Vector)
// replace it with your own Vector to see.
// some code changes needed as your own Vector should not be the everything and the kitchen
// sink, that the STL vector is.

#include <cstring> // where is this needed?




using namespace std;

//-------------------------------------------------------------------

typedef Shape *ShapePtr;
typedef vector<ShapePtr> ShapeVec; // ShapeVec is now a vector of Shape pointers. Shape is the parent class
                                   // so ShapeVec is now a vector of parent class pointers - one of the conditions needed for polymorphism



//------Forward declarations--------------------------------

void Draw (const ShapeVec &array);
void Input (ShapeVec &array);
char Menu ();
Shape *GetShape (char ch);

//-----------------------------------------------------------

int main()
{
	ShapeVec array;

	Input (array); // not a method, just a normal procedure
	Draw (array); // not a method, just a normal procedure

	cout << endl;
	return 0;
}

//-------------------------------------------------------------------

// Work out how this routine runs.
// Shapes are created until quit. Then data is input into the shapes.
void Input (ShapeVec &array)
{
	char ch = Menu(); // uppercase returned, makes checking easy
	while (ch != 'Q')
	{
		ShapePtr shape = GetShape (ch);
		array.push_back(shape); // array is a Vec of base class shape pointers, so it can store pointers to the children.

		ch = Menu();
	}
    // See lecture notes 16 - polymorphism conditions
	for (unsigned index = 0; index < array.size(); index++)
	{
		array[index]->Input(); // correct input called by polymorphism: accessed by the parent (Shape) pointer ->
                               // and Input is declared virtual in the parent class Shape
	}
	cout << endl;
}

//-------------------------------------------------------------------

char Menu ()
{
	string str;
	do
	{
		cout << "S - Square" << endl;
		cout << "T - Triangle" << endl;
		cout << "R - Rectangle" << endl;
		cout << "Q - Quit entry and draw selected shape" << endl;
		cin >> str;
	} while (strchr("STRQstrq",str[0]) == NULL); // strchr from cstring

	return toupper(str[0]);
}

//-------------------------------------------------------------------

ShapePtr GetShape (char ch)
{
	ShapePtr shape = NULL; // shape is a parent (Shape pointer) so it can point to child objects
	switch (ch)
	{
		case 'S':
			shape = new Square;   // parent pointer can point to child objects - will be used for polymorphism
			break;
		case 'T':
			shape = new Triangle; // as above
			break;
		case 'R':
			shape = new Rectangle; // as above
			break;
		}   // there is no default provided. so precondition has to be asserted.
            // how would you do this assertion? See compiler warning.

	return shape;
}

//-------------------------------------------------------------------

void Draw (const ShapeVec &array)   // note that Shape is the base (parent) class
                                    // array will contain parent pointers to child objects
{
	for (unsigned index = 0; index < array.size(); index++)
	{
		array[index]->Draw(); // need to access via the pointer for polymorphism AND
                              // Draw needs to be declared virtual in the parent class.
                              // array[index] is a parent (Shape) pointer point to a child object.
                              // by using ->Draw(), polymorhism will occur as Draw has been declared
                              // virtual in the parent and the child has its own Draw() routine. The child's
                              // Draw() will be called. Same reasoning as the Input method being used above.

	}
	cout << endl;
}

//-------------------------------------------------------------------
