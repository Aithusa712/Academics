#ifndef VECTOR_H
#define VECTOR_H

// The class interface/declaration must have Doxygen comments – put these in
// Follow the style in modelfile.h

#include <cassert>
/**
 * @brief A custom vector class template implementation
 * @tparam T The type of elements stored in the vector
 */
template <class T>
class Vector // This is NOT the std::vector.
{
public:
  /**
   * @brief Default constructor
   */
  Vector();

  /**
   * @brief Copy constructor
   * @param t Vector to copy from
   */
  Vector(const Vector<T> &t);

  /**
   * @brief Constructor with initial size
   * @param n Initial size of the vector
   */
  Vector(int n); // done for you

  /**
   * @brief Destructor
   */
  ~Vector();

  /**
   * @brief Adds an element to the end of the vector
   * @param data Element to be added
   */
  void push(T data);

  /**
   * @brief Access operator for modifiable elements
   * @param index Position of the element to access
   * @return Reference to the element at specified index
   * @throw std::out_of_range if index is invalid
   */
  T &operator[](int index);

  /**
   * @brief Access operator for const elements
   * @param index Position of the element to access
   * @return Const reference to the element at specified index
   * @throw std::out_of_range if index is invalid
   */
  const T &operator[](int index) const;

  /**
   * @brief Assignment operator
   * @param other Vector to copy from
   * @return Reference to this vector
   */
  Vector<T> &operator=(const Vector<T> &other);

  /**
   * @brief Gets the current size of the vector
   * @return Number of elements in the vector
   */
  int size() const;

  /**
   * @brief Removes all elements from the vector
   */
  void Clear();

private:
  /**
   * @brief Increases the capacity of the internal array
   */
  void Resize();

  T *arr;           ///< Pointer to the dynamic array
  int current_size; ///< Current number of elements
  int capacity;     ///< Current capacity of the array
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
  for (int i = 0; i < n; i++) {
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

template <typename T> T &Vector<T>::operator[](int index) {
  assert(index < current_size && "Index is out of bounds");
  return arr[index];
}

template <typename T> const T &Vector<T>::operator[](int index) const {
  assert(index < current_size && "Index is out of bounds");
  return arr[index];
}

template <typename T> Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
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
template <typename T> void Vector<T>::Clear() {
  delete[] arr;
  arr = new T[1];
  capacity = 1;
  current_size = 0;
}

#endif
