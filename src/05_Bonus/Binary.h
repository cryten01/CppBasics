
#ifndef CPPBASICS_BINARY_H
#define CPPBASICS_BINARY_H

#include <vector>

/**
 * 231. Power of Two
 * @param n
 * @return
 */
bool isPowerOfTwo(int n) {
    // Assuming n is a power of 2 it only has one '1' bit
    // Therefore subtracting its previous value must result in all 0 (e.g. 4-3 = 100 - 011 = 000)
    // n > 0 because all negative numbers and 0 are excluded and not a power of 2
    return n > 0 && (n & n - 1) == 0;
}

/**
 * 191. Number of 1 Bits
 * @param n
 * @return
 */
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        // Remove one 1 each iteration
        n &= n - 1;
        // Therefore, we need to increase the counter
        count++;
    }

    return count;
}

/**
 * Hamming Distance
 * @param x
 * @param y
 * @return
 */
int hammingDistance(int x, int y) {
    // Count the number of different bits compared to other integer (x = 00 y = 11 => 2)
    int count = 0;
    int xBitState;
    int yBitState;

    // Loop until every number has no 1 bits left
    while (x || y) {
        // Compares bits at the first position because comparing with 1 == 01 in binary
        // Only can be 1 if first bit is 1
        xBitState = x & 1;
        yBitState = y & 1;

        // Count if difference occurs
        if (xBitState != yBitState) { count++; }

        // Iteration step
        x >>= 1;
        y >>= 1;
    }

    return count;
}

/**
 * Reverse Bits
 * @param n
 * @return
 */
uint32_t reverseBits(uint32_t n) {
    // Use bitset?
    std::bitset<32> bits(n);

    int front = 0;
    int back = bits.size() - 1;

    while (front < back) {
        std::swap(bits[front], bits[back]);
        front++;
        back--;
    }

    return (uint32_t) bits.to_ullong();
}

uint32_t reverseBitsAlt(uint32_t n) {
    // All 32 bits are 0
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        // Get nth bit
        bool bit = (n >> i) & 1;
        // Put it in the opposite spot
        result = result | (bit << (31 - i));
    }

    return result;
}

/**
 * 136. Single Number
 * @param nums
 * @return
 */
int singleNumber(std::vector<int> &nums) {
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
        // XOR bit manipulation
        result ^= nums[i];
    }

    return result;
}

/**
 * 268. Missing Number
 * @param nums
 * @return
 */
int missingNumber(std::vector<int> &nums) {
    int result = nums.size();
    int i = 0;

    // 0 XOR does not matter
    for (int num: nums) {
        // 2 XOR eliminates operation
        result ^= num;
        result ^= i;
        i++;
    }

    return result;
}

/**
 * 338. Counting Bits (medium)
 * @param n
 * @return
 */
std::vector<int> countBits(int n) {
    std::vector<int> ans(n + 1, 0);

    int offset = 1;
    for (int i = 1; i <= ans.size(); i++) {
        if (offset * 2 == i) { offset = i; }

        ans[i] = 1 + ans[i - offset];
    }

    return ans;
}

#endif //CPPBASICS_BINARY_H
