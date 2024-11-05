#define POINTER_H_INCLUDED
#include <iostream>
using namespace std;
class Pointer
{
public:
    Pointer();
    Pointer(const Pointer& otherPointer);   //Copy Constructor
    ~Pointer(){Clear();}
    void Clear();
    bool Set(int number);

    bool Copy(const Pointer& otherPointer);
    Pointer& operator=(const Pointer& otherPointer);    //Assignment Operator
    friend ostream& operator <<(ostream& ostr, const Pointer& pointer);

private:
    int *m_ptr;

};
