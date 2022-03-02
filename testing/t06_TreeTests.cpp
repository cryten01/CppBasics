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

        binaryTree.Push(20);
        binaryTree.Push(10);
        binaryTree.Push(12);
        binaryTree.Push(27);
        binaryTree.Push(9);
        binaryTree.Push(50);
        binaryTree.Push(33);
        binaryTree.Push(6);
    }

    void TearDown() override {
        // Also deletes the subtree
        delete root;
        root = nullptr;
    }

    Node *root;
    Node *subtree;
    BinaryTree<int> binaryTree;
};

TEST_F(TreeTests, Search) {
    EXPECT_TRUE(root->Search(5));
    EXPECT_FALSE(root->Search(9));
}

TEST_F(TreeTests, Remove) {
    EXPECT_TRUE(binaryTree.Search(20));
    binaryTree.Remove(20);
    EXPECT_FALSE(binaryTree.Search(20));
}

TEST_F(TreeTests, Display) {
    // TODO:
}
