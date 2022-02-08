
#ifndef CPPBASICS_C02_STACKVSHEAP_H
#define CPPBASICS_C02_STACKVSHEAP_H

struct Vector3 {
    float x, y, z;

};

class StackVsHeap {
public:
    void AllocateOnStack();
    void AllocateOnHeap();
};


#endif //CPPBASICS_C02_STACKVSHEAP_H
