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

    bool Compare(TreeNode *root1, TreeNode *root2) {
        // Return if both are NULL
        if (!root1 && !root2) {
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
    EXPECT_EQ(maxDepth(root), 3);
}

TEST(LCTreeTests, ValidBST) {
    TreeNode *tree = new TreeNode(0);
    EXPECT_TRUE(isValidBST(tree));
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

TEST_F(LCTreeTests, ConnectNext) {
    // TODO:
}

