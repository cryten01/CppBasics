
#ifndef CPPBASICS_SEARCH_H
#define CPPBASICS_SEARCH_H

#include "../03_DataStructures/ds01_OrderedArray.h"
#include <vector>

class Search {
public:
    static int LinearSearch(int val);
    static int BinarySearch(OrderedArray<int>& array, int value);
    static int TwoPointerSearch(std::vector<int>& array, int target);
};


#endif //CPPBASICS_SEARCH_H
