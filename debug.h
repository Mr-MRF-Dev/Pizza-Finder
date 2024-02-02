
#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
using namespace std;

// enable debug == true
#define DEBUG true

#if DEBUG

    #define log(X, Y) cout << "DEBUG >>> " << X << ": " << Y;

#else

    #define log(X, Y)

#endif

#endif
