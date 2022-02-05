#include <gtest/gtest.h>
#include "../src/03_DataStructures/OrderedArray.h"
#include <iostream>

struct OrderedArrayTest : testing::Test {
    OrderedArray *arrayPtr;

    OrderedArrayTest() {
        arrayPtr = new OrderedArray(10, 0);
    }

    ~OrderedArrayTest() {
        delete arrayPtr;
    }
};

TEST_F(OrderedArrayTest, Push) {
    arrayPtr->Push(11);
    arrayPtr->Push(12);
    arrayPtr->Push(13);
    EXPECT_EQ(arrayPtr->operator[](2), 11);
    EXPECT_EQ(arrayPtr->operator[](1), 12);
    EXPECT_EQ(arrayPtr->operator[](0), 13);
}

TEST_F(OrderedArrayTest, Pop) {
    arrayPtr->Push(11);
    arrayPtr->Push(12);
    arrayPtr->Pop();
    EXPECT_EQ(arrayPtr->getMNumElements(), 1);
    arrayPtr->Pop();
    EXPECT_EQ(arrayPtr->getMNumElements(), 0);
}

TEST_F(OrderedArrayTest, Remove) {
    arrayPtr->Push(11);
    arrayPtr->Push(12);
    arrayPtr->Remove(0);
    EXPECT_EQ(arrayPtr->operator[](0), 11);
    arrayPtr->Remove(0);
    EXPECT_EQ(arrayPtr->operator[](0), 0);
}