
#ifndef CPPBASICS_DYNAMICPROGRAMMING_H
#define CPPBASICS_DYNAMICPROGRAMMING_H

using namespace std;

#include <vector>

/**
 * 121. Best Time to Buy and Sell Stock
 * @param prices a list of prices where each index represents the price on the i-th day.
 * @return the maximum profit possible.
 */
int maxProfit(std::vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {
        minPrice = std::min(minPrice, prices[i]);
        maxPro = std::max(maxPro, prices[i] - minPrice);
    }

    return maxPro;
}


/**
 * 120. Triangle
 * Bottom up
 * @param triangle
 * @return
 */
int minimumTotal(std::vector<std::vector<int>> &triangle) {
    // Iterate
    for (int rows = triangle.size() - 2; rows >= 0; rows--) {
        for (int cols = 0; cols < triangle[rows].size(); cols++) {
            triangle[rows][cols] += std::min(triangle[rows + 1][cols], triangle[rows + 1][cols + 1]);
        }
    }

    return triangle[0][0];
}

/**
 * 118. Pascal's Triangle
 * Using dynamic programming, memoization
 * @param numRows
 * @return
 */
std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < numRows; i++) {
        // Generate empty vector
        std::vector<int> row(i + 1, 1);

        // Starting at 1 because access to index 0 needed
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }

        triangle.push_back(row);
    }

    return triangle;
}

/**
 * Climbing Stairs
 * Bottom up
 * @param n the number of steps to take.
 * @return the number of options
 */
int climbStairs(int n) {
    int first = 1;
    int second = 1;
    int temp = 0;

    for (int i = 0; i < n - 1; i++) {
        temp = first;
        first = first + second;
        second = temp;
    }

    return first;
}

/**
 * 746. Min Cost Climbing Stairs
 * @param cost
 * @return
 */
int minCostClimbingStairs(vector<int>& cost) {
    // 0,1 case
    if (cost.size() == 0) {return 0;}
    if (cost.size() == 1) {return cost[0];}

    // 3-n case
    for (int i = 2; i < cost.size(); i++) {
        cost[i] += min(cost[i-1], cost[i-2]);
    }

    // Return min of last two elements
    return min(cost[cost.size()-1], cost[cost.size()-2]);
}

/**
 * House Robber
 * @param nums
 * @return
 */
int rob(std::vector<int> &nums) {
    int previousRob = 0;
    int currentRob = 0;
    int temp;

    // [2,7,9,3,1]
    // [previousRob, currentRob, n, n+1]
    for (int num: nums) {
        // Figure out max between new num + previousRob or currentRob
        temp = std::max(previousRob + num, currentRob);
        // Shift currentRob to previousRob
        previousRob = currentRob;
        currentRob = temp;
    }

    // Always return latest rob
    return currentRob;
}

/**
 * Finds the contiguous subarray (containing at least one number) which has the largest sum.
 * See Kadane's Algorithm (O(n)). Alternative: Bruteforce (O(n^2))
 * @param nums the dynamic array containing the numbers
 * @return the sum of largest numbers;
 */
int maxSubArray(std::vector<int> &nums) {
    int max = nums[0];
    int current = max;

    // Starting at 1 because first already solved
    for (int i = 1; i < nums.size(); i++) {
        // Check if current sum + new num > new num
        current = std::max(current + nums[i], nums[i]);
        // Check if we have a new max
        max = std::max(current, max);
    }

    return max;
}

/**
 * 300. Longest Increasing Subsequence
 * Medium
 * @param nums
 * @return
 */
int lengthOfLIS(vector<int>& nums) {
    // Find all results from numbers < current
    // Choose max and add +1

    vector<int> lengths(nums.size(), 1);
    int max_all = 1;

    for (int i = 1; i < nums.size(); i++) {
        int max = 0;

        for (int j = i - 1; j >= 0; j--) {
            // Only consider smaller elements
            if (nums[j] < nums[i]) {
                // Max check
                max = lengths[j] > max ? lengths[j] : max;
            }
        }

        lengths[i] = 1 + max;
        max_all = lengths[i] > max_all ? lengths[i] : max_all;
    }

    return max_all;
}

/**
 * 322. Coin Change
 * @param coins
 * @param amount
 * @return
 */
int coinChange(vector<int>& coins, int amount) {
    // Check remainder for every coin
    vector<int> coinAmount(amount + 1, INT_MAX - 10);

    // 0 is always zero
    coinAmount[0] = 0;

    // Store min amount of coins for each value
    for (int i = 1; i <= amount; i++) {
        // Check solution for every possible additional coin
        for (int& coin : coins) {
            int remainder = i - coin;
            if (remainder >= 0) {
                coinAmount[i] =  min(coinAmount[i], 1 + coinAmount[remainder]);
            }
        }
    }

    return coinAmount[amount] != INT_MAX - 10 ? coinAmount[amount] : -1 ;
}


#endif //CPPBASICS_DYNAMICPROGRAMMING_H
