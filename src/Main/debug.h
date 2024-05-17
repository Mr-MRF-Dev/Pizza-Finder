
#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#include "color.h"
using namespace std;

// enable debug == true
#define DEBUG false

#if DEBUG

    #define log2(X, Y)                                                     \
        cout << Color_Gray << "LOG >>> " << X << ": " << Y << Color_Reset \
             << endl;

    #define log3(X, Y, Z)                                                \
        cout << Color_Gray << "LOG >>> " << X << ": " << Y << ", " << Z \
             << Color_Reset << endl;

    #define Err2(X, Y)                                                    \
        cout << Color_Red << "Err >>> " << Color_Reset << X << ": " << Y \
             << endl;

    #define Err3(X, Y, Z)                                                      \
        cout << Color_Red << "Err >>> " << Color_Reset << X << ": " << Y ", " \
             << Z << endl;

#else

    #define log2(X, Y)
    #define log3(X, Y, Z)
    #define Err2(X, Y)
    #define Err3(X, Y, Z)

#endif

#endif
