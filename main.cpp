// Tutorial last Stand: 76 (66-76 skipped)

// Avoid undefined behaviour otherwise different behaviour in debug/release possible

#pragma once // loads header this file only once

#include <iostream>
#include "Class.h"
#include "Preprocessor.h"
#include "DynamicArray.h"

// Global variable
int reference = 1;

// Template: represents a function template where the compiler inserts the data type dependent on input
template<typename T>
void functionTemplates(T attrib) {
    std::cout << attrib << std::endl;
}

// Template specialization: replaces T with int and changes function body
template<>
void functionTemplates(int attrib) {
    std::cout << "I'm an integer" << std::endl;
}

// argc = how many program arguments
// argv = array of program arguments
int main(int argc, char* argv[]) {

    // Class::function() represents a namespace
    Preprocessor::demonstration();
    Class::dataTypeOperations(reference, 2);
    Class::stringOperations();
    Class::memoryOperations();
    Class::pointerOperations();
    Class::ioOperations();

    functionTemplates("Hello");
    functionTemplates(10);

    DynamicArray array(100);
    array.set(5, 100);
    std::cout << array.get(5) << std::endl;

    // 0 means correct execution here
    return 0;
}