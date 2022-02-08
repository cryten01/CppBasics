#include <gtest/gtest.h>
#include "../src/03_DataStructures/DataStructures.h"

class UnorderedArrayTest : public testing::Test {
protected:
    void SetUp() override {
        arrayPtr = new UnorderedArray<int>(3);
    }

    void TearDown() override {
        delete arrayPtr;
        arrayPtr = NULL;
    }

    UnorderedArray<int> *arrayPtr;
};

TEST_F(UnorderedArrayTest, Push) {
    UnorderedArray<int> array(3);
    EXPECT_EQ(array.GetSize(), 0);
    array.Push(10);
    EXPECT_EQ(array.GetSize(), 1);
    EXPECT_EQ(array[0], 10);
}

TEST_F(UnorderedArrayTest, Pop) {
    UnorderedArray<int> array(3);
    array.Push(10);
    array.Pop();
    EXPECT_EQ(array.GetSize(), 0);
    EXPECT_EQ(array[0], 10);
}

TEST_F(UnorderedArrayTest, Remove) {
    UnorderedArray<int> array(3);
    array.Push(10);
    array.Push(12);
    array.Remove(0);
    EXPECT_EQ(array[0], 12);
}

TEST_F(UnorderedArrayTest, Search) {
    UnorderedArray<int> array(3);
    array.Push(20);
    array.Push(40);
    EXPECT_EQ(array.Search(20), 0);
}