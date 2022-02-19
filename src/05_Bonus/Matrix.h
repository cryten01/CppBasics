
#ifndef CPPBASICS_MATRIX_H
#define CPPBASICS_MATRIX_H

using namespace std;

/**
 * 74. Search a 2D Matrix
 * Binary Search
 * @param matrix
 * @param target
 * @return
 */
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) { return false; }

    int nrOfRows = matrix.size();
    int nrOfColumns = matrix[0].size();

    // BS through rows to find correct one
    int top = 0;
    int bottom = nrOfRows - 1;
    int row = 0;

    while (top <= bottom) {
        row = top + (bottom - top) / 2;

        if (target < matrix[row][nrOfColumns - 1]) {
            bottom = row - 1;
        } else if (target > matrix[row][0]) {
            top = row + 1;
        } else
            break;
    }

    // Check if all rows are already crossed out
    if (top <= bottom) return false;

    // BS through correct row
    int left = 0;
    int right = nrOfColumns - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (target == mid) {
            return true;
        } else if (target < mid) {
            right = mid - 1;
        } else if (target > mid) {
            left = mid + 1;
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
 * Depth First Search
 * Alternative approaches: Iterative via input
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
 * 542. 01 Matrix
 * @param mat
 * @return
 */
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {

}


int rotten(vector<vector<int>> &grid, int sr, int sc, int &fresh) {
    // Out of bounds check
    if (sr >= grid.size() || sc >= grid[0].size() || sr < 0 || sc < 0) { return 0; }

    // If empty or already rotten
    if (grid[sr][sc] == 0 || grid[sr][sc] == 2) { return 0; }

    // Else we assume a connected path in which the orange rottens
    grid[sr][sc] = 2;
    fresh--;

    // Recursively call all 4 linear directions (sub paths)
    int left = rotten(grid, sr - 1, sc, fresh);
    int right = rotten(grid, sr + 1, sc, fresh);
    int bottom = rotten(grid, sr, sc + 1, fresh);
    int top = rotten(grid, sr, sc - 1, fresh);

    // Return the max + 1 because orange got rotten
    return (1 + max(max(left, right), max(top, bottom)));
}

/**
 * 994. Rotting Oranges
 * BFS
 * @param grid
 * @return
 */
int orangesRotting(vector<vector<int>> &grid) {
    // TODO: fix method

    if (grid.empty()) return 0;

    int sr = 0;
    int sc = 0;
    int fresh = 0;

    // If there is still one fresh orange return -1
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                fresh++;
            } else if (grid[i][j] == 2) {
                // Found different starting point
                sr = i;
                sc = j;
            }
        }
    }

    // No BFS if starting is 0 or 1
    // We need to start somewhere
    int right = rotten(grid, sr, sc, fresh);

    // First orange always rotten
    return fresh > 0 ? -1 : right;
}


#endif //CPPBASICS_MATRIX_H
