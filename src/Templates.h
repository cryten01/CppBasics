
#ifndef CPPBASICS_TEMPLATES_H
#define CPPBASICS_TEMPLATES_H

// Represents a template that replaces T with the used data type
// Modern C++ does not require template<typename T> for every function. Just <T>
template<typename T>

class Templates {

private:
    T data;

public:
    Templates(T data);

    T getData() const;

    virtual ~Templates();
};


// ATTENTION! Implementation must be defined in one file. Otherwise symbol interpretation error!
template<typename T>
Templates<T>::Templates(T data):data(data) {}

template<typename T>
Templates<T>::~Templates() {}

template<typename T>
T Templates<T>::getData() const {
    return data;
}


// Template: represents a function template where the compiler inserts the data type dependent on input
template<typename T>
void functionTemplates(T attrib) {
    std::cout << "Function template with " << attrib << " called" << std::endl;
}

// Template specialization: replaces T with int and changes function body
template<>
void functionTemplates(int attrib) {
    std::cout << "Function template with integer called" << std::endl;
}

#endif //CPPBASICS_TEMPLATES_H
