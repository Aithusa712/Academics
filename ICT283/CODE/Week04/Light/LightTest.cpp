#include <iostream>
#include "Light.h"

using namespace std;


void Test1(Light& light);
void Test2(Light& light);
void Test3(Light& light);
void Test4(Light& light);

int main()
{
    cout << "Light Test" << endl;
    Light light;
    Test1(light);
    Test2(light);
    Test3(light);
    Test4(light);

    return 0;
}


void Test1(Light& light)
{
    
    cout << "== Test 1 (Construction) == " << endl;
    cout << light <<endl;
    cout <<endl;
}


void Test2(Light& light)
{
 
    cout << "== Test 2 (SetColour(\"red\")) == " << endl;
    cout << light <<endl;
    cout <<endl;
}


void Test3(Light& light)
{
 
    cout << "== Test 3 (SetRadius(-9.3)) == " << endl;
     if(!light.SetRadius(-9.3))
     {
        cout << "Radius must be > 0" << endl;
     }
    cout << light <<endl;
    cout <<endl;

}


void Test4(Light& light)
{
    cout << "== Test 4 (SetRadius(+9.3)) == " << endl;
     if(!light.SetRadius(+9.3))
     {
        cout << "Radius must be > 0" << endl;
     }
    cout << light <<endl;
    cout <<endl;
}