// .h -> Header file separates the actual implementation from the declaration, (+) easier to read, (+) hide details

#ifndef C_BASICS_VARIABLES_H
#define C_BASICS_VARIABLES_H

// <>  predefined libraries
// C   libraries = library.h,
// C++ libraries = clibrary
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

// reference to global variable in main.cpp, doesn't work with static variables
extern int reference;

class Class {

public:
    // represents a function prototype
    static void variableTypes(int &param1, int param2);

    static void stringOperations();
};


#endif //C_BASICS_VARIABLES_H
