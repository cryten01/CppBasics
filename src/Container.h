
#ifndef CPPBASICS_CONTAINER_H
#define CPPBASICS_CONTAINER_H

#include <vector>
#include <list>
#include <iostream>

class Container {

private:
    // represents a resizable array. use push back only to increase size
    std::vector<int> vector;
    // represents a linked list
    std::list<int> list;

public:

    Container();

    void iterator();

    virtual ~Container();
};


#endif //CPPBASICS_CONTAINER_H
