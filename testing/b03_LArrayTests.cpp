#include <gtest/gtest.h>
#include "../src/05_Bonus/Array.h"

TEST(LArrayTests, Intersect) {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    EXPECT_EQ(intersect(nums1, nums2), (std::vector<int>{2, 2}));
}

TEST(LArrayTests, Rotate) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    EXPECT_EQ(nums, (std::vector<int>{5, 6, 7, 1, 2, 3, 4}));
}

TEST(LArrayTests, BinarySearch) {
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(search(nums, 9), 4);
    nums = {5};
    EXPECT_EQ(search(nums, 5), 0);
}