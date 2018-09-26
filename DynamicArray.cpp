
#include "DynamicArray.h"

DynamicArray::DynamicArray(int size) : size(size) {
    data = new int[size];
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

DynamicArray::~DynamicArray() {
    delete[] data;
}

