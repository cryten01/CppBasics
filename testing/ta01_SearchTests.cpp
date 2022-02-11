#include <gtest/gtest.h>
#include "../src/04_Algorithms/Search.h"

TEST(SearchTests, BinarySearch) {
    OrderedArray<int> numbers(10,0);
    numbers.Push(10);
    numbers.Push(2);
    numbers.Push(3);
    int result = Search::BinarySearch(numbers, 10);
    EXPECT_EQ(result, 2);
}

