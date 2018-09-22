// A Preprocessor executes macros during compile time (=code replacement)
// (+) no performance decrease during runtime

#ifndef C_BASICS_PREPROCESSOR_H  // Include Guard prevents loading this header file (every line of code between ifndef und endif) multiple times
#define C_BASICS_PREPROCESSOR_H  // Gets defined only if not existent yet

class Preprocessor {

public:
    static void demonstration();
};

#endif                          // C_BASICS_PREPROCESSOR_H
