
#ifndef CPPBASICS_DS06_BST_H
#define CPPBASICS_DS06_BST_H

template<typename T>
class BinaryTree;

template<typename T>
class BSTNode {
    friend BinaryTree<T>;
public:
    BSTNode(T key) : m_key(key), m_left(NULL), m_right(NULL) {
    }

    ~BSTNode() {
        if (m_left != NULL) {
            delete m_left;
            m_left = NULL;
        }
        if (m_right != NULL) {
            delete m_right;
            m_right = NULL;
        }
    }

    T GetKey() {
        return m_key;
    }

private:
    T m_key;
    BSTNode *m_left, *m_right;
};


template<typename T>
class BinaryTree {
public:
    BinaryTree() : m_root(NULL) {
    }

    ~BinaryTree() {
        if (m_root != NULL) {
            delete m_root;
            m_root = NULL;
        }
    }

    bool Push(T key) {
        // Generate new node
        BSTNode<T> *newNode = new BSTNode<T>(key);

        // Case no root
        if (m_root == NULL) {
            m_root = newNode;
        }
        // Case root exists
        else {
            BSTNode<T> *parentNode = NULL;
            BSTNode<T> *currentNode = m_root;

            // Loop through entire tree
            while (1) {
                parentNode = currentNode;

                // Check for duplicates
                if (key == currentNode->m_key) {
                    delete newNode;
                    return false;
                }

                // Check if key is smaller or bigger
                if (key < currentNode->m_key) {
                    currentNode = currentNode->m_left;
                    // Insert element if leaf was found
                    if (currentNode == NULL) {
                        parentNode->m_left = newNode;
                        return true;
                    }
                } else {
                    currentNode = currentNode->m_right;
                    // Insert element if leaf was found
                    if (currentNode == NULL) {
                        parentNode->m_right = newNode;
                        return true;
                    }
                }
            }
        }
        return true;
    }

    bool Search(T key) {
        // Nothing to search
        if (m_root == NULL) {
            return false;
        }

        BSTNode<T> *currentNode = m_root;

        while (currentNode->m_key != key) {
            if (key < currentNode->m_key) {
                currentNode = currentNode->m_left;
            } else {
                currentNode = currentNode->m_right;
            }

            if (currentNode == NULL) {
                return false;
            }
        }

        return true;
    }

    void Remove(T key) {
        // Nothing to delete
        if (m_root == NULL) {
            return;
        }

        BSTNode<T> *parent = m_root;
        BSTNode<T> *node = m_root;
        bool isLeftNode = false;

        // Loop until you found the key
        while (node->m_key != key) {
            parent = node;

            if (key < node->m_key) {
                node = node->m_left;
                isLeftNode = true;
            } else {
                node = node->m_right;
                isLeftNode = false;
            }

            if (node == NULL) {
                return;
            }
        }

        // Actual deletion
        if (node->m_left == NULL && node->m_right == NULL) {
            if (node == m_root)
                m_root = NULL;
            else if (isLeftNode == true)
                parent->m_left = NULL;
            else
                parent->m_right = NULL;
        } else if (node->m_left == NULL) {
            if (node == m_root)
                m_root = node->m_right;
            else if (isLeftNode == true)
                parent->m_left = node->m_right;
            else
                parent->m_right = node->m_right;
        } else if (node->m_right == NULL) {
            if (node == m_root)
                m_root = node->m_left;
            else if (isLeftNode == true)
                parent->m_left = node->m_left;
            else
                parent->m_right = node->m_left;
        } else {
            BSTNode<T> *tempNode = node->m_right;
            BSTNode<T> *successor = node;
            BSTNode<T> *successorParent = node;
            while (tempNode != NULL) {
                successorParent = successor;
                successor = tempNode;
                tempNode = tempNode->m_left;
            }
            if (successor != node->m_right) {
                successorParent->m_left = successor->m_right;
                successor->m_right = node->m_right;
            }
            if (node == m_root) {
                m_root = successor;
            } else if (isLeftNode) {
                node = parent->m_left;
                parent->m_left = successor;
            } else {
                node = parent->m_right;
                parent->m_right = successor;
            }
            successor->m_left = node->m_left;
        }

        // Nullify so the destructor does not delete any nodes
        // they might point to.
        node->m_left = NULL;
        node->m_right = NULL;
        delete node;
    }

    void DisplayPreOrder() {
        DisplayPreOrder(m_root);
    }

    void DisplayPostOrder() {
        DisplayPostOrder(m_root);
    }

    void DisplayInOrder() {
        DisplayInOrder(m_root);
    }

private:
    void DisplayPreOrder(BSTNode<T> *node) {
        if (node != NULL) {
            std::cout << node->m_key << " ";
            DisplayPreOrder(node->m_left);
            DisplayPreOrder(node->m_right);
        }
    }

    void DisplayPostOrder(BSTNode<T> *node) {
        if (node != NULL) {
            DisplayPostOrder(node->m_left);
            DisplayPostOrder(node->m_right);
            std::cout << node->m_key << " ";
        }
    }

    void DisplayInOrder(BSTNode<T> *node) {
        if (node != NULL) {
            DisplayInOrder(node->m_left);
            std::cout << node->m_key << " ";
            DisplayInOrder(node->m_right);
        }
    }

private:
    BSTNode<T> *m_root;
};

#endif //CPPBASICS_DS06_BST_H
