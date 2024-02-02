
#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
using namespace std;

// enable debug == true
#define DEBUG true

#if DEBUG

    #define mmd

#else

    #define mmd cout << "test";

#endif

#endif
