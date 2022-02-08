#include <gtest/gtest.h>
#include "../src/03_DataStructures/ds04_Dequeue.h"

class DequeueTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    // void TearDown() override {}

    Dequeue<int> emptyDequeue;
};

TEST_F(DequeueTest, IsEmpty) {
    EXPECT_TRUE(emptyDequeue.IsEmpty());
}

TEST_F(DequeueTest, PushBack) {
    emptyDequeue.PushBack(10);
    EXPECT_EQ(emptyDequeue.GetSize(), 1);
}

TEST_F(DequeueTest, PushFront) {

}

TEST_F(DequeueTest, PopBack) {
    emptyDequeue.PushBack(10);
    emptyDequeue.PopBack();
    EXPECT_TRUE(emptyDequeue.IsEmpty());
}

TEST_F(DequeueTest, PopFront) {
    emptyDequeue.PushBack(10);
    emptyDequeue.PushBack(12);
    emptyDequeue.PopFront();
    EXPECT_EQ(emptyDequeue.Front(), 10);
}

TEST_F(DequeueTest, Front) {
    emptyDequeue.PushFront(34);
    EXPECT_EQ(emptyDequeue.Front(), 34);
    emptyDequeue.PushFront(40);
    EXPECT_EQ(emptyDequeue.Front(), 34);
}

TEST_F(DequeueTest, Back) {
    emptyDequeue.PushBack(34);
    emptyDequeue.PushBack(40);
    emptyDequeue.PushBack(21);

    EXPECT_EQ(emptyDequeue.Back(), 34);
}

