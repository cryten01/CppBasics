
#ifndef CPPBASICS_BACKTRACKING_H
#define CPPBASICS_BACKTRACKING_H

using namespace std;

void backtrack(int start, int k, int n, vector<int> &comb, vector<vector<int>> &branches) {
    // Exit condition (base case)
    if (comb.size() == k) {
        branches.push_back(comb);
        return;
    }

    // All possible combinations on 1 level
    // Start must be 1 bigger than root
    for (int i = start; i < n + 1; i++) {
        // Append element to combination
        comb.push_back(i);
        // Iteration step (because k depth)
        backtrack(i + 1, k, n, comb, branches);
        // Pop because make room for new combination
        comb.pop_back();
    }
}

/**
 * 77. Combinations
 * Recursion, Backtracking
 * @param n
 * @param k the height of the decision tree
 * @return
 */
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> firstComb;
    backtrack(1, k, n, firstComb, result);
    return result;
}



/**
 * 46. Permutations
 * @param nums
 * @return
 */
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;

    // Backtrack function

    if (nums.size() == 1) {
        vector<vector<int>> copy = {{nums}};
        return copy;
    }

    for (int i = 0; i < nums.size(); i++) {
        // Pop number first for recursive call
        int number = nums.back();
        nums.pop_back();

        // Get sub permutations
        vector<vector<int>> permutations = permute(nums);

        // Loop through every permutation
        for (vector<int> perm : permutations) {
            // Push back number again in every permutation
            perm.push_back(number);
            // Append the new permutations
            result.push_back(perm);
        }
    }

    // Finally, return the sub permutations
    return result;
}

#endif //CPPBASICS_BACKTRACKING_H
