
#ifndef CPPBASICS_MATRIX_H
#define CPPBASICS_MATRIX_H

using namespace std;

#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

/**
 * 74. Search a 2D Matrix
 * Binary Search
 * @param matrix
 * @param target
 * @return
 */
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.size() < 1 || matrix[0].size() < 1) { return false; }

    // Detect row first
    int top = 0;
    int bottom = matrix.size() - 1;
    int targetRowIndex = -1;

    while (top <= bottom) {
        int mid = top + (bottom - top) / 2;
        int first = matrix[mid][0];
        int last = matrix[mid][matrix[mid].size() - 1];

        // We found the row
        if (target >= first && target <= last) {
            targetRowIndex = mid;
            break;
        } else if (target < first) {
            bottom = mid - 1;
        } else {
            top = mid + 1;
        };
    }

    // No row detected containing number
    if (targetRowIndex == -1) { return false; }

    // Detect correct value afterwards
    vector<int> &targetRow = matrix[targetRowIndex];
    int left = 0;
    int right = targetRow.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target < targetRow[mid]) {
            right = mid - 1;
        } else if (target > targetRow[mid]) {
            left = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

/**
 * Helper function for Flood Fill representing Depth First Search.
 * @param image
 * @param sr
 * @param sc
 * @param newColor
 * @param origColor
 */
void fill(vector<vector<int>> &image, int sr, int sc, int newColor, int origColor) {
    // Boundary check
    if (sr >= image.size() || sc >= image[0].size() || sr < 0 || sc < 0) { return; }
    // Wrong color check (already marked) -> exit condition
    if (image[sr][sc] != origColor) { return; }
    // Color pixel
    image[sr][sc] = newColor;
    // Recursively call all 4 linear directions
    fill(image, sr - 1, sc, newColor, origColor);
    fill(image, sr + 1, sc, newColor, origColor);
    fill(image, sr, sc - 1, newColor, origColor);
    fill(image, sr, sc + 1, newColor, origColor);
}

/**
 * 733. Flood Fill
 * Recursive Depth First Search
 * @param image
 * @param sr
 * @param sc
 * @param newColor
 * @return
 */
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    // Check if already correct color
    if (image[sr][sc] == newColor) { return image; }

    // Get original color
    int origColor = image[sr][sc];

    // Mark coords by color
    fill(image, sr, sc, newColor, origColor);

    return image;
}

/**
 * Helper method for 733. Flood Fill (iterative version)
 * @param image
 * @param coordsStack
 * @param row
 * @param col
 * @param originalColor
 */
void populateStack(vector<vector<int>>& image, stack<pair<int,int>>& coordsStack, int row, int col, int originalColor) {
    // Boundary check
    if (row < 0 || col < 0 || row >= image.size() || col >= image[0].size()) {return;}

    // Color check
    if (image[row][col] != originalColor) {return;}

    // If all checks passed push it
    coordsStack.push(pair<int,int>{row,col});
}

/**
 * 733. Flood Fill
 * Iterative DFS
 * @param image
 * @param sr
 * @param sc
 * @param newColor
 * @return
 */
vector<vector<int>> floodFillIterative(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // 0,1 case
    if (image.size() < 1 || image[0].size() < 1) { return image; }

    // Get original color first
    int originalColor = image[sr][sc];

    // Already same color case
    if (originalColor == newColor) {return image;}

    // Iterative DFS using a stack containing correct target
    stack<pair<int,int>> coordsStack;

    // Push starting point
    coordsStack.push(pair<int,int>{sr,sc});

    // Perform actual DFS
    while (!coordsStack.empty()) {
        // Pop element
        pair<int,int> coords = coordsStack.top();
        coordsStack.pop();

        // Manipulate pixel
        image[coords.first][coords.second] = newColor;

        // Iteration step for all 4 directions
        populateStack(image, coordsStack, coords.first + 1, coords.second, originalColor);
        populateStack(image, coordsStack, coords.first - 1, coords.second, originalColor);
        populateStack(image, coordsStack, coords.first, coords.second + 1, originalColor);
        populateStack(image, coordsStack, coords.first, coords.second - 1, originalColor);
    }

    return image;
}


