
#ifndef CPPBASICS_TREE_H
#define CPPBASICS_TREE_H

using namespace std;

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
 * 104. Maximum Depth of Binary Tree
 * Recursive DFS,
 * @param root
 * @return
 */
int maxDepthRecursive(TreeNode *root) {
    // Case: empty root or no children
    if (root == nullptr) { return 0; }

    return 1 + std::max(maxDepthRecursive(root->left), maxDepthRecursive(root->right));
}

/**
 * 104. Maximum Depth of Binary Tree
 * Iterative level order BFS
 * @param root
 * @return
 */
int maxDepthIterative(TreeNode *root) {
    if (root == nullptr) { return 0; }

    std::queue<TreeNode *> queue;
    queue.push(root);

    int depth = 0;
    TreeNode *current;

    while (!queue.empty()) {
        int levelSize = queue.size();
        for (int i = 0; i < levelSize; i++) {
            current = queue.front();
            queue.pop();

            if (current->left) {
                queue.push(current->left);
            }
            if (current->right) {
                queue.push(current->right);
            }
        }

        depth++;
    }

    return depth;
}

/**
 * 104. Maximum Depth of Binary Tree
 * Iterative DFS
 * @param root
 * @return
 */
int maxDepthDFS(TreeNode *root) {
    if (root == nullptr) { return 0; }

    std::stack<TreeNode *> nodeStack;
    std::stack<int> depthStack;

    nodeStack.push(root);
    depthStack.push(1);

    TreeNode *currentNode;
    int maxDepth = 1;
    int currentDepth = maxDepth;

    while (!nodeStack.empty()) {
        currentNode = nodeStack.top();
        nodeStack.pop();
        currentDepth = depthStack.top();
        depthStack.pop();

        maxDepth = std::max(currentDepth, maxDepth);

        if (currentNode->left) {
            nodeStack.push(currentNode->left);
            depthStack.push(currentDepth + 1);
        }
        if (currentNode->right) {
            nodeStack.push(currentNode->right);
            depthStack.push(currentDepth + 1);
        }
    }

    return maxDepth;
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

bool isValidBSTRecHelper(TreeNode *root, long min, long max) {
    // Base case (stopping point)
    if (root == nullptr) { return true; }
    // Base case 2
    if (root->val <= min || root->val >= max) { return false; }

    // Recursive steps
    bool left = isValidBSTRecHelper(root->left, min, root->val);
    bool right = isValidBSTRecHelper(root->right, root->val, max);

    return left && right;
}

/**
 * 98. Validate Binary Search Tree
 * Recursive solution using Inorder DFS
 * @param root
 * @return
 */
bool isValidBSTRec(TreeNode *root) {
    // Long needed because entire INT range needs to be covered
    return isValidBSTRecHelper(root, LONG_MIN, LONG_MAX);
}

/**
 * 102. Binary Tree Level Order Traversal
 * Breadth first search
 * @param root
 * @return
 */
std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> allLevels;

    // 0 case
    if (root == nullptr) { return allLevels; }

    // Queue because FIFO required
    std::queue<TreeNode *> queue;
    queue.push(root);

    TreeNode *current;
    while (!queue.empty()) {
        // The current level containing all node values
        std::vector<int> level;
        // Important to use store queue size as size changes over time
        int levelLength = queue.size();

        for (size_t i = 0; i < levelLength; i++) {
            current = queue.front();
            queue.pop();

            level.push_back(current->val);

            if (current->left != nullptr) {
                queue.push(current->left);
            }
            if (current->right != nullptr) {
                queue.push(current->right);
            }
        }

        allLevels.push_back(level);
    }

    return allLevels;
}

/**
 *
 * @param root
 * @return
 */
