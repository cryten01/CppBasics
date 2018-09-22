#include "Class.h"

// Default:             "= 1", only defined in declaration, all params after default value must also have a default value
// Call by value:       value gets copied in new variable
// Call by reference:   uses actual variable

void Class::variableTypes(int &param1, int param2 = 1) {

    // Short
    // Int
    // Long
    // Long Long
    // Float
    // Double
    // Long Double
    // Bool (all other types can also be bool 0 = false, 1...n = true)

    // Const makes variable immutable
    double const PI = 3.14;

    // Unsigned restricts to positive range but twice as much positive values
    unsigned people = 10000;

    // sizeOf shows number of bytes of given variable
    int size = sizeof(bool);

    // Reference variable to size also known as alias
    int &sizeRef = size;

    // Casting used in C
    int cStyleCasting = (int) PI;

    // Casting used in C++
    int cppStyleCasting = static_cast<int>(PI);

    // Static variables exist during entire program lifetime, multiple variableTypes calls -> only 1 variable
    static int statVar = 10;

    // Array, out of bound can cause overrides in RAM
    int numbers[100];
    for (int i = 0; i < 100; i++) {
        numbers[i] = i + 1;
    }

    // Random time
    srand(time(0));
}

void Class::stringOperations() {

    // C String (Stores ASCII codes in array)
    char string[] = "Hello";

    // C++ String initialization
    std::string name1 = "Hello";
    std::string name2("Hello");
    std::string name3(30, 'H');

    // String operations
    int cppLength = name1.length();
    name1[2] = 'Z';                  // not recommended because of RAM override
    name1.at(2) = 'Z';
    name2 = std::to_string(10); // primitives need to be converted to string manually first
    name2.insert(5, name1);
};