/**
 * 542. 01 Matrix
 * Dynamic Programming
 * @param mat
 * @return
 */
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    vector<int> DIR = {0, 1, 0, -1, 0};

    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (mat[r][c] == 0) q.emplace(r, c);
            else mat[r][c] = -1; // Marked as not processed yet!

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + DIR[i], nc = c + DIR[i+1];
            if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
            mat[nr][nc] = mat[r][c] + 1;
            q.emplace(nr, nc);
        }
    }
    return mat;
}

/**
 * Perform BFS recursively per level
 * @param grid
 * @param row
 * @param col
 * @param fresh
 * @return
 */
int BFSRecursive(vector<vector<int>> &grid, queue<pair<int, int>> &rottenOranges, int &fresh) {
    if (rottenOranges.empty() || fresh <= 0) {
        return 0;
    }

    vector<pair<int, int>> directions = {{0,  1},
                                         {1,  0},
                                         {0,  -1},
                                         {-1, 0}};

    // Loop through all current rotten oranges
    int size = rottenOranges.size();

    for (int i = 0; i < size; i++) {

        // Pop coords
        std::pair<int, int> coords = rottenOranges.front();
        rottenOranges.pop();

        // Perform BFS in all 4 directions
        for (pair<int, int> &dir: directions) {

            // Calculate neighbour coordinates
            int row = coords.first + dir.first;
            int col = coords.second + dir.second;

            // Boundary check and fresh check
            if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 ||
                grid[row][col] != 1) { continue; }

            // Make it rotten and push it to the queue
            grid[row][col] = 2;
            rottenOranges.push({row, col});

            // Also decrease number of fresh oranges
            fresh--;
        }
    }

    // Return the max + 1 because orange got rotten
    return 1 + BFSRecursive(grid, rottenOranges, fresh);
}

/**
 * Perform BFS iteratively with while loop
 * @param grid
 * @param rottenOranges
 * @param fresh
 * @return
 */
int BFSIterative(vector<vector<int>> &grid, queue<pair<int, int>> &rottenOranges, int &fresh) {
    int time = 0;
    vector<pair<int, int>> directions = {{0,  1},
                                         {1,  0},
                                         {0,  -1},
                                         {-1, 0}};

    // Stop loop if no rotten oranges left
    while (!rottenOranges.empty() && fresh > 0) {

        // Capture all current rotten oranges
        int rottenOrangesSize = rottenOranges.size();

        // Loop through all current rotten oranges
        for (int i = 0; i < rottenOrangesSize; i++) {
            // Pop coords
            std::pair<int, int> coords = rottenOranges.front();
            rottenOranges.pop();

            // Perform BFS in all 4 directions
            for (pair<int, int> &dir: directions) {

                // Calculate neighbour coordinates
                int row = coords.first + dir.first;
                int col = coords.second + dir.second;

                // Boundary check and fresh check
                if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 ||
                    grid[row][col] != 1) { continue; }

                // Make it rotten and push it to the queue
                grid[row][col] = 2;
                rottenOranges.push({row, col});

                // Also decrease number of fresh oranges
                fresh--;
            }
        }

        // Increase time for each level
        time++;
    }

    return time;
}

/**
 * 994. Rotting Oranges
 * BFS
 * @param grid
 * @return
 */
int orangesRotting(vector<vector<int>> &grid) {
    // Empty case
    if (grid.empty()) { return -1; }

    int fresh = 0;
    std::queue<pair<int, int>> rottenOranges;

    // Count fresh oranges
    // Store coords of all rotten oranges
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            if (grid[row][col] == 1) {
                fresh++;
            } else if (grid[row][col] == 2) {
                rottenOranges.push({row, col});
            }
        }
    }

    // Perform BFS and return number of time steps
