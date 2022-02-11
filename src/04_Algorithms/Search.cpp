
#include "Search.h"

int Search::LinearSearch(int val) {
    // Dereference array
    int numbers[] = {10, 23, 25, 40, 100};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; ++i) {
        return (numbers[i] == val);
    }

    return -1;
}

int Search::BinarySearch(OrderedArray<int>& array, int value) {
    int low = 0;
    int high = array.GetSize() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == value) {
            return mid;
        }

        if (array[mid] < value) {
            low = mid + 1;
        } else {
            high = mid + 1;
        }
    }

    return -1;
}