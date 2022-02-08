
#ifndef CPPBASICS_DS04_DEQUEUE_H
#define CPPBASICS_DS04_DEQUEUE_H

#include "ds02_DoubleLinkedList.h"

template<typename T>
class Dequeue {
public:
    Dequeue(int size = 10) {
        assert(size > 0);
        m_size = size;
    }

    virtual ~Dequeue() {}

    void PushBack(T val) {
        if (m_container.GetSize() >= m_size) return;
        m_container.Push(val);
    }

    void PushFront(T val) {
        if (m_container.GetSize() >= m_size) return;
        m_container.PushFront(val);
    }

    void PopBack() {
        m_container.PopFront();
    }

    void PopFront() {
        m_container.Pop();
    }

    const T &Front() {
        LinkIterator<T> it;
        it = m_container.End();
        return *it;
    }

    const T &Back() {
        LinkIterator<T> it;
        it = m_container.Begin();
        return *it;
    }

    int GetSize() {
        return m_container.GetSize();
    }

    int GetMaxSize() {
        return m_size;
    }

    bool IsEmpty() {
        return m_container.GetSize() == 0;
    }

    void Resize(int size) {
        assert(size > 0);
        m_size = size;
    }

private:
    LinkList<T> m_container;
    int m_size;
};

#endif //CPPBASICS_DS04_DEQUEUE_H
