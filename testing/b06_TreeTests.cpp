#include <gtest/gtest.h>
#include "../src/05_Bonus/Tree.h"

using namespace std;

class LCTreeTests : public testing::Test {
protected:
    void SetUp() override {
        // Generating tree
        TreeNode *r2 = new TreeNode{7};
        TreeNode *l2 = new TreeNode{15};
        TreeNode *r1 = new TreeNode{20, l2, r2};
        TreeNode *l1 = new TreeNode{9};
        root = new TreeNode{3, l1, r1};

        // TODO: check for memory leaks
    }

    void TearDown() override {
        // Preventing memory leaks
        delete root;
    }

    /**
     * Generates a tree from level order traversal using vector as queue
     * Breadth First Search
     * @param root
     * @param numbers
     * @return
     */
    TreeNode *GenerateLevelOrderTree(std::vector<int> numbers) {
        if (numbers.size() == 0) { return NULL; }

        // First node
        TreeNode *current = new TreeNode(numbers[0]);
        TreeNode *head = current;

        // Use tree queue to pop last nodes
        std::queue<TreeNode *> rootQueue;
        rootQueue.push(current);

        // Level order traversal
        int numIndex = 1;
        int levelLength = 2;

        while (!rootQueue.empty() && numIndex < numbers.size()) {
            // Go through all level elements
            for (; numIndex <= levelLength && numIndex < numbers.size(); numIndex++) {
                // If even left otherwise right
                if (numIndex % 2 != 0) {
                    if (numbers[numIndex] != -1) {
                        TreeNode *left = new TreeNode(numbers[numIndex]);
                        current->left = left;
                        rootQueue.push(left);
                    }
                } else {
                    if (numbers[numIndex] != -1) {
                        TreeNode *right = new TreeNode(numbers[numIndex]);
                        current->right = right;
                        rootQueue.push(right);
                    }

                    // Go to next current if right case was handled
                    rootQueue.pop();
                    current = rootQueue.front();
                }
            }
            // Increase level
            // SubLists (1,2,4,8,16...) -> n * 2
            levelLength *= 2;
        }

        return head;
    }

    // TODO:
    TreeNode *GenerateLevelOrderTreeAlt(std::vector<int> numbers) {
        if (numbers.size() == 0) { return nullptr; }

        // First node
        TreeNode *current = new TreeNode(numbers[0]);
        TreeNode *head = current;

        // Use tree queue to pop last nodes
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(current);

        int numIndex = 1;
        int currentLevelSize = 1;
        bool isLeft = true;

        // Capture current level size
        // Generate nodes and push it onto the queue

        return head;
    }

    bool Compare(TreeNode *root1, TreeNode *root2) {
        // Return if both are NULL
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        bool check = false;

        // If on is NULL and the other not they cant be equal
        if (!root1 || !root2) {
            check = false;
        }

        // Compare actual values
        if (root1->val == root2->val) {
            check = true;
        }

        Compare(root1->left, root2->left);
        Compare(root1->right, root2->right);

        return check;
    }

    void Check(TreeNode *root, std::vector<int> correctNums) {
        // Empty case
        if (correctNums.size() == 0) {
            EXPECT_TRUE(root == nullptr);
        }

//        for (const int &num: correctNums) {
//            EXPECT_EQ(original->val, num);
//            original = original->next;
//        }
    }

    TreeNode *root;
};

TEST_F(LCTreeTests, MaxDepth) {
    // Default
    EXPECT_EQ(maxDepthRecursive(root), 3);
    EXPECT_EQ(maxDepthIterative(root), 3);
}

TEST_F(LCTreeTests, ValidBST) {
    // Correct
    TreeNode tree = TreeNode(0);
    EXPECT_TRUE(isValidBST(&tree));

    TreeNode left = TreeNode(1);
    TreeNode right = TreeNode(3);
    tree = TreeNode(2, &left, &right);
    EXPECT_TRUE(isValidBSTRec(&tree));

    // Max Int
    tree = TreeNode(2147483647);
    EXPECT_TRUE(isValidBSTRec(&tree));
}

TEST_F(LCTreeTests, LevelOrder) {
    std::vector<std::vector<int>> levels = levelOrder(root);
    std::vector<std::vector<int>> solution = {{3},
                                              {9,  20},
                                              {15, 7}};
    EXPECT_EQ(levels, solution);

    // TODO: tree with null cases between
}

TEST_F(LCTreeTests, MergeTrees) {
    TreeNode *root1 = GenerateLevelOrderTree({1, 3, 2, 5});
    TreeNode *root2 = GenerateLevelOrderTree({2, 1, 3, -1, 4, -1, 7});
    TreeNode *solution = GenerateLevelOrderTree({3, 4, 5, 5, 4, -1, 7});
    TreeNode *result = mergeTrees(root1, root2);
    EXPECT_TRUE(Compare(solution, result));
}

TEST_F(LCTreeTests, PopulatingNextRightPointers) {
    Node n3(4);
    Node n4(5);
    Node n5(6);
    Node n6(7);
    Node n2(3, &n5, &n6, nullptr);
    Node n1(2, &n3, &n4, nullptr);
    Node root(1, &n1, &n2, nullptr);

    // TODO check links
    Node* rootPtr = connectIterative(&root);
}


TEST_F(LCTreeTests, PreorderTraversal) {
    TreeNode *root = GenerateLevelOrderTree({1, 0, 3});
    std::vector<int> solution = preorderTraversal(root);
    EXPECT_EQ(solution, (std::vector<int>{1, 0, 3}));
}

TEST_F(LCTreeTests, InorderTraversal) {
    // TODO: fix GenerateLevelOrderTree
//    TreeNode *root = GenerateLevelOrderTree({1, NULL, 2, 3});
    TreeNode r2(3, nullptr, nullptr);
    TreeNode l1(2, &r2, nullptr);
    TreeNode root(1, nullptr, &l1);

    vector<int> solution = inorderTraversal(&root);
    EXPECT_EQ(solution, (vector<int>{1, 3, 2}));
}

TEST_F(LCTreeTests, PostorderTraversal) {
    TreeNode l2{3, NULL, NULL};
    TreeNode l1{2, &l2, NULL};
    TreeNode root{1, NULL, &l1};

    std::vector<int> result = postorderTraversalIT(&root);
    std::vector<int> solution = {3, 2, 1};
    EXPECT_EQ(result, solution);
}

TEST_F(LCTreeTests, SymmetricTree) {
    // TODO:
    TreeNode root{1, NULL, NULL};
    EXPECT_TRUE(isSymmetric(&root));
}

TEST_F(LCTreeTests, InvertBST) {
    // TODO:
}

TEST_F(LCTreeTests, PathSum) {
    // TODO:
    // Empty
    // False
    // True
    // Negative
    // Just root
}

TEST_F(LCTreeTests, SearchBST) {
    // TODO: fix
    TreeNode *root = GenerateLevelOrderTree({4, 2, 7, 1, 3});
    TreeNode *solution = GenerateLevelOrderTree({2, 1, 3});
    Compare(root, solution);
}

TEST_F(LCTreeTests, InsertIntoBST) {
    // TODO:
}

TEST_F(LCTreeTests, InputIsABST) {
    // TODO:
}

TEST_F(LCTreeTests, LowestCommonAncestor) {
    // TODO:
}