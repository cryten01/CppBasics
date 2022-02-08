
#ifndef CPPBASICS_TEMPLATES_H
#define CPPBASICS_TEMPLATES_H

#include <iostream>

// Represents a template that replaces T with the used data type
// Modern C++ does not require template<typename T> for every function. Just <T>
template<typename T>

class TemplateClass {

private:
    T data;

public:
    TemplateClass(T data);

    T getData() const;

    virtual ~TemplateClass();
};


// ATTENTION! Implementation must be defined in one file. Otherwise, symbol interpretation error!
template<typename T>
TemplateClass<T>::TemplateClass(T data):data(data) {}

template<typename T>
TemplateClass<T>::~TemplateClass() {}

template<typename T>
T TemplateClass<T>::getData() const {
    return data;
}

// Represents a function template where the compiler inserts the data type dependent on input
template<typename T>
void functionTemplate(T attrib) {
    std::cout << "Function template with " << attrib << " called" << std::endl;
}

// Template specialization: replaces T with int and changes function body
template<>
void functionTemplate(int attrib) {
    std::cout << "Function template with integer called" << std::endl;
}


void TestTemplates() {
    TemplateClass<int> a1(10);
//    TemplateClass<char *> a2("String");

    std::cout << "** " << a1.getData() << std::endl;
//    std::cout << "** " << a2.getData() << std::endl;

    // <> symbol not required as compiler can deduct type from attrib
    functionTemplate("Hello");
    functionTemplate(10);
}

#endif //CPPBASICS_TEMPLATES_H
