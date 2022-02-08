
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

int Search::BinarySearch(OrderedArray *arrayPtr, int value) {
    int low = 0;
    int high = arrayPtr->getMNumElements() - 1;
    int current = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arrayPtr->operator[](mid) == value) {
            return mid;
        }
        if (arrayPtr->operator[](mid) < value) {
            low = mid + 1;
        } else {
            high = mid + 1;
        }
    }

    return -1;
}
