
#ifndef CPPBASICS_DS05_LLHASHTABLE_H
#define CPPBASICS_DS05_LLHASHTABLE_H

#include <list>

template<typename T>
class LLHashTable {
public:
    LLHashTable(int size) : m_size(0) {
        if (size > 0) {
            m_size = GetNextPrimeNum(size);
            m_table = new std::list<HashItem<T> >[m_size];
        }
    }

    bool isNumPrime(int val) {
        for (int i = 2; (i * i) <= val; i++) {
            if ((val % i) == 0)
                return false;
        }
        return true;
    }

    int GetNextPrimeNum(int val) {
        int prime;
        for (int i = val + 1;; i++) {
            if (isNumPrime(i)) {
                prime = i;
                break;
            }
        }
        return prime;
    }

    void Insert(int key, T &obj) {
        // No if array is full check needed
        // No check for empty spot
        // No second hash needed
        // No bool return value

        // Generate hash item
        HashItem<T> item;
        item.SetKey(key);
        item.SetObj(obj);

        // Generate hash for array position
        int hash = HashFunction(key);

        // Now entire item gets pushed into linked list
        m_table[hash].push_back(item);
    }

    void Delete(int key) {
        // No if array is full check needed
        // No check for empty spot
        // No second hash needed
        // No bool return value

        // Generate hash for array position
        int hash = HashFunction(key);

        // Generate pointer to linked list stored at given hash index
        std::list<HashItem<T> > *linkedListPtr = &m_table[hash];

        // Create typename alias
        typename std::list<HashItem<T> >::iterator it;

        // Iterate through linked list
        for (it = linkedListPtr->begin(); it != linkedListPtr->end(); it++) {

            // Check if key was found
            if ((*it).GetKey() == key) {

                // Erase item
                linkedListPtr->erase(it);

                // We already found the item
                break;
            }
        }
    }

    bool Find(int key, T *obj) {
        // No if array is full check needed
        // No check for empty spot
        // No second hash needed
        // No bool return value

        int hash = HashFunction(key);

        // Generate pointer to linked list stored at given hash index
        std::list<HashItem<T> > *linkedListPtr = &m_table[hash];

        // Create typename alias
        typename std::list<HashItem<T> >::iterator it;

        // Iterate through linked list
        for (it = linkedListPtr->begin(); it != linkedListPtr->end(); it++) {

            // Check if key was found
            if ((*it).GetKey() == key) {

                // Check if object exists
                if (obj != nullptr) {

                    // Store object into parameter
                    *obj = (*it).GetObject();
                }

                // Successful
                return true;
            }
        }

        // Entry was not found
        return false;
    }

    int HashFunction(int key) {
        return key % m_size;
    }

    int HashFunction(std::string &str) {
        int hash = 0;
        for (int i = 0; i < (int) str.size(); i++) {
            int val = (int) str[i];
            hash = (hash * 256 + val) % m_size;
        }
        return hash;
    }

    int GetSize() {
        return m_size;
    }

private:
    std::list<HashItem<T>> *m_table;
    int m_size;

    // No tracking of total items needed any more
};

#endif //CPPBASICS_DS05_LLHASHTABLE_H
