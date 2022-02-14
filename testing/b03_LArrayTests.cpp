#include <gtest/gtest.h>
#include "../src/05_Bonus/LArray.h"

TEST(LArrayTests, Intersect) {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    EXPECT_EQ(intersect(nums1, nums2), (std::vector<int>{2, 2}));
}

TEST(LArrayTests, MaxSubArray) {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int solution = maxSubArray(nums);
    EXPECT_EQ(solution, 6);
    nums = {1};
    solution = maxSubArray(nums);
    EXPECT_EQ(solution, 1);
}

TEST(LArrayTests, SingleNumber) {

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