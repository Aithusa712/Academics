// Shape.h
// An abstract base class for drawing shapes.
// Version
// 01 - Nicola Ritter
// 02 modified smr -
// to demonstrate dynamic polymorphism in C++
// Examine what is needed for this dynamic polymorphism to occur
// Use initilisation RAII principle
// Do not #include unnecessary files in the interface (.h) files
// Note advice about NOT having I/O in non-I/O specific classes.
// I/O  is application (MAIN) program's responsibility
// Main program is client program. The function main() is just one
//   of the functions in the Main program. main() is of course an
//   an important function as execution starts there.
// Identify all design issues and explain why these are issues
//-------------------------------------------------------------------

#ifndef SHAPE
#define SHAPE

#include <string>  // NEEDED HERE FOR Shape::m_description

//#include <iostream> // is iostream needed here on in shape.cpp?
// DO NOT #include unnecessary interface files/headers



using std::string; // exposing only what is needed.

//-------------------------------------------------------------------
const float ASPECT_RATIO = 12.0/8.0;

//-------------------------------------------------------------------

class Shape // abstract because of pure virtual methods
{
public:
	Shape(): m_height(0),m_description("ABSTRACT") {}// ALWAYS INITIALISE - See RAII
	virtual ~Shape () {};

		//For illustration only. Input is not normal behaviour for a Shape class, so having Input as a method stuffs up the OO design.
		// Set methods should be there instead.
		// Input method only to illustrate two virtual methods, one that is pure (=0) and the other that is not pure.
		// for polymorphism to occur, method needs to be virtual and the method needs to be accessed via a pointer ->
		// Input does not have =0 (not pure) so code body for Input is provided.
		virtual void Input ();

		//pure virtual. Pure (=0) means you can't create an object of Shape. There is no Shape::Draw() defined.
		//Virtual means that Draw can be polymorphic but needs to be accessed via the parent pointer, just like
		// Input() above.
		// See rule 90 in the Type Safety section of the reference  C++ Coding Standards
		// https://ebookcentral-proquest-com.libproxy.murdoch.edu.au/lib/murdoch/detail.action?docID=5135988
	virtual void Draw () const = 0;

protected:
	int m_height;
	string m_description;

};

//-------------------------------------------------------------------

#endif

