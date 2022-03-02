#include <gtest/gtest.h>
#include "../src/05_Bonus/Binary.h"

using namespace std;

TEST(BinaryTests, PowerOf2) {
    // Invalid
    EXPECT_FALSE(isPowerOfTwo(3));
    // Valid
    EXPECT_TRUE(isPowerOfTwo(16));
    EXPECT_TRUE(isPowerOfTwo(32));
}

TEST(BinaryTests, NumberOf1Bits) {
    // TODO:
    EXPECT_EQ(hammingWeight(00000000000000000000000000001011), 3);
}

TEST(BinayTests, HammingDistance) {
    EXPECT_EQ(hammingDistance(3, 1), 1);
    EXPECT_EQ(hammingDistance(1, 4), 2);
}

TEST(BinayTests, ReverseBits) {
    EXPECT_EQ(reverseBitsAlt(0b00000010100101000001111010011100), 0b00111001011110000010100101000000);
}

TEST(BinayTests, SingleNumber) {
    // TODO
    std::vector<int> numbers = {2, 2, 1};
    EXPECT_EQ(singleNumber(numbers), 1);
    numbers = {4, 1, 2, 1, 2};
    EXPECT_EQ(singleNumber(numbers), 4);
}

TEST(BinaryTests, MissingNumber) {
    std::vector<int> numbers = {3, 0, 1};
    EXPECT_EQ(missingNumber(numbers), 2);
    numbers = {1, 2, 3, 4};
    EXPECT_EQ(missingNumber(numbers), 0);
}

TEST(BinaryTests, CountingBits) {
    EXPECT_EQ(countBits(2), (std::vector<int>{0, 1, 1}));
}