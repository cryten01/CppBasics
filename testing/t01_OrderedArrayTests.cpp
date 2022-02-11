#include <gtest/gtest.h>
#include "../src/03_DataStructures/ds01_OrderedArray.h"

struct OrderedArrayTest : testing::Test {
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(OrderedArrayTest, Push) {
    OrderedArray<int> array(3, 0);
    array.Push(11);
    array.Push(12);
    array.Push(13);
    EXPECT_EQ(array[2], 11);
    EXPECT_EQ(array[1], 12);
    EXPECT_EQ(array[0], 13);
}

TEST_F(OrderedArrayTest, Pop) {
    OrderedArray<int> array(3, 0);
    array.Push(11);
    array.Push(12);
    array.Pop();
    EXPECT_EQ(array.GetSize(), 1);
    array.Pop();
    EXPECT_EQ(array.GetSize(), 0);
}

TEST_F(OrderedArrayTest, Remove) {
    OrderedArray<int> array(3, 0);
    array.Push(11);
    array.Push(12);
    array.Remove(0);
    EXPECT_EQ(array[0], 11);
    array.Remove(0);
    EXPECT_EQ(array[0], 0);
}