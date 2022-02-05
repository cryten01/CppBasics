// .h -> Header file separates the actual implementation from the declaration, (+) easier to read, (+) hide details

#pragma once // loads header this file only once
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
#include <memory>
#include "SuperclassA.h"

// reference to global variable in main.cpp, doesn't work with static variables
extern int reference;

// variable with limited range of values
enum Color {
    RED,
    GREEN,
    BLUE
};


class A {
    virtual void doSmth() {};
public:
    virtual ~A() {
        std::cout << "Destructor of Class A called!" << std::endl;
    }
};

// Basic Inheritance
class B : public A {
};

class C : public A {
};


// Public inheritance in 99,9%
// Protected / private inheritance makes all attributes and methods of superclass protected/private
// Multiple inheritance, no interfaces possible in C++, problematic with variables of same name
// virtual prevents deadly diamond
class Concepts : public virtual SuperclassA, public virtual SuperclassB {

public:
    // represents a function prototype
    static void dataTypeOperations(int &param1, int param2);

    static void stringOperations();

    static void pointerOperations();

    static void memoryOperations();

    static void ioOperations();

    static void dynamicCast();

    static void reinterpretCast();

    static void smartPointer();

    // represents an override
    void baseMethod() override;
};


#endif //C_BASICS_VARIABLES_H
