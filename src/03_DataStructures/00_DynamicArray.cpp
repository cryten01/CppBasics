
#include <iostream>
#include "00_DynamicArray.h"

DynamicArray::DynamicArray(int size) : size(size) {
//    (*this).size = size // this in C++ is a pointer to own object. Dereferencing in order to access value
//    this->size = size; // "pointer->" is the short form of (*this).size
    data = new int[size];
}

DynamicArray::DynamicArray(const DynamicArray &other) {
    size = other.size;
    data = new int[size];

    // Copies array values
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DynamicArray::DynamicArray(DynamicArray &&other) {
    data = other.data;
    size = other.size;
    other.data = nullptr; // prevents destructor from accessing other
}

DynamicArray::DynamicArray() {
    size = 10;
    data = new int[size];
}

int DynamicArray::get(int index) const {
    return data[index];
}

int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::set(int index, int value) {
    data[index] = value;
}


int &DynamicArray::operator[](int index) {
    return data[index];
}

DynamicArray DynamicArray::operator+(const DynamicArray &other) {
    if (size != other.size) {
        // Exception handling in C++ can throw everything, crash only if not catched
        throw 1;
    }

    DynamicArray retVal(size);
    for (int i = 0; i < size; ++i) {
        retVal[i] = data[i] + other.data[i];
    }
    return retVal;
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
    if (&other == this) return *this;

    if (other.size != size) {
        delete[] data;
        size = other.size;
        data = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray &&other) {
    if (&other == this) return *this;

    delete[] data;
    data = other.data;
    other.data = nullptr;

    return *this;
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

