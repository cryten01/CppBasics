
#ifndef CPPBASICS_DS03_UASTACK_H
#define CPPBASICS_DS03_UASTACK_H

#include "ds01_UnorderedArray.h"

// Required concepts: templates, generics, initializer lists

template<typename T>
class UAStack {
public:
    UAStack(int size, int growBy = 1) {
        assert(size > 0 && growBy >= 0);

        m_container = new UnorderedArray<T>(size, growBy);

        assert(m_container != nullptr);
    }

    ~UAStack() {
        if (m_container != nullptr) {
            delete m_container;
            m_container = nullptr;
        }
    }

    void Push(T val) {
        assert(m_container != nullptr);
        m_container->Push(val);
    }

    void Pop() {
        assert(m_container != nullptr);
        m_container->Pop();
    }

    const T &Top() {
        assert(m_container != nullptr);
        return (*m_container)[m_container->GetMaxSize() - 1];
    }

    int GetSize() {
        assert(m_container != nullptr);
        return m_container->GetSize();
    }

    int GetMaxSize() {
        assert(m_container != nullptr);
        return m_container->GetMaxSize();
    }

    int IsEmpty() {
        assert(m_container != nullptr);
        return (m_container->GetSize() == 0);
    }

    int IsFull() {
        assert(m_container != nullptr);
        return (Top() == m_container->GetMaxSize() - 1);
    }

private:
    UnorderedArray<T> *m_container;
};

#endif //CPPBASICS_DS03_UASTACK_H
