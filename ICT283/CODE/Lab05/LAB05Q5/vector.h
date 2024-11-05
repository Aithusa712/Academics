#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
public:
    Vector();
    Vector(int n);
    ~Vector();

    int size() const;
    T& get(int index);
    T& get(int index) const;
    void push(const T& value);

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
void Vector<T>::push(const T& value)
{
    if (current == capacity)
    {
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] =arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }
    arr[current] = value;
    current++;
}

#endif // VECTOR_H
