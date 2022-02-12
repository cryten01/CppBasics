
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

int Search::BinarySearch(OrderedArray<int> &array, int value) {
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
            high = mid - 1;
        }
    }

    return -1;
}

/**
 * Two pointer technique based solution to find
 * if there is a pair in A[0..N-1] with a given sum.
 * @param array the array to search.
 * @param target the target pair sum to find.
 * @return 1 if pair sum exists, otherwise 1.
 */
int Search::TwoPointerSearch(std::vector<int> &array, int target) {
    int size = array.size();

    // Represents first pointer
    int i = 0;

    // Represents second pointer
    int j = size - 1;

    while (i < j) {
        // If we find a pair
        if (array[i] + array[j] == target) {
            return 1;
        }
        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (array[i] + array[j] < target) {
            i++;
        }
        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing j--
        else {
            j--;
        }
    }

    return 0;
}
