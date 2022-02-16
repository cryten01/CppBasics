
#ifndef CPPBASICS_S02_VIRTUALFUNCTIONS_H
#define CPPBASICS_S02_VIRTUALFUNCTIONS_H

#include <iostream>
#include <string>

// Prioritizes method of the closest declared class type first
class Entt {
public:
    // Generates a v-table for mapping the functions
    virtual std::string GetName() { return "Entity"; };
};

/**
 * A subclass inheriting from player
 */
class Bird : public Entt {
private:
    std::string m_Name;
public:
    Bird(const std::string &name) : m_Name(name) {}

    // For better readability and avoiding spelling mistakes mark function as override
    // Optional
    std::string GetName() override { return m_Name; }
};


void ShowVirtualFunctionsExample() {
    Entt* e = new Bird("Entity");
    std::cout << e->GetName() << std::endl;

    Bird* p = new Bird("Player");
    std::cout << p->GetName() << std::endl;

    Entt* e1 = p;
    std::cout << e1->GetName() << std::endl;
}

#endif //CPPBASICS_S02_VIRTUALFUNCTIONS_H
