#include <gtest/gtest.h>
#include "../src/05_Bonus/TwoPointers.h"

class UnorderedArrayTest : public testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    std::vector<int> empty = {};
    std::vector<int> single = {1};
    std::vector<int> n = {-4, -1, 0, 3, 10};
    std::vector<int> duplicate = {1, 1, 2, 2};
};

TEST(TwoPointerTests, SortedSquaresTest) {
    // Default
    std::vector<int> nums;
    nums = {-4, -1, 0, 3, 10};
    EXPECT_EQ(sortedSquares(nums), (vector<int>{0, 1, 9, 16, 100}));
    // 1 case
    nums = {5};
    EXPECT_EQ(sortedSquares(nums), vector<int>{25});
    // Identical squared
    nums = {-7, -3, 2, 3, 11};
    EXPECT_EQ(sortedSquares(nums), (vector<int>{4,9,9,49,121}));
}

TEST(TwoPointerTests, TwoSumTest) {
    std::vector<int> nums;
    // Default
    nums = {2, 3, 4};
    EXPECT_EQ(twoSum(nums, 6), (vector<int>({1, 3})));
    // Negative
    nums = {-1, -2, 0};
    EXPECT_EQ(twoSum(nums, -3), vector<int>({1,2}));
    // Invalid target
    nums = {1,2,3,4};
    EXPECT_EQ(twoSum(nums, 20), vector<int>({}));
}

TEST(TwoPointerTests, MoveZeroesTest) {
    std::vector<int> empty{};
    moveZeroes(empty);
    EXPECT_EQ(empty, std::vector<int>{});
    std::vector<int> n{0, 1, 0, 3, 12};
    moveZeroes(n);
    EXPECT_EQ((std::vector<int>{1, 3, 12, 0, 0}), n);
}

TEST(TwoPointersTests, MergeSortedArrayTest) {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> result;

    // All empty
    nums1 = {};
    nums2 = {};
    merge(nums1, 0, nums2, 0);
    EXPECT_EQ(nums1, std::vector<int>{});

    // nums2 empty
    nums1 = {1};
    nums2 = {};
    merge(nums1, 1, nums2, 0);
    EXPECT_EQ(nums1, std::vector<int>{1});

    // nums1 empty (0 because only way to ensure fit)
    nums1 = {0};
    nums2 = {2};
    merge(nums1, 0, nums2, 1);
    EXPECT_EQ(nums1, std::vector<int>{2});

    // Default
    nums1 = {1, 2, 3, 0, 0, 0};
    nums2 = {2, 5, 6};
    result = {1, 2, 2, 3, 5, 6};
    merge(nums1, 3, nums2, 3);
    EXPECT_EQ(nums1, result);

    // Default 2
    nums1 = {4, 5, 6, 0, 0, 0};
    nums2 = {1, 2, 3};
    result = {1, 2, 3, 4, 5, 6};
    merge(nums1, 3, nums2, 3);
    EXPECT_EQ(nums1, result);
}
