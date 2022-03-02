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

    // TODO: more testcases
    // Diagonal
    // Surrounded
    // All
    // Nothing
}

TEST(MatrixTests, SearchA2DMatrix) {
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

TEST(MatrixTests, MaxAreaOfIsland) {
    // TODO
}

TEST(MatrixTests, M01Matrix) {
    // TODO
    vector<vector<int>> matrix;
    vector<vector<int>> solution;
    matrix = {{0, 0, 0},
              {0, 1, 0},
              {1, 1, 1}};
    solution = {{0, 0, 0},
                {0, 1, 0},
                {1, 2, 1}};
    EXPECT_EQ(updateMatrix(matrix), solution);
}

TEST(MatrixTests, ReshapeTheMatrix) {
    // TODO
    vector<vector<int>> matrix = {{1, 2},
                                  {3, 4}};
    vector<vector<int>> solution = {{1, 2, 3, 4}};
    EXPECT_EQ(matrixReshape(matrix, 1, 4), solution);
}

TEST(MatrixTests, IsValidSudoku) {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    EXPECT_TRUE(isValidSudoku(board));
}


TEST(MatrixTests, NumberOfIslands) {
    std::vector<vector<char>> grid = {{'1', '1', '1', '1', '1', '0', '0', '0', '0'},
                                      {'0', '0', '1', '1', '1', '0', '0', '0', '0'}};
    // TODO
    EXPECT_EQ(numIslands(grid), 1);
}