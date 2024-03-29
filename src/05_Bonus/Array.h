
#ifndef CPPBASICS_ARRAY_H
#define CPPBASICS_ARRAY_H

#include <vector>
#include <unordered_map>
#include <iostream>

/**
 * 35. Search Insert Position
 * Binary search
 * @param nums
 * @param target
 * @return the index of the target found, otherwise where it would be if inserted in order.
 */
int searchInsert(std::vector<int> &nums, int target) {
    if (nums.size() < 1) { return -1; }

    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left <= right) {
        // Detecting mid index
        mid = left + (right - left) / 2;

        // We found the target
        // Or moving either into left or right partition
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else if (target > nums[mid]) {
            left = mid + 1;
        }
    }

    // Return the last index before left > right
    return left;
}

/**
 *
 * @param nums
 * @param target
 * @return
 */
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

/**
 * 189. Rotate Array
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


#endif //CPPBASICS_ARRAY_H
