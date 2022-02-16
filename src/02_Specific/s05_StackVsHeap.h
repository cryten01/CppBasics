
#ifndef CPPBASICS_C02_STACKVSHEAP_H
#define CPPBASICS_C02_STACKVSHEAP_H

struct Vector3 {
    float x, y, z;

};

/**
 * Demonstrates how variables are created on the stack
 * Memory allocation is one CPU instruction
 * Moves pointer and then returns memory address
 * Packed data and therefore zero cache misses (relevant if millions)
 * Allocate on the stack as often as possible
 */
void AllocateOnStack() {
    int number = 5;

    int numberArray[5];
    for (int number : numberArray) {
        number = 1;
    }

    Vector3 vector;
    vector.x = 11;
    vector.y = 12;
    vector.z = 13;

    // As soon as scope is left variables on the stack are freed automatically
}

/**
 * Demonstrates how variables are created on the heap
 * New triggers memory allocation (malloc)
 * DeleteAt triggers (dealloc)
 * Allocate on the heap if lifetime needs to be longer than scope or for large data (that does not fit in the stack)
 */
void AllocateOnHeap() {
    int* number = new int;
    *number = 5;
    int* array = new int[5];
    Vector3* vector = new Vector3();

    // Manual memory deletion required!
    delete number;
    delete[] array;
    delete vector;
}

#endif //CPPBASICS_C02_STACKVSHEAP_H
