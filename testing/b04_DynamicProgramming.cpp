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
