
#ifndef CPPBASICS_DS06_TREE_H
#define CPPBASICS_DS06_TREE_H

class Node {
public:
    Node(int obj) : m_object(obj), m_next(NULL),
                    m_prev(NULL), m_child(NULL) {
        std::cout << "Node created!" << std::endl;
    }

    ~Node() {
        m_prev = NULL;
        if (m_child != NULL)
            delete m_child;

        if (m_next != NULL)
            delete m_next;
        m_child = NULL;
        m_next = NULL;
        std::cout << "Node deleted" << std::endl;
    }

    void AddSibling(Node *node) {
        Node *ptr = m_next;

        if (m_next == NULL) {
            m_next = node;
            node->m_prev = this;
        } else {
            while (ptr->m_next != NULL) {
                ptr = ptr->m_next;
            }
            ptr->m_next = node;
            node->m_prev = ptr;
        }
    }

    void AddChild(Node *node) {
        if (m_child == NULL) {
            m_child = node;
        } else {
            m_child->AddSibling(node);
        }
    }

    void DisplayTree() {
        std::cout << m_object;

        if (m_next != NULL) {
            std::cout << " ";
            m_next->DisplayTree();
        }

        if (m_child != NULL) {
            std::cout << std::endl;
            m_child->DisplayTree();
        }
    }

    bool Search(int value) {
        if (m_object == value)
            return true;

        if (m_child != NULL) {
            if (m_child->Search(value) == true)
                return true;
        }

        if (m_next != NULL) {
            if (m_next->Search(value) == true)
                return true;
        }

        return false;
    }

private:
    int m_object;
    Node *m_next, *m_prev, *m_child;
};

#endif //CPPBASICS_DS06_TREE_H
