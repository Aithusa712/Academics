#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
using std::cout;
using std::endl;

int main ()
{
    Square mySquare;
    //cout  << mySquare.area() << endl;
    Square mySquare2;
    mySquare2.SetHeight(7);
    //cout <<mySquare2.area() << endl;
    //Rectangle myRectangle;
    //cout <<myRectangle.area() << endl;
    Rectangle myRectangle2;
    myRectangle2.SetHeight(10);
    myRectangle2.SetLength(7);
    //cout << myRectangle2.area() <<endl;

    Shape *shapePtr;
    shapePtr = &mySquare;
    cout << "shapePtr->area() mySquare.area(): " << shapePtr->area() << endl;
    
    shapePtr = &mySquare2;
    cout << "shapePtr->area() mySquare.area(): " << shapePtr->area() << endl;
    
    shapePtr = &myRectangle2;
    cout << "shapePtr->area() mySquare.area(): " << shapePtr->area() << endl;

    shapePtr = new Rectangle();
    cout << "shapePtr->area() mySquare.area(): " << shapePtr->area() << endl;

    
    return 0;
}