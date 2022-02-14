
#ifndef CPPBASICS_LARRAY_H
#define CPPBASICS_LARRAY_H

#include <vector>
#include <unordered_map>
#include <iostream>

/**
 *
 * @param nums
 * @param k
 */
void rotate(std::vector<int> &nums, int k) {
    if (k <= 0) return;

//    for (int i = 0; i < k; i++) {
//        int jump = i;
//        int currentSlot = nums.size() -1 - i;
//        while (jump < currentSlot) {
//            std::swap(nums[jump], nums[currentSlot]);
//            jump += k;
//        };
//    }

    // Store last element
    int last = nums[nums.size() - 1];

    int temp = last;
    // Move all elements to the left except last
    for (int i = nums.size() - 1; i > 0; i--) {
        temp = nums[i - 1];
        nums[i] = temp;
    }

    // Replace first element with last
    nums[0] = last;

    // Iteration step
    k--;

    // Recursive call
    rotate(nums, k);
}

/**
 * Finds the contiguous subarray (containing at least one number) which has the largest sum.
 * See Kadane's Algorithm (O(n)). Alternative: Bruteforce (O(n^2))
 * @param nums the dynamic array containing the numbers
 * @return the sum of largest numbers;
 */
int maxSubArray(std::vector<int> &nums) {
    int max = nums[0];
    int current = max;

    for (int i = 1; i < nums.size(); i++) {
        // Check if current sum + new num > new num
        current = std::max(current + nums[i], nums[i]);
        // Check if we have a new max
        max = std::max(current, max);
    }

    return max;
}

/**
 * 350. Intersection of Two Arrays II
 * @param nums1
 * @param nums2
 * @return a new vector containing the intersection of both arrays or an empty array if no intersection occurred.
 */
std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> result;

    if (nums1.size() < 1 || nums2.size() < 1) return result;

    std::unordered_map<int, int> frequency;

    for (int i = 0; i < nums1.size(); i++) {
        frequency[nums1[i]] += 1;
    }

    for (int i = 0; i < nums2.size(); i++) {
        if (frequency[nums2[i]] > 0) {
            frequency[nums2[i]] -= 1;
            result.push_back(nums2[i]);
        }
    }

    return result;
}

/**
 *
 * @param nums the target that needs to be searched. Must contain at least 1 number and/or 1 unique number.
 * @return the index of the unique number
 */
int singleNumber(std::vector<int> &nums) {
    int result = 0;

    for (int i = 0; i < nums.size(); ++i) {
        // XOR bit manipulation
        result ^= nums[i];
    }

    return result;
}


int search(std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high) {
        // Calculate new mid
        mid = low + (high - low) / 2;

        // Equal
        if (nums[mid] == target) {
            return mid;
        }

        // Smaller
        if (target < nums[mid]) {
            high = mid - 1;
        }
            // Bigger
        else {
            low = mid + 1;
        }
    }

    return -1;
}

#endif //CPPBASICS_LARRAY_H
