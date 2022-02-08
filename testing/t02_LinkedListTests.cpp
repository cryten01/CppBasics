#include <gtest/gtest.h>
#include "../src/03_DataStructures/DataStructures.h"

class LinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        singleNodeList.Push(10);
        twoNodeList.Push(11);
        twoNodeList.Push(12);
    }

    // void TearDown() override {}

    LinkList<int> emptyList;
    LinkList<int> singleNodeList;
    LinkList<int> twoNodeList;
};

TEST_F(LinkedListTest, IsEmpty) {
    EXPECT_EQ(emptyList.GetSize(), 0);
}

TEST_F(LinkedListTest, Push) {
    LinkList<int> singleLinkedList;
    EXPECT_EQ(singleLinkedList.GetSize(), 0);
    singleLinkedList.Push(10);
    singleLinkedList.Push(11);
    EXPECT_EQ(singleLinkedList.GetSize(), 2);
}

TEST_F(LinkedListTest, PushFront) {
    // TODO: Test
}

TEST_F(LinkedListTest, Pop) {
    LinkList<int> singleLinkedList;
    singleLinkedList.Push(10);
    singleLinkedList.Push(11);
    singleLinkedList.Pop();
    EXPECT_EQ(singleLinkedList.GetSize(), 1);
}

TEST_F(LinkedListTest, PopFront) {
    // TODO: Test
}

TEST_F(LinkedListTest, Iterator) {
    LinkIterator<int> it;

    it = twoNodeList.Begin();
    EXPECT_EQ(*it, 11);
    it++;
    EXPECT_EQ(*it, 12);
}

