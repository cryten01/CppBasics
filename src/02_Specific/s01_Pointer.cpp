
#include <memory>
#include "s01_Pointer.h"

void PointerExample::ShowRawPointer() {
    // 0, NULL, nullptr all means invalid memory address
    // Types are needed for byte size so that sufficient memory is allocated during de-referencing
    void* typelessPointer = nullptr;

    // The integer value itself
    int myInt = 100;
    // A type specific pointer currently pointing to nothing (valid state)
    int* intPtr = nullptr;
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
void PointerExample::ShowSmartPointer() {
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
