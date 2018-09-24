#include "Class.h"


int *writeIntoHeap() {
    int *ptr = new int;
    return ptr;
}

void Class::dataTypeOperations(int &param1, int param2 = 1) {

    // Long Long
    // Long Double
    // Bool (all other types can also be bool 0 = false, 1...n = true)

    // Default:             "= 1", only defined in declaration, all params after default value must also have a default value
    // Call by value:       value gets copied in new variable
    // Call by reference:   uses actual variable

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

    // Static variables exist during entire program lifetime, multiple dataTypeOperations calls -> only 1 variable
    static int statVar = 10;

    // Array, out of bound can cause overrides in RAM
    int numbers[100];
    for (int i = 0; i < 100; i++) {
        numbers[i] = i + 1;
    }

    // Random time
    srand(time(0));

    // Start time
    // using auto to avoid std::chrono::high_resolution_clock::timepoint
    // compiler automatically interprets auto, avoid using it when primitives, use only when unique identifiable
    auto start = std::chrono::high_resolution_clock::now();
    // End time
    auto end = std::chrono::high_resolution_clock::now();
    // Diff
    auto diff = end - start;
    // Duration in ms
    int ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();

    // Typedef creates a new data type, (+) makes code more readable, (+) shorter names
    // Only advisable with own functions because type can be interpreted as char in this case (e.g. std::cout)
    typedef unsigned char byte;
    byte b = 5;

    // C++: Vector, Java: Arraylist
    // Attention: object is already created here as new means something different in C++
    std::vector<int> myVec(10);
    // Extends vector and inserts 10 behind last index of vector
    myVec.push_back(10);

    // Enum
    Color color = RED;
}
//
void Class::stringOperations() {

    // C String (Stores ASCII codes in array)
    char string[] = "Hello";

    // C++ String initialization
    std::string name1 = "Hello";
    std::string name2("Hello");
    std::string name3(30, 'H');

    // String operations
    int cppLength = name1.length();
    name1[1] = 'Z';                  // not recommended because of RAM override
    name1.at(1) = 'Z';
    name2 = std::to_string(10); // primitives need to be converted to string manually first
    name2.insert(1, name1);
}

void Class::pointerOperations() {

    float myfloat = 100;
    int myInt = 100;

    // Pointer (& on left side = reference, & on right side = storage location)
    int *pointer = &myInt;
    // Changes value of myInt to 15.
    // * is always needed to pointed value, otherwise pointer itself gets overwritten!
    *pointer = 15;



    // Represents a pointer to a data block in ram
    int numbers[100];
    // Equivalent to int numbers[100]
    int *beginArray = numbers;

    for (int i = 0; i < 100; i++) {
        // Dereference if access to pointed value is desired, moves 4 bytes per iteration because of i
        *(beginArray + i) = i;
    }

    // Pointer is now pointing to nothing
    beginArray = nullptr;

    // Do not cast a pointer as it changes the memory address and not the pointed value!

    // Can point to any object
    void *voidPointer = nullptr;
    float *floatPointer = &myfloat;
    voidPointer = floatPointer;

    // Void pointer always need to be casted before pointed value can be manipulated
    // Casting between pointer ok
    // Only use in rare cases
    float *floatPointer2 = static_cast<float *>(voidPointer);
    *floatPointer2 = 10.0;


    // Pointer to pointer
    int a = 10;
    int *aPointer = &a;
    int **pointerToPointer = &aPointer;
    // pointerToPointer points to aPointer. aPointer points to a. a gets changed
    **pointerToPointer = 30;

    // Read only pointer: Referenced object value cannot be modified but reference itself can be modified.
    const int *myIntPtr1 = &myInt;
    // Pointer cannot change it's reference but can change its pointed value.
    int *const myIntPtr2 = &myInt;
    // Pointer reference cannot be changed and also pointed value cannot be changed. Not used in practice.
    const int *const myIntPtr3 = &myInt;


    // Function pointer
    // void is the return value of the function
    // everything within braces are arguments of the pointed function
    int &myIntRef = myInt;
    void (*myFuncPtr)(int &, int);
    // Points to actual function
    myFuncPtr = dataTypeOperations;
    // Executes function
    myFuncPtr(myIntRef, 10);

    // Never ever return a pointer to a local/stack variable (= variable with local scope/lifetime)
}

void Class::memoryOperations() {

    // Pointer that points to dynamic variable (=during runtime and not during compile time as normally)
    // new in C++: dynamic memory gets created, new in Java: Object gets created
    // When using new also type in delete!
    // Garbage collection can reduce performance significantly
    int *myIntPtr = new int[100];

    // Dynamic memory lives across scope, needs to be deleted manually (=no garbage collection)
    // Needs [] because myIntPtr points to array, otherwise only first element gets destroyed
    delete[] myIntPtr;

    // Nullptr nullifies delete operation
    myIntPtr = nullptr;
    delete[] myIntPtr;

    // Possible to return a ptr because variable is on Heap (= doesn't get deleted when out of scope)
    // Attention also needs to be manually deleted!
    // C: malloc and free, C++: new and delete, don't mix both!
    delete writeIntoHeap();

    // Storage segments that cannot change size during runtime:
    // Code segment in machine language (OS prevents direct manipulation during runtime)
    // Data segment contains static and global variables
    // BSS segment contains non initialized static and global variables (for storage efficiency)

    // Storage segments that can change size during runtime:
    // Stack segment gets increased/decreased when new function is called/closed (stack frame), stores local variables
    // Heap segment gets increased/decreased when new/delete, needs manual memory management
}

void Class::ioOperations() {

    // Creates an output file stream
    std::ofstream outFile;
    // Open flags
    // app appends to last position per call
    // ate put writing position to end when file gets opened
    // trunc resets bytesize to zero and starts again
    // can be combined with "|" = bitwise or
    outFile.open("/Users/gerhard/CLionProjects/CppBasics/Textfile.txt", std::ios::trunc | std::ios::binary);

    // Checks if file stream is open
    if (outFile.is_open()) {
        outFile << "Write operation";
        outFile.close();
    } else {
        std::cerr << "Error during opening of file!";
    }


    // Creates an input file stream
    std::ifstream inFile;
    std::string line;
    inFile.open("/Users/gerhard/CLionProjects/CppBasics/Textfile.txt");

    // Checks if file stream is open
    if (inFile.is_open()) {
        // every line should be stored in File
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Error during opening of file!";
    }

    // Read in binary data
    char *buffer;
    // Closed file streams can be reused
    // ate guarantees that reading position is at end of line
    inFile.open("/Users/gerhard/CLionProjects/CppBasics/Textfile.zip", std::ios::binary | std::ios::ate);

    if (inFile.is_open()) {
        // tellg() returns reading position
        int size = inFile.tellg();
        // dynamically allocates memory
        buffer = new char[size];
        // beg sets reading position to beginning
        inFile.seekg(0, std::ios::beg);
        // reads everything in the buffer
        inFile.read(buffer, size);

        inFile.close();
        delete[] buffer;
        buffer = nullptr;
    } else {
        std::cerr << "Error during opening of file!";
    }

    // redirect cerr in log file
    std::ofstream logFile("/Users/gerhard/CLionProjects/CppBasics/Logfile.txt", std::ios::app);
    std::cerr.rdbuf(logFile.rdbuf());
    std::cerr << "Error!" << std::endl;
    logFile.close();
};

