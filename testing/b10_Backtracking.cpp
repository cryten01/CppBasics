#include <gtest/gtest.h>
#include "../src/05_Bonus/Backtracking.h"

using namespace std;

TEST(BacktrackingTests, Combinations) {
    // TODO:
    vector<vector<int>> solution;
    vector<vector<int>> result;

    // Two elements, single element
    solution = {{1},
                {2}};
    result = combine(2, 1);
    EXPECT_EQ(result, solution);
}

TEST(BacktrackingTests, Permutations) {
    // TODO:
    vector<vector<int>> solution = {{1, 2, 3},
                                    {1, 3, 2},
                                    {2, 1, 3},
                                    {2, 3, 1},
                                    {3, 1, 2},
                                    {3, 2, 1}};
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    EXPECT_EQ(solution, result);
}