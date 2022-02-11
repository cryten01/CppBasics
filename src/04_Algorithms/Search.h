
#ifndef CPPBASICS_SEARCH_H
#define CPPBASICS_SEARCH_H

#include "../03_DataStructures/ds01_OrderedArray.h"

class Search {
public:
    static int LinearSearch(int val);
    static int BinarySearch(OrderedArray<int>& array, int value);
};


#endif //CPPBASICS_SEARCH_H
