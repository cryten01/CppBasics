
#ifndef CPPBASICS_DS05_HASHTABLE_H
#define CPPBASICS_DS05_HASHTABLE_H

#include <iostream>

template<typename T>
class HashItem {
public:
    HashItem() : m_key(-1) {}

    ~HashItem() {}

    int GetKey() { return m_key; }

    void SetKey(int k) { m_key = k; }

    T GetObject() { return m_obj; }

    void SetObj(T obj) { m_obj = obj; }

    bool operator==(HashItem &item) {
        if (m_key == item.GetKey())
            return true;
        return false;
    }

    void operator=(HashItem item) {
        m_key = item.GetKey();
        m_obj = item.GetObject();
    }

private:
    int m_key;
    T m_obj;
};


template<typename T>
class HashTable {
public:
    HashTable(int size) : m_size(0), m_totalItems(0) {
        if (size > 0) {
            m_size = GetNextPrimeNum(size);
            m_table = new HashItem<T>[m_size];
        }
    }

    ~HashTable() {
        if (m_table != nullptr) {
            delete[] m_table;
            m_table = nullptr;
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

    bool Insert(int key, T &obj) {
        // Check if table is already full
        if (m_totalItems == m_size)
            return false;

        // Generate hash for array position
        int hash = HashFunction(key);

        // Generate hash for step
        int step = HashFunction2(key);

        // Check for empty spot
        while (m_table[hash].GetKey() != -1) {

            // Step by generated hash value
            hash += step;

            // Adjust hash value
            hash %= m_size;
        }

        // Set key and object
        m_table[hash].SetKey(key);
        m_table[hash].SetObj(obj);

        // Increase element size
        m_totalItems++;

        // Insertion was successful
        return true;
    }

    void Delete(int key) {
        // Generate hashes
        int hash = HashFunction(key);
        int step = HashFunction2(key);

        // Store original hash for later references
        int originalHash = hash;

        // Loop until we found a non-empty array position
        while (m_table[hash].GetKey() != -1) {

            // If key exists at this position
            if (m_table[hash].GetKey() == key) {

                // Invalidate key
                m_table[hash].SetKey(-1);

                // Decrease number of items and return
                m_totalItems--;
                return;
            }

            // Step by generated hash value
            hash += step;
            // Adjust hash value
            hash %= m_size;

            // Compare hashes (avoids infinite loops?)
            if (originalHash == hash) {
                return;
            }
        }
    }

    bool Find(int key, T *obj) {
        int hash = HashFunction(key);
        int step = HashFunction2(key);
        int originalHash = hash;

        while (m_table[hash].GetKey() != -1) {

            // If key exists at this position
            if (m_table[hash].GetKey() == key) {

                // If obj exists
                if (obj != nullptr) {
                    // Set pointer value to found obj (for checking purposes?)
                    *obj = m_table[hash].GetObject();
                }
                return true;
            }

            // Step by generated hash value and adjust hash
            hash += step;
            hash %= m_size;

            // Compare hashes (avoids infinite loops?)
            if (originalHash == hash) {
                return false;
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

    int HashFunction2(int key) {
        return 3 - key % 3;
    }

    int GetSize() {
        return m_size;
    }

    int GetTotalItems() {
        return m_totalItems;
    }

private:
    HashItem<T> *m_table;
    int m_size, m_totalItems;
};

#endif //CPPBASICS_DS05_HASHTABLE_H
