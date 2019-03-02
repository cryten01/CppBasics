
#ifndef CPPBASICS_SUPERCLASS_H
#define CPPBASICS_SUPERCLASS_H


class SuperclassA {

public:
    // virtual enables "late binding" -> method is decided at runtime based on type of pointed object otherwise "early binding"
    // = 0 means pure virtual so there is no implementation, forces child to implement
    virtual void baseMethod() = 0;

    // Calls child destructor, always put virtual in front of Destructor
    virtual ~SuperclassA();
};


class SuperclassB {

};


#endif //CPPBASICS_SUPERCLASS_H
