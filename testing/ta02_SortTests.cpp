#include <gtest/gtest.h>
#include "../src/04_Algorithms/Algorithms.h"

TEST(SortTests, CountingSort) {
    std::vector<int> vec{1, 1, 0, 2};
    std::vector<int> freq = CountingSort(vec, 3);
    std::vector<int> freqRes{1, 2, 1};

    EXPECT_EQ(freq, freqRes);
}
