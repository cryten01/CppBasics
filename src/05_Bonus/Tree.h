
#ifndef CPPBASICS_TREE_H
#define CPPBASICS_TREE_H

#include <stack>
#include <queue>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

/**
 * Recursive DFS, Alternatives: Iterative DFS, BFS
 * @param root
 * @return
 */
int maxDepth(TreeNode *root) {
    // Case: empty root or no children
    if (root == nullptr) { return 0; }

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

/**
 * 98. Validate Binary Search Tree
 * DFS - Inorder
 * @param root
 * @return
 */
bool isValidBST(TreeNode *root) {
    std::stack<TreeNode *> parents;

    // Long needed because root val might be smaller than INT_MIN
    long left_val = LONG_MIN;

    while (parents.size() != 0 || root != NULL) {
        // Populate input
        while (root != NULL) {
            parents.push(root);
            root = root->left;
        }

        // Get data first then pop
        root = parents.top();
        parents.pop();

        // Inorder traversal
        if (root->val <= left_val) return false;
        left_val = root->val;
        root = root->right;
    }

    return true;
}

/**
 * Also called breadth first search
 * @param root
 * @return
 */
std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> levels;

    if (root == nullptr) {
        return levels;
    }

    // Init queue
    std::queue<TreeNode *> queue;
    // Push first element
    queue.push(root);

    // Level order traversal
    while (!queue.empty()) {
        std::vector<int> level;

        // Important to use store queue size as size changes over time
        int levelLength = queue.size();

        for (size_t i = 0; i < levelLength; i++) {
            TreeNode *temp = queue.front();
            queue.pop();

            level.push_back(temp->val);

            if (temp->left != nullptr) {
                queue.push(temp->left);
            }
            if (temp->right != nullptr) {
                queue.push(temp->right);
            }
        }

        levels.push_back(level);
    }

    return levels;
}

/**
 *
 * @param nums
 * @return
 */
TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    return NULL;
}


/**
 * 617. Merge Two Binary Trees
 * Traversing tree using Depth First Search
 * @param root1
 * @param root2
 * @return
 */
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    // Use root2 only
    if (root1 == NULL) {
        return root2;
    }

    // Use root1 only
    if (root2 == NULL) {
        return root1;
    }

    // Merge roots
    root1->val += root2->val;

    // Check subtrees
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

/**
 * 116. Populating Next Right Pointers in Each Node
 * Recursive or iterative with queue/input
 * @param root
 * @return
 */
Node *connect(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    std::queue<Node *> queue;
    queue.push(root);

    // Level order traversal
    while (!queue.empty()) {
        int levelLength = queue.size();
        Node *previous = NULL;
        Node *current = NULL;

        for (int i = 0; i < levelLength; i++) {
            current = queue.front();
            queue.pop();

            if (previous != NULL) {
                previous->next = current;
            }

            if (current->left != NULL) {
                queue.push(current->left);
            }
            if (current->right != NULL) {
                queue.push(current->right);
            }

            previous = current;
        }
    }

    return root;
}

/**
 *
 * @param root the trees root (height == 0)
 * @return
 */
int GetHeight(Node *root) {
    if (root == NULL) {
        return -1;
    }

    return std::max(GetHeight(root->left), GetHeight(root->right) + 1);
}

#endif //CPPBASICS_TREE_H
