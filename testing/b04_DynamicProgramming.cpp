#include <gtest/gtest.h>
#include "../src/05_Bonus/DynamicProgramming.h"

TEST(DynamicProgrammingTests, MaxProfit) {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfit(prices), 5);
}

TEST(DynamicProgrammingTests, PascalTriangle) {
    std::vector<std::vector<int>> result = {{1},
                                            {1, 1},
                                            {1, 2, 1},
                                            {1, 3, 3, 1},
                                            {1, 4, 6, 4, 1}};
    EXPECT_EQ(generate(5), result);
}

TEST(DynamicProgrammingTests, MinimumTotal) {
    std::vector<std::vector<int>> result = {{2},
                                            {3, 4},
                                            {6, 5, 7},
                                            {4, 1, 8, 3}};
    EXPECT_EQ(minimumTotal(result), 11);
}

TEST(DynamicProgrammingTests, ClimbStairs) {
    EXPECT_EQ(climbStairs(3), 3);
}

TEST(DynamicProgrammingTests, HouseRobber) {
    std::vector<int> nums;

    // Empty
    nums = {};
    EXPECT_EQ(rob(nums), 0);
    // Default
    nums = {2, 7, 9, 3, 1};
    EXPECT_EQ(rob(nums), 12);
}

TEST(LArrayTests, MaxSubArray) {
    std::vector<int> nums;
    int solution;

    nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    solution = maxSubArray(nums);
    EXPECT_EQ(solution, 6);
    nums = {1};
    solution = maxSubArray(nums);
    EXPECT_EQ(solution, 1);
}