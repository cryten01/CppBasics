
#ifndef CPPBASICS_G04_BINARY_H
#define CPPBASICS_G04_BINARY_H

void BinaryPrint(int number) {
    std::cout << "Binary: " << std::bitset<6>(number) << " | Decimal: " << number << std::endl;
}

void BinaryShiftOperations(int x) {
    // Shifts x two bits or multiplies it with 2^2
    x = x << 2;
    BinaryPrint(x);

    // Short syntax
    x >>= 2;
    BinaryPrint(x);
}

void BinaryANDOperations(int x) {
    x = 0;
    // Often used for masks or selecting specific bits
    BinaryPrint(x);
    BinaryPrint(x);
    BinaryPrint(x & x);
}

void BinaryOROperations(int x) {
    // Often used for combinations
    BinaryPrint(x);
    BinaryPrint(x - 1);
    BinaryPrint(x | x - 1);

}

void BinaryNOTOperations(int x) {
    // Toggles bits on/off
}

void BinaryXOROperations(int x) {
    BinaryPrint(x);
    BinaryPrint(x - 1);
    BinaryPrint(x ^ x - 1);
}

void ShowBinaryExamples() {
    int x = 8;

    // Directly converting binary to decimal
//    std::cout << 0b11;

//    BinaryShiftOperations(x);
//    BinaryANDOperations(x);
//    BinaryOROperations(x);
    BinaryXOROperations(x);

}

#endif //CPPBASICS_G04_BINARY_H
