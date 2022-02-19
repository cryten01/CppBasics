#include <gtest/gtest.h>
#include "../src/05_Bonus/LinkedList.h"

class LCLinkedListTests : public testing::Test {
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
        // Empty case
        if (correctNums.size() == 0) {
            EXPECT_TRUE(original == NULL);
        }

        // 1-n case
        for (const int &num: correctNums) {
            EXPECT_EQ(original->val, num);
            original = original->next;
        }
    }

    ListNode *list;
    ListNode *list2;
    ListNode *list3;
};

TEST_F(LCLinkedListTests, ReverseLinkedList) {
    ListNode *list;

    // Default (2-n)
    list = GenerateList({0, 1, 2, 3});
    list = reverseList(list);
    CheckSolution(list, {3, 2, 1, 0});

    // Empty
    list = GenerateList({});
    CheckSolution(list, {});

    // Single element
    list = GenerateList({1});
    CheckSolution(list, {1});
}


TEST_F(LCLinkedListTests, MergeTwoLists) {
    ListNode *list1;
    ListNode *list2;
    ListNode *result;

    // Default
    list1 = GenerateList({1, 2, 4});
    list2 = GenerateList({1, 3, 4});
    result = mergeTwoLists(list1, list2);
    CheckSolution(result, {1, 1, 2, 3, 4, 4});
    // Empty
    list1 = GenerateList({});
    list2 = GenerateList({});
    result = mergeTwoLists(list1, list2);
    CheckSolution(result, {});
    // List1 only
    list1 = GenerateList({1});
    list2 = GenerateList({});
    result = mergeTwoLists(list1, list2);
    CheckSolution(result, {1});
    // List2 only
    list1 = GenerateList({});
    list2 = GenerateList({2});
    result = mergeTwoLists(list1, list2);
    CheckSolution(result, {2});
}

TEST_F(LCLinkedListTests, HasCycle) {
    // TODO
}

TEST_F(LCLinkedListTests, MiddleNode) {
    ListNode *list = GenerateList({1, 2, 3, 4, 5});
    EXPECT_EQ(middleNode(list)->val, 3);
}

TEST_F(LCLinkedListTests, RemoveLinkedListElements) {
    // Empty
    ListNode *list = GenerateList({});
    ListNode *result = removeElements(list, 1);
    CheckSolution(result, {});
    // First node
    list = GenerateList({1});
    result = removeElements(list, 1);
    CheckSolution(result, {});
    // Last node
    list = GenerateList({1, 2, 3, 4});
    result = removeElements(list, 4);
    CheckSolution(result, {1, 2, 3});
    // All equal
    list = GenerateList({7, 7, 7, 7});
    result = removeElements(list, 7);
    CheckSolution(result, {});
    // Default
    list = GenerateList({1, 2, 6, 3, 4, 5, 6});
    result = removeElements(list, 6);
    CheckSolution(result, {1, 2, 3, 4, 5});
}

TEST_F(LCLinkedListTests, RemoveDuplicatesFromSortedList) {
    ListNode *list;
    ListNode *result;
    list = GenerateList({1, 1, 2});
    result = GenerateList({1, 2});
    CheckSolution(result, {1, 2});
}