//    int time = BFSIterative(grid, rottenOranges, fresh);
    int time = BFSRecursive(grid, rottenOranges, fresh);

    return fresh > 0 ? -1 : time;
}


int dfsLand(vector<vector<int>> &grid, int sr, int sc) {
    // Out of bounds check
    if (sr >= grid.size() || sc >= grid[0].size() || sr < 0 || sc < 0) { return 0; }

    // Already detected or water
    if (grid[sr][sc] == -1 || grid[sr][sc] == 0) { return 0; }

    // Mark as detected
    grid[sr][sc] = -1;

    // Recursively progress in all 4 linear directions (DFS iteration)
    int left = dfsLand(grid, sr - 1, sc);
    int right = dfsLand(grid, sr + 1, sc);
    int bottom = dfsLand(grid, sr, sc + 1);
    int top = dfsLand(grid, sr, sc - 1);

    // Return all adjacent island parts + current one (-1 prevents double counting)
    return (1 + left + right + bottom + top);
}

/**
 * 695. Max Area of Island
 * Depth First Search
 * @param grid
 * @return
 */
int maxAreaOfIsland(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int max = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // We detected land
            if (grid[i][j] == 1) {
                // Run dfs
                int landSize = dfsLand(grid, i, j);
                // Check if new max
                max = std::max(landSize, max);
            }
        }
    }

    return max;
}

/**
 * 566. Reshape the Matrix
 * @param mat
 * @param r
 * @param c
 * @return
 */
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    vector<vector<int>> result(r, vector<int>(c, 0));

    // Sanity check
    if (r < 1 || r < 1 || mat.size() * mat[0].size() != r * c) { return mat; }

    int row = 0;
    int col = 0;

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (col >= c) {
                col = 0;
                row++;
            }

            result[row][col] = mat[i][j];
            col++;
        }
    }

    return result;
}

/**
 * 36. Valid Sudoku
 * @param board
 * @return
 */
bool isValidSudoku(vector<vector<char>> &board) {
    //rows[5][0] means whether number 1('0'+1) in row 5 has appeared.
    int rows[9][9] = {0};
    //cols[3][8] means whether number 9('8'+1) in col 3 has appeared.
    int cols[9][9] = {0};
    //blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.
    int blocks[3][3][9] = {0};

    //traverse board r,c
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            //skip all number '.'
            if (board[r][c] != '.') {
                //calculate the number's index(board's number minus 1)
                int number = board[r][c] - '1';
                //if the number has already appeared once, return false.
                if (rows[r][number]++) return 0;
                if (cols[c][number]++) return 0;
                if (blocks[r / 3][c / 3][number]++) return 0;
            }
    return 1;
}

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col) {
    // Base case: out of bounds
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) { return; }

    // Base case: water or visited
    if (grid[row][col] == '0' || visited[row][col]) { return; }

    // Mark all connected land as true
    visited[row][col] = true;

    // Recursive steps
    dfs(grid, visited, row + 1, col);
    dfs(grid, visited, row - 1, col);
    dfs(grid, visited, row, col + 1);
    dfs(grid, visited, row, col - 1);
}

/**
 * 200. Number of Islands (medium)
 * Recursive DFS
 * @param grid
 * @return
 */
int numIslands(vector<vector<char>> &grid) {
    // 0 case
    if (grid.size() < 1 || grid[0].size() < 1) { return 0; }

    // default values: false
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    int nrOfLands = 0;
    // Go through every cell
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            // Call dfs if not visited and land
            if (grid[row][col] == '1' && !visited[row][col]) {
                dfs(grid, visited, row, col);
                nrOfLands++;
            }
        }
    }

    return nrOfLands;
}



#endif //CPPBASICS_MATRIX_H
