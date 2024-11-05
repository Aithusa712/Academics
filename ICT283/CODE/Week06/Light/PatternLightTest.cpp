#include <iostream>
#include "PatternLight.h"

using std::cout;
using std::endl;

int main()
{
    PatternLight myPatternLight;
    myPatternLight.Switch();//turn on
    myPatternLight.SetColour("green");
    myPatternLight.SetRadius(15);
    myPatternLight.SetRadius(RIGHT_ARROW);
    cout << myPatternLight <<endl;
}