#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	Queue(Queue& t);
	bool Enqueue(const T& data);
	bool Dequeue(T& data);
	bool Empty() const;
private:
	Queue<T>m_queue;
	T* m_array;
	int m_size;
	int m_arraySize;
	int m_front;
	int m_back;
};

template <typename T>
Queue<T>::Queue()
{
	m_size = 0;
	m_arraySize = 1;
	T* m_array = new T[m_arraySize];
	m_front = 0;
	m_back = 0;
}

template <typename T>
Queue<T>::~Queue()
{

}

template <typename T>
Queue<T>::Queue(Queue& t)
{
	
}

template <typename T>
bool Queue<T>::Enqueue(const T& data)
{
	if (m_size >= m_arraySize)
	{
		T* arrTemp = new T[m_arraySize*2];
        	for (int i = 0; i < m_size; i++)
        	{
            		arrTemp[i] =m_array[i];
        	}
        	m_arraySize *= 2;
        	delete[] m_array;
        	m_array = arrTemp;
   
		return false;
	}
	else 	
	{
		if(m_size==0)
		{
		m_front = 0;
		}
		m_size++;
		m_back = (m_back+1)%m_arraySize;
		m_array[m_back] = data;
		return true;
	}

}
template <typename T>
bool Queue<T>::Dequeue(T& data)
{
	if(m_size == 0 )
	{
		return false;
	}
	else
	{
		data = m_array[m_front];
		m_front =(m_front+1)%m_arraySize;
		m_size--;
		if(m_size==0)
		{
			m_front = -1;
			m_back = -1;
		}
		return true;
	}
}

template <typename T>
bool Queue<T>::Empty() const
{
	if(m_size==0)
	{
		return true;
	}
	else
	{
		return false;	
	}
}
