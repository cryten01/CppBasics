
#ifndef CPPBASICS_DS03_LLSTACK_H
#define CPPBASICS_DS03_LLSTACK_H

#include "ds02_DoubleLinkedList.h"

template<typename T>
class LLStack {
public:
    LLStack() {}

    ~LLStack() {}

    void Push(T val) {
        m_container.Push(val);
    }

    void Pop() {
        m_container.Pop();
    }

    const T &Top() {
        LinkIterator<T> it;
        it = m_container.End();
        return *it;
    }

    int GetSize() {
        return m_container.GetSize();
    }

    int IsEmpty() {
        return m_container.GetSize() == 0;
    }

private:
    LinkList<T> m_container;
};

#endif //CPPBASICS_DS03_LLSTACK_H
