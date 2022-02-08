
#ifndef CPPBASICS_DS00_TEST_H
#define CPPBASICS_DS00_TEST_H

#include <cassert>

template<typename T>
class LinkIterator;

template<typename T>
class LinkList;


template<typename T>
class LinkNode {
    friend class LinkIterator<T>;

    friend class LinkList<T>;

private:
    T m_data;
    LinkNode *m_next;
    LinkNode *m_previous;
};

template<typename T>
class LinkIterator {
public:
    LinkIterator() {
        m_node = nullptr;
    }

    ~LinkIterator() {
    }

    void operator=(LinkNode<T> *node) {
        m_node = node;
    }

    T &operator*() {
        assert(m_node != nullptr);
        return m_node->m_data;
    }

    void operator++() {
        assert(m_node != nullptr);
        m_node = m_node->m_next;
    }

    void operator++(int) {
        assert(m_node != nullptr);
        m_node = m_node->m_next;
    }

    void operator--() {
        assert(m_node != nullptr);
        m_node = m_node->m_previous;
    }

    void operator--(int) {
        assert(m_node != nullptr);
        m_node = m_node->m_previous;
    }

    bool operator!=(LinkNode<T> *node) {
        return (m_node != node);
    }

    bool operator==(LinkNode<T> *node) {
        return (m_node == node);
    }

private:
    LinkNode<T> *m_node;
};


template<typename T>
class LinkList {
public:
    LinkList() : m_size(0), m_root(0), m_lastNode(0) {
    }

    ~LinkList() {
        while (m_root != nullptr) {
            Pop();
        }
    }

    LinkNode<T> *Begin() {
        assert(m_root != nullptr);
        return m_root;
    }

    LinkNode<T> *End() {
        return m_lastNode;
    }

    void Push(T newData) {
        // Create new node on the heap
        LinkNode<T> *node = new LinkNode<T>;

        // Sanity check
        assert(node != nullptr);

        // Set node member variables
        node->m_data = newData;
        node->m_next = nullptr;
        node->m_previous = nullptr;

        // Check if we already have a root
        if (m_lastNode != nullptr) {

            // If so link old root with new root
            m_lastNode->m_next = node;

            // Also link new root with old root
            node->m_previous = m_lastNode;

            // Finally, define new root
            m_lastNode = node;

        } else {
            // As the list only contains 1 node the root and last node are identical
            m_root = node;
            m_lastNode = node;
        }

        // Increase size of linked list
        m_size++;
    }

    void PushFront(T newData) {
        // Create new node on the heap
        LinkNode<T> *node = new LinkNode<T>;

        // Sanity check
        assert(node != nullptr);

        // Set node member variables
        node->m_data = newData;
        node->m_next = nullptr;
        node->m_previous = nullptr;

        // Check if we already have a root
        if (m_root != nullptr) {

            // If so link new root with old root
            node->m_next = m_root;

            // Also link old root with new root
            m_root->m_previous = node;

            // Finally, define new root
            m_root = node;

        } else {
            // As the list only contains 1 node the root and last node are identical
            m_root = node;
            m_lastNode = node;
        }

        // Increase size of linked list
        m_size++;
    }

    void Pop() {
        // Sanity check
        assert(m_root != nullptr);

        // Check if list only has 1 node
        if (m_root->m_next == nullptr) {

            // Delete data at which the pointer is pointing to
            delete m_root;

            // Set to nullptr to reset the pointer
            m_root = nullptr;

        } else {
            // Get node 1 before last
            LinkNode<T> *prevNode = m_lastNode->m_previous;

            // Delete data at which the pointer is pointing to
            delete m_lastNode;

            // Reset this pointer because it is pointing to nowhere
            prevNode->m_next = nullptr;

            // Set new last node
            m_lastNode = prevNode;
        }

        // Decrease size if not 0
        m_size = (m_size == 0 ? m_size : m_size - 1);
    }

    void PopFront() {
        // Sanity check
        assert(m_root != nullptr);

        // Create a temporary pointer for later deleting the content at the given memory address
        LinkNode<T> *temp = m_root;

        // Retarget pointer to next element in the list (can be nullptr)
        m_root = m_root->m_next;

        // Check if list still has 1 node
        if(m_root != nullptr) {

            // If so, this element is now pointing into nowhere
            m_root->m_previous = nullptr;
        }

        // Delete actual data stored at this location
        delete temp;

        // Decrease size if not 0
        m_size = (m_size == 0 ? m_size : m_size - 1);
    }

    int GetSize() {
        return m_size;
    }

private:
    int m_size;
    LinkNode<T> *m_root;
    LinkNode<T> *m_lastNode;
};

#endif //CPPBASICS_DS00_TEST_H
