#include <gtest/gtest.h>
#include "00_LinkedList.h"
#include <iostream>

/**
 * @brief A test fixture that contains all relevant data.
 * Can be reused for different tests.
 */
struct LinkedListTest : testing::Test {
    LinkedList *list;

    LinkedListTest() {
        list = new LinkedList();
    }

    ~LinkedListTest() {
        delete list;
    }
};

TEST_F(LinkedListTest, Init) {
    EXPECT_TRUE(list->head == NULL);
}

TEST_F(LinkedListTest, Insert) {
    list->Insert(10);
    EXPECT_EQ(list->head->data, 10);
    list->Insert(12);
    EXPECT_EQ(list->head->data, 12);
}

TEST_F(LinkedListTest, InsertAfter) {
    list->InsertAfter(0,10);
}

TEST_F(LinkedListTest, Get) {
    list->Insert(10);
    list->Insert(12);
    Node *node1 = list->Get(0);
    EXPECT_EQ(node1->data, 12);
    Node *node2 = list->Get(1);
    EXPECT_EQ(node2->data, 10);
}