
#ifndef CPPBASICS_SORT_H
#define CPPBASICS_SORT_H

#include <vector>

// Comparison sorts

void BubbleSort(std::vector<int> &array) {
    // Determines the number of passes
    for (int i = 0; i < array.size() - 1; i++) {
        // Compare item against all non-sorted items
        for (int j = 0; j < array.size() - i - 1; j++) {
            // Swap items if current element is bigger than next (bubble up)
            if (array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void SelectionSort(std::vector<int> &array) {
    int temp;
    int min = 0;

    for (int k = 0; k < array.size() - 1; k++) {
        // Set min
        min = k;

        // Check for new min
        for (int i = k + 1; i < array.size(); i++) {
            if (array[i] < array[min]) {
                min = i;
            }
        }

        // Swap elements if element at min pos is smaller
        if (array[k] > array[min]) {
            temp = array[k];
            array[k] = array[min];
            array[min] = temp;
        }
    }
}

void InsertionSort(std::vector<int> &array) {
    int temp;
    int i = 0;

    // Loop through all items except first
    for (int k = 1; k < array.size(); k++) {
        temp = array[k];
        i = k;

        // Loop down from k
        while (i > 0 && array[i - 1] >= temp) {
            array[i] = array[i - 1];
            i--;
        }

        array[i] = temp;
    }
}

// Counting sorts

std::vector<int> CountingSort(std::vector<int> vec, int size) {
    std::vector<int> frequency(size);

    // Loop through all elements
    for (int element: vec) {
        // Increase count at position: element
        frequency.at(element) += 1;
    }

    return frequency;
}

#endif //CPPBASICS_SORT_H
