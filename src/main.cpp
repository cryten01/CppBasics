// Tutorial last Stand: 110 (66-76, 101-103, 107 skipped) - 122

// Avoid undefined behaviour otherwise different behaviour in debug/release possible

#include <iostream>
#include "Concepts.h"
#include "Preprocessor.h"
#include "DynamicArray.h"
#include "Templates.h"
#include "Container.h"

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



// argc = how many program arguments
// argv = array of program arguments
int main(int argc, char *argv[]) {

    // Concepts::function() represents a namespace
//    Preprocessor::demonstration();
//    Concepts::dataTypeOperations(reference, 2);
//    Concepts::stringOperations();
//    Concepts::memoryOperations();
//    Concepts::pointerOperations();
//    Concepts::ioOperations();
//    Concepts::dynamicCast();
//    Concepts::smartPointer();


    Container container;
    container.iterator();


    Templates<int> a1(10);
    Templates<char *> a2("String");

    std::cout << "** " << a1.getData() << std::endl;
    std::cout << "** " << a2.getData() << std::endl;

    functionTemplates("Hello");
    functionTemplates(10);


    // in C++ method is called based on variable not nearest class
    SuperclassA *superclassPtr = new Concepts();
    superclassPtr->baseMethod();

    try {
        DynamicArray array1(100);
        array1[5] = 100;
        DynamicArray array2(120);
        // Makes use of + operator overloading, (-) slow
        DynamicArray result = array1 + array2;

        // Use of = operator overloading
        array1 = array2;
    } catch (int e) {
        std::cout << "Int Exception caught!" << std::endl;
    }


    myColor color;
    color.rgba = 0xFFC080AA;
    std::cout << +color.r <<  " " << +color.g << " " << +color.b << " " << +color.a << std::endl;


    // 0 means correct execution here
    return 0;
}