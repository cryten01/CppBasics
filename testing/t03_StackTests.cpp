#include <gtest/gtest.h>
#include "../src/03_DataStructures/DataStructures.h"

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {
        singleLinkedListStack.Push(10);
        twoLinkedListStack.Push(10);
        twoLinkedListStack.Push(12);
    }

    // void TearDown() override {}

    LLStack<int> emptyLinkedListStack;
    LLStack<int> singleLinkedListStack;
    LLStack<int> twoLinkedListStack;

    // TODO: Also test array version
};

TEST_F(StackTest, IsEmpty) {
    EXPECT_TRUE(emptyLinkedListStack.IsEmpty());
}

TEST_F(StackTest, Top) {
    emptyLinkedListStack.Push(10);
    EXPECT_EQ(emptyLinkedListStack.Top(), 10);
}

TEST_F(StackTest, Push) {
    singleLinkedListStack.Push(23);
    EXPECT_EQ(singleLinkedListStack.GetSize(), 2);
}

TEST_F(StackTest, Pop) {
    singleLinkedListStack.Pop();
    EXPECT_TRUE(singleLinkedListStack.IsEmpty());
    twoLinkedListStack.Pop();
    EXPECT_EQ(twoLinkedListStack.GetSize(), 1);
}

