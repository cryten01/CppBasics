
#ifndef CPPBASICS_TWOPOINTERS_H
#define CPPBASICS_TWOPOINTERS_H

using namespace std;

#include <vector>
#include <unordered_map>

/**
 * 977. Squares of a Sorted Array
 * @param nums the array that needs to be squared and sorted.
 * @return the sorted dynamic array containing the squared numbers in ascending order.
 */
std::vector<int> sortedSquares(std::vector<int> &nums) {
    vector<int> result(nums.size());

    if (nums.size() == 0) {return result; }

    int left = 0;
    int right = nums.size() - 1;

    // For each insertion
    for (int i = 0; i < nums.size(); i++) {
        // Obtain squared numbers
        int nl = nums[left] * nums[left];
        int nr = nums[right] * nums[right];

        // Comparisons
        if (nl < nr) {
            result[nums.size() - 1 - i] = nr;
            right--;
        } else if (nl > nr) {
            result[nums.size() - 1 - i] = nl;
            left++;
        } else {
            result[nums.size() - 1 - i] = nl;
            left++;
        }
    }

    return result;
}

/**
 * 167. Two Sum II - Input Array Is Sorted
 * @param numbers an unordered array containing the numbers.
 * @param target the target sum.
 * @return the vector containing the two relevant index values + 1.
 */
std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    vector<int> result;

    if (numbers.size() < 2) {return result;}

    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            result.push_back(left + 1);
            result.push_back(right + 1);
            break;
        }
    }

    return result;
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
