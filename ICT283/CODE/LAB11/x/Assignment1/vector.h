#ifndef VECTOR_H
#define VECTOR_H

/**
 * \file Vector.h
 * \brief Header file for the Vector class template
 */


/**
 * \class Vector
 * \brief Vector is a dynamic resizable array.
 */
template <class T>
class Vector
{
public:
    /**
    * @brief  Default Constructor
    */
    Vector();
    /**
    * @brief  Default Constructor with initial capacity
    * @param n - initial capacity of the vector
    */
    Vector(int n);
    /**
    * @brief  Deconstructor
    */
    ~Vector();
    /**
    * @brief Returns the number of elements in the vector
    * @return current size of the vector
    */
    int size() const;
    /**
    * @brief Retrieves the current element specified by the parameter index
    * @return data stored in the element specified by the parameter
    */
    T& get(int index);
    /**
    * @brief get function with const implementation
    * @return const data stored in the element specified by the parameter
    */
    T& get(int index) const;
    /**
    * @brief Add another element into the end of the vector
    */
    void push(const T& value);

private:
    ///
    T* arr;
    ///capacity of elements in the vector
    int capacity;
    ///cuurent elements in the vector
    int current;
};


/**
 * @brief  Default Constructor
 */
template <class T>
Vector<T>::Vector()
{
    capacity = 1;
    current = 0;
    arr = new T[capacity];
}

/**
 * @brief Default Constructor with initial capacity.
 * @param n initial capacity.
 */

template <class T>
Vector<T>::Vector(int n)
{
    capacity = n;
    current = 0;
    arr = new T[capacity];
}

/**
 * @brief Destructor that deletes the array to clean up memory.
 */

template <class T>
Vector<T>::~Vector()
{
    delete[] arr;
}

/**
 * @brief Returns the number of elements in the vector
 * @return current size of the vector
 */
template <class T>
int Vector<T>::size() const
{
    return current;
}

/**
 * @brief Retrieves the current element specified by the parameter index
 * @return data stored in the element specified by the parameter
 */
template <class T>
T& Vector<T>::get(int index)
{
    return arr[index];
}

/**
 * @brief get function with const implementation
 * @return const data stored in the element specified by the parameter
 */
template <class T>
T& Vector<T>::get(int index) const
{
    return arr[index];
}


/**
 * @brief Add another element into the end of the vector
 */
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
