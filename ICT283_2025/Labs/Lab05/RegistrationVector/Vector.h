#ifndef VECTOR_H
#define VECTOR_H

// The class interface/declaration must have Doxygen comments – put these in
// Follow the style in modelfile.h

#include <stdexcept>
template <class T>
class Vector // This is NOT the std::vector.
{
public:
  Vector();
  Vector(const Vector<T> &t);
  Vector(int n); // done for you
  ~Vector();
  void push(T data);
  T& operator[](int index);
  const T& operator[](int index) const;
  Vector<T> &operator=(const Vector<T> &other);
  int size() const;

  // you fill in the rest and include Doxygen comments
  // make sure only method declarations are here, otherwise
  // no marks can be given.
  // So do not clutter the class declaration and keep the class
  // interface clean.
  // operator[] is required/mandatory
private:
  void Resize();
  T *arr;
  int current_size;
  int capacity;
}; // end of interface/declaration of the template class

template <typename T> Vector<T>::Vector() {
  arr = new T[1];
  capacity = 1;
  current_size = 0;
}

template <typename T> Vector<T>::Vector(const Vector<T> &other) {
  current_size = other.current_size;
  capacity = other.capacity;
  arr = new T[capacity];
  for (int index = 0; index < current_size; index++) {
    arr[index] = other.arr[index];
  }
}

template <typename T> Vector<T>::Vector(int n) {
  arr = new T[n];
  capacity = n;
  current_size = n;
  for(int i = 0; i < n; i++) {
        arr[i] = T();
    }
}

template <typename T> Vector<T>::~Vector() { delete[] arr; }

template <typename T> void Vector<T>::push(T data) {
  if (current_size == capacity) {
    Resize();
  }
  arr[current_size] = data;
  current_size++;
}
template <typename T> int Vector<T>::size() const { return current_size; }

template <typename T> void Vector<T>::Resize() {
  T *temp = new T[capacity * 2];

  for (int index = 0; index < capacity; index++) {
    temp[index] = arr[index];
  }

  delete[] arr;
  capacity *= 2;
  arr = temp;
}

template <typename T> T& Vector<T>::operator[](int index) {
  if (index >= current_size) {
    throw std::out_of_range("Index is out of bounds");
  }
  return arr[index];
}


template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index >= current_size) {
        throw std::out_of_range("Index is out of bounds");
    }
    return arr[index];
}

template <class T> Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
  if (this != &other) {
    delete[] arr;
    current_size = other.current_size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < current_size; i++) {
      arr[i] = other.arr[i];
    }
  }
  return *this;
}



#endif
