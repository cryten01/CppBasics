
#ifndef CPPBASICS_CONST_H
#define CPPBASICS_CONST_H

#include <iostream>

class Entity {
private:
    int m_X, m_Y;
public:
    // const after only works in class, prevents modifying the class
    int GetX() const {
        // not possible
//        m_X = 10;
        return m_X;
    }

    void SetX(int x) {
        m_X = x;
    }
};

void Print(const Entity& e) {
    // would not be possible if get function is not const because GetX could otherwise modify content of e
    std::cout << e.GetX() << std::endl;
}

void ShowConstExamples() {
    // Contents immutability

    // const variables are immutable and are written in CAPITAL letters
    const int MAX = 50;

    // const before means the value the pointer is referring to cannot be changed
    const int *number = new int;
    // however, I still can reference to another value
    number = &MAX;
    // this is not possible because
//    *number = 10;

    // identical to list case
    int const *number2 = new int;

    // Pointer immutability

    // on what address the pointer is pointing to is now constant but the value can still be changed
    int *const pointerConst = new int;
    *pointerConst = 10;
//    pointerConst = &MAX;

    // Contents & pointer immutability

    const int *const bothConst = new int;
//    bothConst = &MAX;
//    *bothConst = 10;
}

#endif //CPPBASICS_CONST_H

