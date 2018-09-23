// Tutorial last Stand: 50

#pragma once // loads header this file only once

#include <iostream>
#include "Class.h"
#include "Preprocessor.h"

// global variable
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


int main() {

    // Class::function() represents a namespace
    Preprocessor::demonstration();
    Class::variableOperations(reference, 2);
    Class::stringOperations();
    Class::memoryOperations();
    Class::pointerOperations();

    functionTemplates("Hello");
    functionTemplates(10);


    // 0 means correct execution here
    return 0;
}