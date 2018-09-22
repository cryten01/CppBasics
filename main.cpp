// Tutorial last Stand: 31

#pragma once // loads header this file only once
#include <iostream>
#include "Class.h"
#include "Preprocessor.h"


// global variable
int reference = 1;


int main() {
    Class::variableTypes(reference, 2);
    Preprocessor::demonstration();

    // 0 means correct execution here
    return 0;
}