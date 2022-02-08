
#ifndef CMAKETEST_ORDEREDARRAY_H
#define CMAKETEST_ORDEREDARRAY_H

#include <iostream>

// Required concepts: Classes, Pointers, Stack vs Heap, TemplateClass,
// Operator overloads, virtual, const

class OrderedArray {
public:
    OrderedArray(int size, int growBy = 1);

    ~OrderedArray();

    int Push(int val);

    void Pop();

    void Remove(int index);

    void Clear();

    virtual const int &operator[](int index) {
        assert(m_array != NULL && index <= m_numElements);
        return m_array[index];
    };
private:
    int *m_array;

    int m_maxSize;
public:
    int getMMaxSize() const;

    int getMGrowSize() const;

    int getMNumElements() const;

private:
    int m_growSize;
    int m_numElements;

    bool Expand();
};

#endif //CMAKETEST_ORDEREDARRAY_H
