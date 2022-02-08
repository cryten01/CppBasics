#include <gtest/gtest.h>
#include "../src/03_DataStructures/ds04_Queue.h"

class QueueTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    // void TearDown() override {}

    Queue<int> emptyQueue;
};

TEST_F(QueueTest, IsEmpty) {
    EXPECT_TRUE(emptyQueue.IsEmpty());
}

TEST_F(QueueTest, Push) {
    emptyQueue.Push(10);
    EXPECT_EQ(emptyQueue.GetSize(), 1);
}

TEST_F(QueueTest, Pop) {
    emptyQueue.Push(10);
    emptyQueue.Pop();
    EXPECT_TRUE(emptyQueue.IsEmpty());
}

TEST_F(QueueTest, Front) {
    emptyQueue.Push(34);
    EXPECT_EQ(emptyQueue.Front(), 34);
    emptyQueue.Push(40);
    EXPECT_EQ(emptyQueue.Front(), 34);
}

