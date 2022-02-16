//#include <iostream>
//#include "02_Specific/SpecificConcepts.h"
//#include "03_DataStructures/STLContainers.h"
//#include "04_Algorithms/STLAlgorithms.h"

// Brotcruncher tutorial last Stand: 110 (66-76, 101-103, 107 skipped) - 122
// Avoid undefined behaviour otherwise different behaviour in debug/release possible

// int and struct share same ram space, means if int changes also struct changes
union myColor {
    struct {
        // reverse because bytes in ram are reversed
        unsigned char a, b, g, r;
    };
    unsigned int rgba;
};

// Global variable
int reference = 1;

// Concepts::function() represents a namespace
//    Concepts::dataTypeOperations(reference, 2);

// // in C++ method is called based on variable not nearest class
// SuperclassA *superclassPtr = new Concepts();
// superclassPtr->baseMethod();

// try {
//     DynamicArray array1(100);
//     array1[5] = 100;
//     DynamicArray array2(120);
//     // Makes use of + operator overloading, (-) slow
//     DynamicArray result = array1 + array2;

//     // Use of = operator overloading
//     array1 = array2;
// } catch (int e) {
//     std::cout << "Int Exception caught!" << std::endl;
// }

//    myColor color;
//    color.rgba = 0xFFC080AA;
//    std::cout << +color.r << " " << +color.g << " " << +color.b << " " << +color.a << std::endl;
