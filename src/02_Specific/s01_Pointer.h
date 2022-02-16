
#ifndef CPPBASICS_C01_POINTER_H
#define CPPBASICS_C01_POINTER_H

#include <memory>

void ShowRawPointer() {
    // 0, NULL, nullptr all means invalid memory address
    // Types are needed for byte size so that sufficient memory is allocated during de-referencing
    void *typelessPointer = nullptr;

    // The integer value itself
    int myInt = 100;
    // A type specific pointer currently pointing to nothing (valid state)
    int *intPtr = nullptr;
    // & on left side = reference, & on right side = storage location
    intPtr = &myInt;
    // Changes value of myInt to 15.
    // For de-referencing * is always needed to pointed value, otherwise intPtr itself gets overwritten!
    *intPtr = 15;
}

/**
 * Recommended to understand Stack vs Heap first
 * Wrapper around raw pointer. Automatically (de)allocates memory
 */
void ShowSmartPointer() {
    // A unique pointer guarantees that only pointer uniquePtr is pointing to this int
    // Also called scoped pointer because destroyed when out of scope
    std::unique_ptr<int> uniquePtr = std::make_unique<int>();

    // Shared pointer destroys dynamically allocated int after no other shared pointer is pointing to
    // Uses reference counter to count the nr of pointers
    // If unique pointer does not suffice
    std::shared_ptr<int> sharedPtr = std::make_shared<int>();

    // Weak pointer does not increase reference count.
    // Good when not taking ownership (e.g. storing list of references that do not need to be alive)
    std::weak_ptr<int> weakPtr = sharedPtr;
}

// Generates a new int called copy, increases it by 1 and returns it
int IncreaseCopy(int copy) {
    return copy++;
}

// Dereferences a pointer and returns it increased value
int IncreaseValueAtMemoryAddress(int* ptr) {
    // Dereference first then increase, otherwise memory address would be increased
    return (*ptr)++;
}

// Identical to IncreaseValueAtMemoryAddress but syntactically easier
int IncreaseReference(int& ref) {
    return ref++;
}

void ShowReferences() {
    int number = 5;
    int number2 = 6;

    // References have to be initialized at declaration
    // Does not consume memory. Represents an alias not a real variable
    int &ref = number;

    // You cannot change the reference later
    int& ref2 = number2;
    // Changes the value of number2 to 5 but not changes reference!
    ref2 = number;


    IncreaseCopy(number);
    IncreaseReference(number);
    IncreaseValueAtMemoryAddress(&number);
}




#endif //CPPBASICS_C01_POINTER_H
