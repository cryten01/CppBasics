
#include <iostream>
#include "SuperclassA.h"

void SuperclassA::baseMethod() {
    std::cout << "I'm currently in SuperclassA" << std::endl;
}

SuperclassA::~SuperclassA() {
}
