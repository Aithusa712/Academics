#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
    Vector();
    Vector(int n);
    Vector (Vector const &vec);

    ~Vector();

    int size() const;
    T& get(int index);
    T& get(int index) const;
    void add(const T& value);
    void resize();
    void print();
   
private:
    T* arr;
    int capacity;
    int current;
};

template <class T>
Vector<T>::Vector()
{
    capacity = 1;
    current = 0;
    arr = new T[capacity];
}

template <class T>
Vector<T>::Vector(int n)
{
    capacity = n;
    current = 0;
    arr = new T[capacity];
}
template <class T>
Vector<T>::Vector(const Vector& vec){
    current = vec.current;
    capacity = vec.capacity;
    arr = new T[capacity];
    for(int i = 0; i<current; i++)
    {
        arr[i]=vec.arr[i];   
    }
    cout << "Copy Const called" << endl; 
}

template <class T>
Vector<T>::~Vector()
{
    delete[] arr;
}

template <class T>
int Vector<T>::size() const
{
    return current;
}

template <class T>
T& Vector<T>::get(int index)
{
    return arr[index];
}

template <class T>
T& Vector<T>::get(int index) const
{
    return arr[index];
}



template <class T>
void Vector<T>::add(const T& value)
{
    if (current == capacity)
    {
        resize();
    }
    arr[current] = value;
    current++;
}

template<class T>
void Vector<T>::resize()
{
    T* arrTemp = new T[capacity*2];
        for (int i = 0; i < current; i++)
        {
            arrTemp[i] =arr[i];
        }
        capacity *= 2;
        delete[] arr;
        arr = arrTemp;
   

}

template <class T>
void Vector<T>::print()
{
    for (int i = 0; i<current; i++)
    {
        cout << arr[i] << endl;
    }
}



#endif // VECTOR_H
