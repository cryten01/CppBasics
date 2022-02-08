
#include "00_OrderedArray.h"

OrderedArray::OrderedArray(int size, int growBy) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0) {
    if (size) {
        m_maxSize = size;
        m_array = new int[m_maxSize];
        m_growSize = ((growBy > 0) ? growBy : 0);
    }
}

OrderedArray::~OrderedArray() {
    if (m_array != NULL) {
        delete[] m_array;
        m_array = NULL;
    }
}

int OrderedArray::Push(int val) {
    // Increase arrayPtr size if already full
    if (m_numElements >= m_maxSize) {
        Expand();
    }

    // Figure out where to store the new value
    int index = 0;
    for (int i = index; i < m_numElements; i++) {
        if (m_array[i] > val) {
            index = i;
            break;
        }
    }

    // Move all bigger elements on position up
    for (int k = m_numElements; k > index; k--) {
        m_array[k] = m_array[k - 1];
    }

    // Assign value to given slot
    m_array[index] = val;

    // Increase element size
    m_numElements++;

    // Return the index where the value is stored
    return index;
}

void OrderedArray::Pop() {
    // Values still exist in memory but cannot be accessed any more
    if (m_numElements > 0) {
        m_numElements--;
    }
}

void OrderedArray::Remove(int index) {
    // Out of bounds
    if (index >= m_maxSize) {
        return;
    }

    // Loop through all elements starting at the given index
    // and move them 1 pos before
    for (int k = index; k < m_maxSize - 1; k++) {
        m_array[k] = m_array[k + 1];
    }

    // Decrease size as we removed one element
    m_maxSize--;

    // Sync both variables
    if (m_numElements >= m_maxSize) {
        m_numElements = m_maxSize - 1;
    }
}

void OrderedArray::Clear() {
    m_numElements = 0;
}

bool OrderedArray::Expand() {
    // Return if no growing is allowed
    if (m_growSize <= 0) {
        return false;
    }
    // Create a new arrayPtr on the heap
    int *temp = new int[m_maxSize + m_growSize];

    // Copy the old arrayPtr in the new arrayPtr
    memcpy(temp, m_array, sizeof(int) * m_maxSize);

    // Delete the old arrayPtr
    delete[] m_array;

    // Set the new arrayPtr
    m_array = temp;

    // Adjust size
    m_maxSize += m_growSize;

    // Return successful operation
    return true;
}

int OrderedArray::getMMaxSize() const {
    return m_maxSize;
}

int OrderedArray::getMGrowSize() const {
    return m_growSize;
}

int OrderedArray::getMNumElements() const {
    return m_numElements;
}
