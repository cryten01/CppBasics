#include <gtest/gtest.h>
#include "../src/05_Bonus/MyQueue.h"
#include "../src/05_Bonus/Design.h"


class LCQueueTests : public testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {};
};

TEST_F(LCQueueTests, Push) {

}

TEST_F(LCQueueTests, Pop) {

}

TEST_F(LCQueueTests, Peek) {

}

TEST_F(LCQueueTests, Empty) {

}

TEST_F(LCQueueTests, MinStack) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    EXPECT_EQ(minStack.getMin(), -3);
    minStack.pop();
    EXPECT_EQ(minStack.top(), 0);
    EXPECT_EQ(minStack.getMin(), -2);
}

TEST_F(LCQueueTests, RandomShuffle) {
    std::vector<int> nums{1, 2, 3};
    Solution solution(nums);
    nums = solution.shuffle();


}
