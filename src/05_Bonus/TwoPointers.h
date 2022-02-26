
#ifndef CPPBASICS_TWOPOINTERS_H
#define CPPBASICS_TWOPOINTERS_H

#include <vector>
#include <unordered_map>

/**
 * 977. Squares of a Sorted Array
 * @param nums the array that needs to be squared and sorted.
 * @return the sorted dynamic array containing the squared numbers in ascending order.
 */
std::vector<int> sortedSquares(std::vector<int> &nums) {
    // Create empty array with n slots other wise no [] operator possible
    std::vector<int> result(nums.size());

    int first = 0;
    int last = nums.size() - 1;
    int current = last;

    int firstEl;
    int lastEl;

    // Loop through nums
    while(first <= last) {
        // Compare biggest elements of each side and insert bigger one at back
        // Move pointer in corresponding direction
        firstEl = abs(nums[first]);
        lastEl = abs(nums[last]);

        if (firstEl > lastEl) {
            result[current] = firstEl * firstEl;
            first++;
        } else {
            result[current] = lastEl * lastEl;
            last--;
        }

        // Because last positioned element is already correct
        current--;
    }

    return result;
}

/**
 * Two Sum II - Input Array is Sorted
 * @param numbers an unordered array containing the numbers.
 * @param target the target sum.
 * @return the vector containing the two relevant numbers.
 */
std::vector<int> twoSum(std::vector<int> &numbers, int target) {

    int first = 0;
    int second = numbers.size() - 1;
    int sum;

    while (first < second) {
        sum = numbers[first] + numbers[second];

        if (sum == target) {
            break;
        }
            // Smaller
        else if (sum < target) {
            first++;
        }
            // Bigger
        else {
            second--;
        }
    }

    // Because 1 indexed array
    return std::vector<int>{first + 1, second + 1};


//    // Stores key: number and value: index
//    std::unordered_map<int, int> numMap;
//
//    // Iterate over each element
//    for (int i = 0; i < numbers.size(); ++i) {
//        int complement = target - numbers[i];
//
//        // Check if we have complement
//        if (numMap.count(complement)) {
//            return std::vector<int>{numMap.find(complement)->second, i};
//        }
//
//        // Insert the new number-index pair
//        numMap[numbers[i]] = i;
//    }
//
//    return std::vector<int>{-1, -1};
}

/**
 *
 * @param nums
 */
void moveZeroes(std::vector<int> &nums) {
    int last = 0;
    int current = 0;

    while (current < nums.size()) {
        // Check if current number is not a 0
        if (nums[current] != 0) {
            // Swap 0 with number
            std::swap(nums[last], nums[current]);
            // Move the last pointer to next 0 spot
            last++;
        }
        // Iteration step
        current++;
    }
}

/**
 * 88. Merge Sorted Array
 * Binary Search
 * Merges two arrays into nums1 in ascending order.
 * @param nums1 the list integer array sorted in ascending order.
 * @param m the number of elements in the list integer array.
 * @param nums2  the second integer array sorted in ascending order.
 * @param n the number of elements in the second integer array.
 */
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int first = m - 1;
    int second = n - 1;
    int insert = m + n - 1;

    // Loop until one array pointer is -1
    while (first >= 0 && second >= 0) {
        // Compare elements
        if (nums1[first] > nums2[second]) {
            // Insert to empty slot
            nums1[insert] = nums1[first];
            // Move back
            first--;
        } else {
            nums1[insert] = nums2[second];
            second--;
        }

        // In each case change empty slot
        insert--;
    }

    // Overwrite all remaining bigger numbers in nums1
    while (second >= 0) {
        nums1[insert] = nums2[second];
        second--;
        insert--;
    }
}

#endif //CPPBASICS_TWOPOINTERS_H
