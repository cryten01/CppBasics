
#ifndef CPPBASICS_S03_PUREVIRTUALFUNCTIONS_H
#define CPPBASICS_S03_PUREVIRTUALFUNCTIONS_H

#include <iostream>

/**
 * Contains a pure virtual function and therefore represents an abstract class/interface.
 */
class Printable {
public:
    // Has to be implemented in subclass
    virtual std::string GetClassName() = 0;
};

class Car : public Printable {
public:
    std::string GetClassName() override { return "Car"; }
};

void Print(Printable *obj) {
    std::cout << obj->GetClassName() << std::endl;
}

void ShowPrintable() {
    Car *car = new Car();
    Print(car);
}

#endif //CPPBASICS_S03_PUREVIRTUALFUNCTIONS_H
