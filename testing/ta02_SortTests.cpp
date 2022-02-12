#include <gtest/gtest.h>
#include "../src/04_Algorithms/Algorithms.h"

class SortTests : public ::testing::Test {
protected:
    // void SetUp() override {}
    // void TearDown() override {}

    std::vector<int> vec{1, 4, 3, 2};
    std::vector<int> toCompare{1, 2, 3, 4};
};

TEST_F(SortTests, BubbleSort) {
    BubbleSort(vec);
    EXPECT_EQ(vec, toCompare);
}

TEST_F(SortTests, SelectionSort) {
    SelectionSort(vec);
    EXPECT_EQ(vec, toCompare);
}

TEST_F(SortTests, InsertionSort) {
    InsertionSort(vec);
    EXPECT_EQ(vec, toCompare);
}

TEST_F(SortTests, MergeSort) {
    MergeSort(vec, 0, vec.size()-1);
    EXPECT_EQ(vec, toCompare);
}

TEST(SortTests, CountingSort) {
    std::vector<int> vec{1, 1, 0, 2};
    std::vector<int> freq = CountingSort(vec, 3);
    std::vector<int> freqRes{1, 2, 1};

    EXPECT_EQ(freq, freqRes);
}


