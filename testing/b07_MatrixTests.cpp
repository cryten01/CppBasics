#include <gtest/gtest.h>
#include "../src/05_Bonus/Matrix.h"

using namespace std;

TEST(MatrixTests, FloodFill) {
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};

    vector<vector<int>> solution = {{2, 2, 2},
                                    {2, 2, 0},
                                    {2, 0, 1}};

    image = floodFill(image, 1, 1, 2);

    EXPECT_EQ(image, solution);
}

TEST(MatrixTests, MaxAreaOfIsland) {
    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    EXPECT_TRUE(searchMatrix(matrix, 3));
}

TEST(MatrixTests, RottenOranges) {
    vector<vector<int>> matrix;
    int result;

    // Default
    matrix = {{2, 1, 1},
              {1, 1, 0},
              {0, 1, 1}};
    result = orangesRotting(matrix);
    EXPECT_EQ(result, 4);

    // Empty
    matrix = {{}};
    result = orangesRotting(matrix);
    EXPECT_EQ(result, 0);

    // All rotten
    matrix = {{0, 2}};
    result = orangesRotting(matrix);
    EXPECT_EQ(result, 0);

    // Not reachable
    matrix = {{0, 1}};
    result = orangesRotting(matrix);
    EXPECT_EQ(result, -1);

    // Connected but different starting point
    matrix = {{1, 2}};
    result = orangesRotting(matrix);
    EXPECT_EQ(result, 1);

}