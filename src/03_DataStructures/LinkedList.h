
#ifndef CPPBASICS_DS01_LINKEDLIST_H
#define CPPBASICS_DS01_LINKEDLIST_H

// Required concepts: Classes, Pointers, Stack vs Heap

struct Node {
    int data;
    Node *next;
};

class LinkedList {
public:
    virtual ~LinkedList();

    void Init();
    void Insert(int data);
    void InsertAfter(int index, int data);
    void Delete(int key);
    void DeleteAt(int index, int key);
    void DeleteAll();
    void Reverse();
    void PrintAll();
    void Length();
    Node* Get(int index);

public:
    Node *head;
    int size;

    Node* CreateNode(int data);
    void PrintNode(Node* node);
};

#endif //CPPBASICS_DS01_LINKEDLIST_H
