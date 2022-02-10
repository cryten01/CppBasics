#include <gtest/gtest.h>
#include "../src/03_DataStructures/DataStructures.h"


class TreeTests : public ::testing::Test {
protected:
    void SetUp() override {
        root = new Node(1);
        subtree = new Node(3);

        root->AddChild(new Node(2));
        subtree->AddChild(new Node(5));
        subtree->AddChild(new Node(6));
        root->AddChild(subtree);
        root->AddChild(new Node(4));

        root->DisplayTree();
    }

    void TearDown() override {
        // Also deletes the subtree
        delete root;
        root = nullptr;
    }

    Node *root;
    Node *subtree;
};

TEST_F(TreeTests, Search) {
    EXPECT_TRUE(root->Search(5));
    EXPECT_FALSE(root->Search(9));
}