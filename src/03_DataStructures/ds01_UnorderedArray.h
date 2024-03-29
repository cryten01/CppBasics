
#ifndef CPPBASICS_DS01_UNORDEREDARRAY_H
#define CPPBASICS_DS01_UNORDEREDARRAY_H

#include <iostream>

template<class T>
class UnorderedArray {
public:
    UnorderedArray(int size, int growBy = 1) :
            m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0) {

        // Only initialize array if size is defined
        if (size) {
            m_maxSize = size;
            m_array = new T[m_maxSize];
            m_growSize = ((growBy > 0) ? growBy : 0);
        }
    };

    virtual ~UnorderedArray() {
        if (m_array != NULL) {
            delete[] m_array;

            // Avoids double deletes and undefined behaviour
            m_array = NULL;
        }
    }

    virtual void Push(T val) {
        assert(m_array != NULL);

        if (m_numElements >= m_maxSize) {
            Expand();
        }

        m_array[m_numElements] = val;
        m_numElements++;
    }

    void Pop() {
        if (m_numElements > 0) {
            m_numElements--;
        }
    }

    void Remove(int index) {
        assert(m_array != NULL);

        if (index >= m_maxSize) {
            return;
        }

        for (int k = index; k < m_maxSize - 1; k++) {
            m_array[k] = m_array[k + 1];
        }

        m_maxSize--;

        if (m_numElements >= m_maxSize) {
            m_numElements = m_maxSize - 1;
        }
    }

    virtual T &operator[](int index) {
        assert(m_array != NULL && index <= m_numElements);
        return m_array[index];
    }

    virtual int Search(T val) {
        assert(m_array != NULL);

        for (int i = 0; i < m_numElements; i++) {
            if (m_array[i] == val)
                return i;
        }

        return -1;
    }

    void Clear() { m_numElements = 0; }

    int GetSize() { return m_numElements; }

    int GetMaxSize() { return m_maxSize; }

    int GetGrowSize() { return m_growSize; }

    void SetGrowSize(int val) {
        assert(val >= 0);
        m_growSize = val;
    }

private:
    T *m_array;

    int m_maxSize;
    int m_growSize;
    int m_numElements; // Also shows where to insert the next item

    bool Expand() {
        if (m_growSize <= 0)
            return false;
        T *temp = new T[m_maxSize + m_growSize];
        assert(temp != NULL);
        memcpy(temp, m_array, sizeof(T) * m_maxSize);
        delete[] m_array;
        m_array = temp;
        m_maxSize += m_growSize;
        return true;
    }
};

#endif //CPPBASICS_DS01_UNORDEREDARRAY_H
