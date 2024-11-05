
#ifndef MY_QUEUE
#define MY_QUEUE

//-------------------------------------------

#include <queue> // uses the STL queue
// #include <iostream> should this be included. If you do not need
//   do not include.
using namespace std;  // should everything in this namespace be exposed?
						// what would be a better way?

//-------------------------------------------

int CAPACITY 6;

template <class T>
class Queue
{
public:
	Queue ();   // management method
	~Queue ();  // management method
	bool Enqueue(const T &data); // primary behaviour
	bool Dequeue (T &data);      // primary behaviour
	bool Empty ();              // query status
	bool Full();
private:
	int m_size;
	int m_front;
	int m_back;
	T m_queue[CAPACITY];
};

template<class T>
Queue<T>::Queue ()
{
    m_size = 0;
    m_front = -1;
    m_back = -1;
}

template<class T>
Queue<T>::~Queue ()
{}

template<class T>
bool Queue<T>::Empty()
{
	return m_size == 0;
}

template<class T>
bool Queue<T>::Empty()
{
	return m_size == CAPACITY;
}

template<class T>
bool Queue<T>::Enqueue(const T &data)
{
    if(Full())  //If Queue is full
    {
        return false;
    }
    else
    {
        if(Empty()) //If queue is initially empty
        {
            m_front = 0;
        }
        m_size++;
        m_back++;
        m_back = m_back % CAPACITY;
        m_queue[m_back] = data;
        return true;
    }
}

//-------------------------------------------

template<class T>
bool Queue<T>::Dequeue(T &data)
{
    if (Empty())
    {
        return false;
    }
    else
    {
        data = m_queue[m_front];
        m_front++;
        m_front = m_front % CAPACITY;
        m_size--;
        if(Empty())
        {
            m_front = -1;
            m_back = -1;
        }
        return true;

    }
}

//-------------------------------------------

#endif
