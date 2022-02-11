
#include "00_LinkedList.h"
#include <iostream>
#include <assert.h>

LinkedList::~LinkedList() {
    std::cout << "Deallocating memory" << std::endl;
    DeleteAll();
}

/**
 *
 */
void LinkedList::Init() {
    head = NULL;
}

/**
 * Creates a new node and stores data in it.
 * Note the last inserted data is always the head
 * @param data The data that needs to be inserted.
 */
void LinkedList::Insert(int data) {
    // Create new node
    Node *tempPtr = CreateNode(data);
    // Link it to head
    tempPtr->next = head;
    // Point to last inserted node
    head = tempPtr;
}

/**
 * Creates a new node and stores data in it after the given index.
 * @param index The index after that a new node should be created. Starts from head.
 * @param data The data of the node
 */
void LinkedList::InsertAfter(int index, int data) {
    int lastPossibleIndex = size - 1;
    if (lastPossibleIndex < 0 || index > lastPossibleIndex || index < 0) { return; }

    Node* prevNode = Get(index);
    Node* currentNode = CreateNode(data);

    currentNode->next = prevNode->next;
    prevNode->next = currentNode;
}

/**
 *
 * @param node
 */
void LinkedList::PrintNode(Node *node) {
    std::cout << "Node value: " << node->data << std::endl;
}

/**
 *
 */
void LinkedList::PrintAll() {
    Node *temp = head;

    while (temp != NULL) {
        PrintNode(temp);
        temp = temp->next;
    }
}

/**
 *
 */
void LinkedList::DeleteAll() {
    Node *temp = head;

    while (temp != NULL) {
        std::cout << "Deleting value " << temp->data << std::endl;
        temp = temp->next;
        delete temp;
    }
}

/**
 *
 * @param index
 * @param key
 */
void LinkedList::DeleteAt(int index, int key) {
}

/**
 *
 */
void LinkedList::Reverse() {

}

/**
 *
 * @param data
 * @return
 */
Node *LinkedList::CreateNode(int data) {
    // Generate node pointer and allocate memory on the heap
    Node *tempPtr = new Node;
    // Assign values
    tempPtr->data = data;
    tempPtr->next = NULL;
    // Increase list size if successful
    size++;
    // Return pointer to newly created node
    return tempPtr;
}

/**
 *
 * @param index The index the node is located at.
 * @return A nullptr for invalid indices and the node in every other case.
 */
Node *LinkedList::Get(int index) {
    // Check for invalid indices or empty list
    int lastIndex = size - 1;
    if (size == 0 || index < 0 || index > lastIndex) { return nullptr; }

    // Start from the head
    Node *temp = head;
    int currentIndex = 0;

    // Traverse the list until node at index is found
    while (currentIndex < index) {
        currentIndex++;
        temp = temp->next;
    }

    return temp;
}



