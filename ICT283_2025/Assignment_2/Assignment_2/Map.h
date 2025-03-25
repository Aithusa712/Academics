#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>

template <typename K, typename V>
class Map {
public:
    void Insert(const K &key, const V &value);
    V &operator[](const K &key);
    const V &operator[](const K &key) const;
    V *find(const K &targetKey) const;
    Map &operator=(const Map<K, V> &other);
    void Clear();
    int Size() const;

private:
    std::map<K, V> data;
};

template <typename K, typename V>
void Map<K, V>::Insert(const K &key, const V &value) {
    data[key] = value; // Use operator[] for insertion
}

template <typename K, typename V>
V &Map<K, V>::operator[](const K &key) {
    return data[key]; // Non-const version for modifying/inserting
}

template <typename K, typename V>
const V &Map<K, V>::operator[](const K &key) const {
    return data.at(key); // Use at() for const version, throws if key is missing
}

template <typename K, typename V>
V *Map<K, V>::find(const K &targetKey) const {
    auto it = data.find(targetKey);
    if (it != data.end()) {
        return &(it->second);
    }
    return nullptr;
}

template <typename K, typename V>
Map<K, V> &Map<K, V>::operator=(const Map<K, V> &other) {
    if (this != &other) {
        data = other.data; // Use map's assignment operator
    }
    return *this;
}

template <typename K, typename V>
int Map<K, V>::Size() const {
    return data.size();
}

template <typename K, typename V>
void Map<K, V>::Clear() {
    data.clear();
}

#endif
