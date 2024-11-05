#include <iostream>
#include "Pointer.h"

using namespace std;

int main()
{
    Pointer pointer1;
    pointer1.Set(89);

    Pointer pointer2 = pointer1;
    Pointer pointer3(pointer1);
    cout << "Pointer 1: " << endl;
    cout << pointer1 << endl;

    cout << "Pointer 2:" << endl;
    cout << pointer2 << endl;

    cout << "Pointer 3: " << endl;
    cout << pointer3 << endl;
    return 0;
}
