#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
public:
    Vector();
    ~Vector();

    int size() const;
    T& at(int index);
    const T& at(int index) const;
    void push_back(const T& value);

private:
    T* arr;
    int capacity;
    int current_size;

    void resize();
};

template <class T>
Vector<T>::Vector()
{
    capacity = 1;
    current_size = 0;
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
    return current_size;
}

template <class T>
T& Vector<T>::at(int index)
{
    return arr[index];
}

template <class T>
const T& Vector<T>::at(int index) const
{
    return arr[index];
}

template <class T>
void Vector<T>::push_back(const T& value)
{
    if (current_size == capacity)
    {
        resize();
    }
    arr[current_size] = value;
    current_size++;
}

template <class T>
void Vector<T>::resize()
{
    int new_capacity = capacity * 2;
    T* new_arr = new T[new_capacity];
    for (int i = 0; i < current_size; ++i)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}

#endif // VECTOR_H
