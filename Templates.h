
#ifndef CPPBASICS_TEMPLATES_H
#define CPPBASICS_TEMPLATES_H

// Represents a template that replaces a data type with the defined Template type
template<typename T>

class Templates {

private:
    T data;

public:
    Templates(T data);

    virtual ~Templates();

    T getData() const;
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

#endif //CPPBASICS_TEMPLATES_H
