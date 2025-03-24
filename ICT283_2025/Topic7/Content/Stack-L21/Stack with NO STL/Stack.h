// This stuff belongs in Stack.h
// so doxygen comments are needed in here only for the interface part
// Stack class using raw array
//  smr
//-------------------------------------------

#ifndef ARR_STACK
#define ARR_STACK

//-------------------------------------------


// #include <iostream> Do not include unnecessary stuff
//using namespace std; Do not expose namespaces. Your client will not like this,
//  because you data structure exposes or includes something that they do not want.

// NO I/O HERE. LET THE CLIENT DEAL WITH I/O

// Rearrange the implementation so that it follows the same order as the interface

//-------------------------------------------

#include <cassert>

template <class T>
class Stack
{
public:

    // DATA STRUCTURE MANAGEMENT
    Stack (int n=100); // other approaches could be used. default size is 100. n must NOT be unsigned
    ~Stack (); // needed for pointer data. not needed if own Vector is used
    Stack(const Stack<T> & other); // needed for pointer data. not needed if own Vector is used
    const Stack<T> & operator=(const Stack<T> & other); // needed for ptr data. not needed if own Vector is used

    // DATA STRUCTURE BEHAVIOUR
    bool Push(const T &data);
    bool Pop (T &data);  // version from reference book Introduction to Algorithms by Cormen et al

    // DATA STRUCTURE STATUS QUERY
    bool Empty ();
    bool Full(); // accept although not minimal, can also be Private

private:
    T *dat; // raw array, but can use your own Vector.
                //If Vector used, destructor, op=, copy constructor not needed, so can be stubs.
    int max;  // max items
    int top; // for the current item // elements would be in index range 0..max-1

    void copyStack(const Stack& other);
};

// Doxygen comments only for the interface above. Normal comments for the implementation below.

//-------------------------------------------
// It is a template, so we have to put all the code
//   in the header file
// If Stack wasn't a template class, the following implementation code would go into Stack.cpp
//-------------------------------------------

// In implementation, can request the compiler to inline. BUT INTERFACE AND IMPLEMENTATION MUST BE SEPARATE

template<class T>
inline bool Stack<T>::Empty()
{
    return (top < 0);
}

template<class T>
inline bool Stack<T>::Full()
{
    return (top >= max-1); // elements would be in index range 0..max-1
}

template<class T>
Stack<T>::Stack(int n)
{
    assert (n>1); // stack of 1, client can use tmp var, 2 onwards ok. can throw exception instead

    max = n;
    top = -1; // element 0 would be a data item

    dat = new T[max];
    assert (dat != nullptr); // ALWAYS CHECK. can throw exception
}

template<class T>
Stack<T>::~Stack()  // MAKE SURE ALL DATA IS SET in destructor
{
    max = 0;
    top = -1; // element 0 would be a data item

    delete [] dat;
    dat = nullptr;

}

template<class T>
Stack<T>::Stack(const Stack<T> & other)
{
    copyStack(other);
}

template <class T>
const Stack<T>& Stack<T>::operator= (const Stack<T>& other)
{
    if (this != &other)  //avoid self-copy, wastes time and so not efficient
    {
        delete [] dat;  // IF NOT DELETED, MEMORY LEAK
        copyStack(other);
    }

    return *this;
}

template<class T>
bool Stack<T>::Push(const T &data)
{
    assert (dat != nullptr); // after explicit destruction, Push not permitted
                            // always check that all pre-conditions are valid before internal data is accessed

    bool okay = false; 

    if (Full())
    {
        okay = false; // accept other approaches where assert is used, or exception used
    }
    else
    {
        top++; // go to the next spot available
        dat[top] = data;
        okay = true;
    }

    return okay;
}


//-------------------------------------------

template<class T>
bool Stack<T>::Pop(T &data)
{
    assert (dat != nullptr); // after explicit destruction, Pop not permitted
                            // always check that all pre-conditions are valid before internal data is accessed

    bool okay = false;

    if (Empty())
    {
        okay = false;
    }
    else
    {
        data = dat[top];
        top--;
        okay =  true;
    }

    return okay;
}

template <class T>
void Stack<T>::copyStack (const Stack<T>& other)
{
    max = other.max;
    top = other.top;

    dat = new T[max];
    assert (dat != nullptr); // ALWAYS CHECK

    //copy other Stack into this Stack
    for (int i = 0; i <= top; i++)  // data is in index range 0..top
        dat[i] = other.dat[i];
}

//-------------------------------------------

#endif