std::vector<std::vector<int>> levelOrderRec(TreeNode *root) {
    std::vector<std::vector<int>> values;

    if (root == NULL) return values;

    // TODO:

    return values;
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
 * Recursive Depth First Search
 * @param root1
 * @param root2
 * @return
 */
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    // Use root2 only
    if (root1 == nullptr) {
        return root2;
    }

    // Use root1 only
    if (root2 == nullptr) {
        return root1;
    }

    // Merge roots
    root1->val += root2->val;

    // Process subtrees
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
 * 116. Populating Next Right Pointers in Each Node
 * Iterative BFS
 * @param root
 * @return
 */
Node* connectIterative(Node* root) {
    // 0 case
    if (root == nullptr) {return root;}

    queue<Node*> nodeQueue;

    // Push first element
    nodeQueue.push(root);

    // Using dummy node in order to avoid starting edge case
    Node dummy(-1);

    // BFS (level order approach)
    while (!nodeQueue.empty()) {
        // Capture current level size
        int levelSize = nodeQueue.size();
        Node* previous = &dummy;
        Node* current = nullptr;

        // For each node
        for (int i = 0; i < levelSize; i++) {
            // Pop element from the queue
            current = nodeQueue.front();
            nodeQueue.pop();

            // Pushing left child
            if (current->left) {
                nodeQueue.push(current->left);
            }

            // Pushing right child
            if (current->right) {
                nodeQueue.push(current->right);
            }

            // Iteration step
            previous->next = current;
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

/**
 * 144. Binary Tree Preorder (easy)
 * Iterative DFS Preorder (node, left, right)
 * @param root
 * @return
 */
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result{};

    if (root == nullptr) return result;

    // Performing DFS
    stack<TreeNode *> stack;
    stack.push(root);

    TreeNode *current;
    while (!stack.empty()) {
        // Process root
        current = stack.top();
        stack.pop();
        result.push_back(current->val);

        // Reverse order (because last in first out)
        if (current->right != nullptr) {
            stack.push(current->right);
        }
        if (current->left != nullptr) {
            stack.push(current->left);
        }
    }

    return result;
}

/**
 * 94. Binary Tree Inorder Traversal (easy)
 * Iterative DFS Inorder (left, node, right)
 * @param root
 * @return
 */
std::vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result{};

    if (root == nullptr) return result;

    stack<TreeNode *> stack;
    TreeNode *current = root;

    // Check current because left subtree can be empty or processed
    // but current moved to the right
    while (current != nullptr || !stack.empty()) {

        // Go all the way to the left
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // Process root
        current = stack.top();
        stack.pop();
        result.push_back(current->val);

        // Go to the right
        current = current->right;
    }

    return result;
}

/**
 * 145. Binary Tree Postorder Traversal (easy)
 * Helper method
 * @param root
 * @param result
 */
void postorder(TreeNode *root, std::vector<int> &result) {
    if (root == nullptr) { return; }

    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

/**
 * 145. Binary Tree Postorder Traversal (easy)
 * Recursive DFS Postorder (left, right, root)
 * @param root
 * @return
 */
vector<int> postorderTraversalRec(TreeNode *root) {
    vector<int> result{};
    postorder(root, result);
    return result;
}

/**
 * 145. Binary Tree Postorder Traversal (easy)
 * Iterative DFS Postorder (left, right, root)
 * @param root
 * @return
 */
std::vector<int> postorderTraversalIT(TreeNode *root) {
    std::vector<int> result{};

    // 0 case
    if (root == nullptr) { return result; }

    std::stack<TreeNode *> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode *current = nodeStack.top();
        nodeStack.pop();
        result.push_back(current->val);

        if (current->left != nullptr) {
            nodeStack.push(current->left);
        }
        if (current->right != nullptr) {
            nodeStack.push(current->right);
        }
    }

    // Reverse because (root, left, right = preorder)
    std::reverse(result.begin(), result.end());

    return result;
}

/**
 * 101. Symmetric Tree
 * Helper
 * @param root1
 * @param root2
 * @return
 */
bool traverseSubtree(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) { return true; }
    if (root1 == nullptr || root2 == nullptr) { return false; }

    // Already found wrong value so no further comparison of subtrees needed
    if (root1->val != root2->val) { return false; }

    // Note that we compare the opposite values
    bool left = traverseSubtree(root1->left, root2->right);
    bool right = traverseSubtree(root1->right, root2->left);

    return left && right;
}

/**
 * 101. Symmetric Tree
 * @param root
 * @return
 */
bool isSymmetric(TreeNode *root) {
    return traverseSubtree(root, root);
}


TreeNode *dfsInvert(TreeNode *parent) {
    // Exit condition
    if (parent == nullptr) { return parent; }

    // Node
    std::swap(parent->left, parent->right);
    // Left
    dfsInvert(parent->left);
    // Right
    dfsInvert(parent->right);

    return parent;
}

/**
 * 226. Invert Binary Tree
 * DFS Preorder
 * @param root
 * @return
 */
TreeNode *invertTree(TreeNode *root) {
    // Exit condition
    if (root == nullptr) { return root; }

    // Iteration steps
    // Processing node
    std::swap(root->left, root->right);
    // Left
    invertTree(root->left);
    // Right
    invertTree(root->right);

    // Return result
    return root;
}

/**
 * 112. Path Sum
 * DFS Inorder
 * @param root
 * @param targetSum
 * @return
 */
bool hasPathSum(TreeNode *root, int targetSum) {
    // 0 case - empty tree
    if (root == nullptr) {
        return false;
    }

    // Process
    targetSum -= root->val;

    // Exit condition
    // We found a leaf
    if (root->left == nullptr && root->right == nullptr) {
        return targetSum == 0;
    }

    // Iteration step
    bool left = false;
    bool right = false;
    // Left
    if (root->left) {
        left = hasPathSum(root->left, targetSum);
    }
    // Right
    if (root->right) {
        right = hasPathSum(root->right, targetSum);
    }

    // Because only one path needs to exist
    return left || right;
}

/**
 * 700. Search in a Binary Search Tree
 * @param root
 * @param val
 * @return
 */
TreeNode *searchBST(TreeNode *root, int val) {
    // Exit condition (base case)
    if (root == nullptr) { return root; }

    // We found the corresponding subtree
    if (root->val == val) { return root; }

    // Iteration step
    TreeNode *sub = searchBST(root->val > val ? root->left : root->right, val);

    // Prioritize returning correct node otherwise return nothing
    return sub && sub->val == val ? sub : nullptr;
}

/**
 * 701. Insert into a Binary Search Tree
 * @param root
 * @param val
 * @return
 */
TreeNode *insertIntoBST(TreeNode *root, int val) {
    // Base case
    if (root == nullptr) { return new TreeNode{val}; }

    // No duplicates allowed
    if (root->val == val) { return root; }

    // Iteration step
    if (root->val > val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}


void findTargetHelper(TreeNode* root, std::vector<int>& values) {
    if (root == nullptr) { return; }
    // Left
    findTargetHelper(root->left, values);
    // Process
    values.push_back(root->val);
    // Right
    findTargetHelper(root->right, values);
}

/**
 * 653. Two Sum IV - Input is a BST
 * Recursive Inorder DFS
 * @param root
 * @param k
 * @return
 */
bool findTarget(TreeNode* root, int k) {
    // Traverse tree and store values in vector
    std::vector<int> values;
    findTargetHelper(root, values);

    // Move pointers until combination is found
    int left = 0;
    int right = values.size() -1;

    while (left < right) {
        if (values[left] + values[right] > k) {
            right--;
        } else if (values[left] + values[right] < k) {
            left++;
        } else {
            return true;
        };
    }

    return false;
}

/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * @param root
 * @param p
 * @param q
 * @return
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

}

#endif //CPPBASICS_TREE_H
