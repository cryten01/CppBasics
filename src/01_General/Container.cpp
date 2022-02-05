
#include "Container.h"

Container::Container() {

    // Initializes list
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
}

Container::~Container() {}

void Container::iterator() {

    for (std::list<int>::iterator i = list.begin(); i != list.end(); i++){
        // Prints value that i is pointing to
        std::cout << *i << std::endl;
    }
}
