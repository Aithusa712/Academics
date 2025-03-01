#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

/**
 * @class Vector
 * @brief A dynamic array implementation that grows automatically
 *
 * This template class provides a resizable array (vector) implementation
 * that automatically manages memory allocation and deallocation.
 * The vector grows dynamically when elements are added, doubling its
 * capacity when needed.
 *
 * @author Kim Andrew Dela Cruz
 * @version 01
 * @date 16/02/2025 Kim Andrew Dela Cruz
 */
template <class T> class Vector {
public:
  /**
   * @brief Default constructor
   *
   * Initializes an empty vector with default capacity.
   * Sets current_size to 0 and allocates initial memory.
   */
  Vector();

  /**
   * @brief Copy constructor
   *
   * Creates a deep copy of the provided vector.
   *
   * @param t Reference to the vector to be copied
   */
  Vector(const Vector<T> &t);

  /**
   * @brief Parameterized constructor
   *
   * Creates a vector with initial capacity of n.
   *
   * @param n Initial capacity of the vector
   */
  Vector(int n); // done for you

  /**
   * @brief Destructor
   *
   * Deallocates all memory used by the vector.
   */
  ~Vector();

  /**
   * @brief Adds an element to the end of the vector
   *
   * Automatically resizes the vector if necessary before adding the element.
   *
   * @param data Element to be added to the vector
   */
  void push(T data);

  /**
   * @brief Array subscript operator
   *
   * Provides access to elements at specified index.
   *
   * @param index Position of the element to access
   * @return Reference to the element at specified index
   */
  T &operator[](int index);

  /**
   * @brief Const array subscript operator
   *
   * Provides read-only access to elements at specified index.
   *
   * @param index Position of the element to access
   * @return Const reference to the element at specified index
   */
  const T &operator[](int index) const;

  /**
   * @brief Returns the current number of elements
   *
   * @return Current size of the vector
   */
  int size() const;

  /**
   * @brief Removes all elements from the vector
   *
   * Resets the vector to its initial empty state.
   */
  void Clear();

private:
  /**
   * @brief Doubles the capacity of the vector
   *
   * Called automatically when more space is needed.
   */
  void Resize();

  T *arr;           ///< Dynamic array holding the elements
  int current_size; ///< Number of elements currently in the vector
  int capacity;     ///< Total capacity of the allocated memory
};

/*######################################################################*/
/*++++++++++++++++++++++++++++IMPLEMENTATION++++++++++++++++++++++++++++*/
/*######################################################################*/

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

template <typename T> void Vector<T>::Clear() {
  delete[] arr;
  arr = new T[1];
  capacity = 1;
  current_size = 0;
}

#endif
