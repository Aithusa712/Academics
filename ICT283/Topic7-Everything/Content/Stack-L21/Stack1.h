
//-------------------------------------------

#ifndef STACK1_H
#define STACK1_H

//-------------------------------------------


#include <stack> // Our Stack uses the STL stack. Encapsulates the STL stack.

const int CAPACITY =5;
template <class T>
class Stack
{
public:
	Stack ();
	~Stack () {};
	bool Push(const T &data);
	bool Pop (T &data);  // version from reference book Introduction to Algorithms by Cormen et al
	bool Empty ();
	bool Full();
private:
    T m_stack[CAPACITY];
    int m_top;
};

//-------------------------------------------
template<class T>
Stack<T>::Stack()
{
    m_top = -1;
}


template<class T>
bool Stack<T>::Empty()
{
    return m_top==-1;
}

template<class T>
bool Stack<T>::Full()
{
    return m_top==CAPACITY-1;
}


template<class T>
bool Stack<T>::Push(const T &data)
{
    if (Full())
    {
        return false;
    }
    else
    {
        m_top++;
        m_stack[m_top] = data;
        return true;
    }
}

//-------------------------------------------

template<class T>
bool Stack<T>::Pop(T &data)
{
    if(Empty())
    {
        return false;
    }
    else
    {
        data = m_stack[m_top];
        m_top--;
        return true;
    }
}

//-------------------------------------------

#endif
