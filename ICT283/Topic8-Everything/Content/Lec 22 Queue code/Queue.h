// Queue.h

// doxygen comments are needed in this
// follow the style in modelfile.h for the class declaration.

//
// Queue class
// Version
// Nicola Ritter
// modified smr
// Encapsulates the STL queue, to provide a minimal and complete queue.
//-------------------------------------------

#ifndef MY_QUEUE
#define MY_QUEUE

//-------------------------------------------

#include <queue> // uses the STL queue
// #include <iostream> should this be included. If you do not need
//   do not include.
using namespace std;  // should everything in this namespace be exposed?
						// what would be a better way?

//-------------------------------------------

// This is a template class
// Keep the interface/specification part clean and un-cluttered
// Users should only see "what" the methods do in the interface.
// Doxygen comments to be added would show "what" the methods do, not "how".
// How the methods work would be in the code body below the class specs for
// template classes.

template <class T>
class Queue
{
public:
	Queue ();   // management method
	~Queue ();  // management method
	bool Enqueue(const T &data); // primary behaviour
	bool Dequeue (T &data);      // primary behaviour
	bool Empty ();              // query status
private:
	queue<T> m_queue;  // uses the STL queue internally
};

//-------------------------------------------
// It is a template, so we have to put all the code
//   in the header file
//-------------------------------------------

// Implementation part of the file contains code body.
// Use normal comments, not doxygen comments.

template<class T>
Queue<T>::Queue ()
{}

template<class T>
Queue<T>::~Queue ()
{}

template<class T>
bool Queue<T>::Empty()
{
	return m_queue.empty();
}

// just use T. everyone knows that it is a type parameter. the context is not ambiguous
// You will also come across the following where typename is used instead of class. That is ok too.
// template<typename T>
template<class T>
bool Queue<T>::Enqueue(const T &data)
{
	bool okay = true;
	try
	{
		m_queue.push(data);
	}
	catch (...)
	{
		okay = false;
	}

	return okay;
}

//-------------------------------------------

template<class T>
bool Queue<T>::Dequeue(T &data)
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
