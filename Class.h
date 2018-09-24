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
#include <chrono>
#include <vector>
#include <fstream>

// reference to global variable in main.cpp, doesn't work with static variables
extern int reference;

// variable with limited range of values
enum Color {
    RED,
    GREEN,
    BLUE
};

class Class {

public:
    // represents a function prototype
    static void dataTypeOperations(int &param1, int param2);

    static void stringOperations();

    static void pointerOperations();

    static void memoryOperations();

    static void ioOperations();
};


#endif //C_BASICS_VARIABLES_H
