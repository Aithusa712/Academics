// Queue.h
//
// Queue class
//
// See actual code provided in the zip file
//-------------------------------------------

#ifndef MY_QUEUE
#define MY_QUEUE

//-------------------------------------------

#include <queue> // for the STL queue
#include <iostream>
using namespace std;

//-------------------------------------------


template <class T>
class Queue // minimal and complete
{
public:
	Queue () {};
	~Queue () {};
	bool Enqueue(const T &data);
	bool Dequeue (T &data);
	bool Empty () const {return m_queue.empty();}
private:
	queue<T> m_queue; // encapsulates STL queue
};


//-------------------------------------------
// It is a template, so we have to put all the code
//   in the header file
//-------------------------------------------

template<class DataType>
bool Queue<DataType>::Enqueue(const DataType &data)
{
	bool okay = true;
	try
	{
		m_queue.push(data); // calls STL queue method
	}
	catch (...)
	{
		okay = false;
	}

	return okay;
}

//-------------------------------------------

template<class DataType>
bool Queue<DataType>::Dequeue(DataType &data)
{
	if (m_queue.size() > 0)
	{
		data = m_queue.front();
		m_queue.pop();
		return true;
	}
	else
	{
		return false;
	}
}

//-------------------------------------------

#endif
