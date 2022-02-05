#include "Preprocessor.h"

#define NUMBER 100          // replaces NUMBER with 100
#define square(a) a*a       // replaces square(a) with a*a operation - ATTENTION when using increment/decrement
#define conditional         // if defined ifdef block gets executed else ifndef block gets executed

//#error "Trigger error"    // an error gets triggered if codepiece is executed, (+) helps finding errors


void Preprocessor::demonstration() {
    int number;

#ifdef conditional
    number = square(NUMBER);
#endif

#ifndef conditional
    number = 10000;
#endif
}

#undef NUMBER           // eliminates macro