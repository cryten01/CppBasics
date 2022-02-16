
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

    // Loop through all items except list
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

/**
 * Helper function for insertion sort.
 * @param array
 * @param left
 * @param mid
 * @param right
 */
void Merge(std::vector<int> &array, int left, int mid, int right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto subOne = 0;    // Initial index of list sub-array
    auto subTwo = 0;    // Initial index of second sub-array
    int merged = left;  // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (subOne < subArrayOne && subTwo < subArrayTwo) {
        if (leftArray[subOne] <= rightArray[subTwo]) {
            array[merged] = leftArray[subOne];
            subOne++;
        } else {
            array[merged] = rightArray[subTwo];
            subTwo++;
        }
        merged++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (subOne < subArrayOne) {
        array[merged] = leftArray[subOne];
        subOne++;
        merged++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (subTwo < subArrayTwo) {
        array[merged] = rightArray[subTwo];
        subTwo++;
        merged++;
    }
}

/**
 * Uses divide and conquer.
 * @param array
 */
void MergeSort(std::vector<int> &array, int begin, int end) {
    // Exit condition (Only 1 or less elements)
    if (begin >= end) return;

    // Define mid
    auto mid = begin + (end - begin) / 2;

    // Left partition
    MergeSort(array, begin, mid);
    // Right partition
    MergeSort(array, mid + 1, end);
    // Once splitted, merge
    Merge(array, begin, mid, end);
}

/**
 *
 * @param vec
 * @param size
 * @return
 */
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
