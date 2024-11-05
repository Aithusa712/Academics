#include "Pointer.h"

Pointer::Pointer()
{
    m_ptr = nullptr;
}

void Pointer::Clear()
{
    if(m_ptr != nullptr)
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
}

Pointer::Pointer(const Pointer& otherPointer)
{
    m_ptr = nullptr;    //initialize first
    Copy(otherPointer);


}

bool Pointer::Copy(const Pointer& otherPointer)
{
    // 1. Ensure that otherPointer is not null
    if(otherPointer.m_ptr != nullptr)
    {
        // 2. Get memory from the heap
        if(m_ptr== nullptr)
        {

        }
        m_ptr = new int;    //attempt to get memory from the heap (not guaranteed)
        // 3. Copy value from other Pointer to our own memory
        if(m_ptr != nullptr)
        {
        *m_ptr = *(otherPointer.m_ptr);
        return true;
        }
    }
    return false;


}

Pointer& Pointer::operator=(const Pointer& otherPointer)
{
    Copy(otherPointer);
    return *this;
}

bool Pointer::Set(int number)
{
    if(m_ptr == nullptr)
    {
        m_ptr = new int;
    }

    if(m_ptr != nullptr)
    {
        return true;
    }
    return false;


}

ostream& operator <<(ostream& ostr, const Pointer& pointer)
    {
        ostr << "Addr of m_ptr      : " << &(pointer.m_ptr) << '\n'
             << "Contents of m_ptr  : " << pointer.m_ptr << '\n'
             << "Contents of *m_ptr : " << *(pointer.m_ptr) << '\n';
        return ostr;
    }
