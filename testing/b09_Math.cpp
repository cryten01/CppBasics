#include <gtest/gtest.h>
#include "../src/05_Bonus/Math.h"

TEST(MathTests, CountPrimes) {
    EXPECT_EQ(countPrimes(10), 4);
    EXPECT_EQ(countPrimes(13), 5);
}

TEST(MathTests, PowerOfThree) {
    EXPECT_FALSE(isPowerOfThree(0));
    EXPECT_FALSE(isPowerOfThree(5));
    EXPECT_TRUE(isPowerOfThree(9));
    EXPECT_TRUE(isPowerOfThree(27));
    EXPECT_FALSE(isPowerOfThree(4782968));
    EXPECT_TRUE(isPowerOfThree(243));

}