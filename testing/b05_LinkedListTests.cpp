#include <gtest/gtest.h>
#include "../src/05_Bonus/LinkedList.h"

class LeetCode : public testing::Test {
protected:
    void SetUp() override {
        list = GenerateList({0, 1, 2, 3});
        list2 = GenerateList({1, 2, 4});
        list3 = GenerateList({1, 3, 4});
    }

    void TearDown() override {
        delete list;
        list = nullptr;
        delete list2;
        list2 = nullptr;
        list3 = nullptr;
        delete list3;
    }

    ListNode *GenerateList(std::vector<int> numbers) {

        ListNode *temp = nullptr;
        ListNode *previous = nullptr;
        ListNode *head = nullptr;

        for (int &number: numbers) {
            // Generate new node
            temp = new ListNode(number);

            // Link with list if there is a previous node
            if (previous == nullptr) {
                head = temp;
            } else {
                previous->next = temp;
            }

            // Iteration step
            previous = temp;
        }

        return head;
    }

    void CheckSolution(ListNode *original, std::vector<int> correctNums) {
        for (const int &num: correctNums) {
            EXPECT_EQ(original->val, num);
            original = original->next;
        }
    }

    ListNode *list;
    ListNode *list2;
    ListNode *list3;
};

TEST_F(LeetCode, Reverse) {
    list = reverseList(list);
    CheckSolution(list, {3, 2, 1, 0});
}

TEST_F(LeetCode, MergeTwoLists) {
    ListNode *result = mergeTwoLists(list2, list3);
    CheckSolution(result, {1, 1, 2, 3, 4, 4});
}

TEST_F(LeetCode, HasCycle) {
    // TODO
}

TEST_F(LeetCode, MiddleNode) {
    ListNode* list = GenerateList({1,2,3,4,5});
    (middleNode(list)->val, 3);
}