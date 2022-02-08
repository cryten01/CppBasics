
#ifndef CPPBASICS_G01_STRUCTSANDCLASSES_H
#define CPPBASICS_G01_STRUCTSANDCLASSES_H

#include <iostream>

class Player {
public:
    Player() {}

    // Constructor uses an initializer list instead of m_speed = speed
    // Use them to avoid creating unnecessary objects that get thrown away by assigning new ones in the constructor
    // Watch out for the correct order of initialization
    Player(const std::string &name)
            : m_speed(100), m_name(name) {
    }

    // virtual avoids undefined behaviour when derived
    virtual ~Player();

private:
    int m_x, m_y; // m_ means member variables
    int m_speed;
    std::string m_name;

public:
    void Move(int x, int y) {
        this->m_x = x * m_speed;
        this->m_y = y * m_speed;
    }

    void Attack();
};

#endif //CPPBASICS_G01_STRUCTSANDCLASSES_H
