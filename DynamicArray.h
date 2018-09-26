
#ifndef CPPBASICS_DYNAMICARRAY_H
#define CPPBASICS_DYNAMICARRAY_H


class DynamicArray {

private:
    int* data;
    int size;
public:
    DynamicArray(int size);

    DynamicArray();

    virtual ~DynamicArray();

    int getSize() const;
    int get(int index) const ;
    void set(int index, int value);
};


#endif //CPPBASICS_DYNAMICARRAY_H
