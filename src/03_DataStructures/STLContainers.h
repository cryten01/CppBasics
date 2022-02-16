
#ifndef CPPBASICS_CONTAINER_H
#define CPPBASICS_CONTAINER_H

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <unordered_map>

// A list of the most important containers in the STL library

/**
 * Represents a fixed sized array
 */
void ShowArray() {
    std::array<int, 10> array;
}

/**
 * Iterates over vector and prints its values.
 * @param vector the vector to be iterated upon.
 */
void PrintVector(std::vector<int>& vector) {
    // Classic way
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    // Range based for loop
    for (int& value: vector) {
        std::cout << value << " ";
    }
    // Iterator
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << " ";
    }
}

/**
 * Represents a resizable dynamic array
 */
void ShowVector() {
    std::vector<int> vector;
    // Optimization 1: Avoid reallocation by allocating memory for 3 integers before;
    vector.reserve(3);

    // TODO: Modifiers
    // Optimization 2: Use emplace_back and not push_back to directly construct variable in the memory and not in the function
    vector.emplace_back(1);
    vector.emplace_back(2);
    vector.emplace_back(3);

    vector.erase(vector.begin() + 1);

    PrintVector(vector);

    // TODO: Capacity
    // TODO: Access
}

/**
 * Represents a doubly linked list
 */
void ShowLinkedList() {
    std::list<int> list;

    // Initializes list
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }

    // Iterate over list
    for (std::list<int>::iterator i = list.begin(); i != list.end(); i++) {
        // Prints value that i is pointing to
        std::cout << *i << std::endl;
    }
}

template<typename T>
void PrintHashMap(T &map) {
    for (std::pair<int, std::string> element: map) {
        std::cout << element.first << " " << element.second << std::endl;
    }
}

void ShowHashMap() {
    // Initializes an empty hashmap with key value pairs
    std::unordered_map<int, std::string> hashmap;

    // No second insertion possible
    hashmap.insert(std::make_pair<int, std::string>(10, "Cat"));
    hashmap.insert(std::make_pair<int, std::string>(10, "Eagle"));

    // TODO: iterate
    // Use using for simplifying type names
    using playermap = std::unordered_map<int, std::string>;

    // Range based for loop approach
    for (std::pair<int, std::string> keyValue : hashmap) {
        std::cout << keyValue.first << " " << keyValue.second << std::endl;
    }

    // Iterator approach (only way for unordered non index based systems)
    for (playermap::const_iterator it = hashmap.begin(); it != hashmap.end(); it++) {
        auto &key = it->first;
        auto &value = it->second;

        std::cout << key << " " << value << std::endl;
    }

    // C++ 17: structured bindings
    for (auto [key, value] : hashmap) {
        std::cout << key << " " << value << std::endl;
    }

    // Finds an entry
    PrintHashMap(hashmap);

    // Deletes an entry
    hashmap.erase(10);
}

/**
 * Multi-maps allow for duplicate key-value pairs
 */
void ShowHashMultiMap() {
    // Initialize new hash multimap with key value pairs
    std::unordered_multimap<int, std::string> hash_multimap;

    // Can have duplicate key value pairs
    hash_multimap.insert(std::make_pair(1, "Bird"));
    hash_multimap.insert(std::make_pair(1, "Bird"));

    PrintHashMap(hash_multimap);
}

#endif //CPPBASICS_CONTAINER_H
