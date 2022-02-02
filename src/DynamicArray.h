
#ifndef CPPBASICS_DYNAMICARRAY_H
#define CPPBASICS_DYNAMICARRAY_H


class DynamicArray {

private:
    int *data;
    int size;
public:
    DynamicArray(int size);

    // Default copy constructor only copies values, prevents double deletion call, "= delete" prevents copying
    DynamicArray(const DynamicArray &other);

    // Represents a move constructor, && represents an r value = temporary available value
    DynamicArray(DynamicArray &&other);

    DynamicArray();

    virtual ~DynamicArray();

    int getSize() const;

    int get(int index) const;

    void set(int index, int value);

    // Represents operator overloading, replaces [] with the assigned function, use sparsely
    int &operator[](int index);

    DynamicArray operator+(const DynamicArray &other);

    // Copies array when assigned, similar to copy constructor expect existing data gets replaced with value of &other
    DynamicArray &operator=(const DynamicArray &other);

    // Represents a move assignment operator
    DynamicArray &operator=(DynamicArray &&other);
};


#endif //CPPBASICS_DYNAMICARRAY_H
