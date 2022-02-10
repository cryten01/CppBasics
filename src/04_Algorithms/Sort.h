
#ifndef CPPBASICS_SORT_H
#define CPPBASICS_SORT_H

#include <vector>

// Comparison sorts

// Counting sort
std::vector<int> CountingSort(std::vector<int> vec, int size) {
    std::vector<int> result(size);

    // Loop through all elements
    for (int element : vec) {
        // Increase count at position: element
        result.at(element) += 1;
    }

    return result;
}

#endif //CPPBASICS_SORT_H
