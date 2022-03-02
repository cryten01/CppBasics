#include <gtest/gtest.h>
#include "../src/05_Bonus/LinkedList.h"

class LCLinkedListTests : public testing::Test {
protected:
    void SetUp() override {
        listBase = GenerateList({0, 1, 2, 3});
        listEmpty = GenerateList({});
        listSingle = GenerateList({1});
    }

    void TearDown() override {
        delete listBase;
        listBase = nullptr;
        delete listEmpty;
        listEmpty = nullptr;
        delete listSingle;
        listSingle = nullptr;
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

    ListNode *listBase;
    ListNode *listEmpty;
    ListNode *listSingle;
};

TEST_F(LCLinkedListTests, ReverseLinkedList) {
    ListNode *list;

    // Default (2-n)
    listBase = reverseList(listBase);
    CheckSolution(listBase, {3, 2, 1, 0});

    // Empty
    listEmpty = reverseList(listEmpty);
    CheckSolution(listEmpty, {});

    // Single element
    listSingle = reverseList(listSingle);
    CheckSolution(listSingle, {1});
}

TEST_F(LCLinkedListTests, MiddleNode) {
    ListNode *list = GenerateList({1, 2, 3, 4, 5});
    EXPECT_EQ(middleNode(list)->val, 3);
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

TEST_F(LCLinkedListTests, SortList) {
    // Default
    ListNode *list1 = GenerateList({-1, 5, 3, 4, 0});
    list1 = sortList(list1);
    CheckSolution(list1, {-1, 0, 3, 4, 5});
}

TEST_F(LCLinkedListTests, HasCycle) {
    // Default
    ListNode n1(1);
    ListNode n3(3,&n1);
    ListNode n2(2,&n3);
    n1.next = &n2;
    EXPECT_TRUE(hasCycle(&n1));
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

TEST_F(LCLinkedListTests, RemoveNthNodeFromEndOfList) {
    ListNode *list;
    ListNode *result;
    // Default
    list = GenerateList({1, 2, 3, 4, 5});
    result = removeNthFromEnd(list, 2);
    CheckSolution(list, {1, 2, 3, 5});
}