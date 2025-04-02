#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>

/**
 * @brief Class that implements a simple map using std::map.
 *
 * @tparam K The type of keys in the map.
 * @tparam V The type of values associated with the keys.
 */
template <class K, class V> class Map {
public:
  /**
   * @brief Inserts a key-value pair into the map.
   *
   * @param key The key to insert.
   * @param value The value to associate with the key.
   */
  void Insert(const K &key, const V &value);

  /**
   * @brief Accesses the value associated with a given key.
   *
   * @param key The key whose value to access.
   * @return const V& A constant reference to the value associated with the key.
   */
  const V &operator[](const K &key) const;

  /**
   * @brief Clears all elements from the map.
   */
  void Clear();

  /**
   * @brief Gets the number of elements in the map.
   *
   * @return int The number of elements in the map.
   */
  int Size() const;

private:
  std::map<K, V> data;
};

/**
 * @brief Inserts a key-value pair into the map.
 */
template <typename K, typename V>
void Map<K, V>::Insert(const K &key, const V &value) {
  data[key] = value;
}

/**
 * @brief Accesses the value associated with a given key.
 */
template <typename K, typename V>
const V &Map<K, V>::operator[](const K &key) const {
  return data.at(key);
}

/**
 * @brief Gets the number of elements in the map.
 */
template <typename K, typename V> int Map<K, V>::Size() const {
  return data.size();
}

/**
 * @brief Clears all elements from the map.
 */
template <typename K, typename V> void Map<K, V>::Clear() { data.clear(); }


#endif
