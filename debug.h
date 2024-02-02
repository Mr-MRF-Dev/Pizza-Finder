
#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#include "color.h"
using namespace std;

// enable debug == true
#define DEBUG true

#if DEBUG

    #define log(X, Y)                                                     \
        cout << Color_Gray << "LOG >>> " << X << ": " << Y << Color_Reset \
             << endl;

    #define log(X, Y, Z)                                             \
        cout << Color_Gray << "LOG >>> " << X << ": " << Y ", " << Z \
             << Color_Reset << endl;

    #define Err(X, Y)                                                    \
        cout << Color_Red << "Err >>> " << Color_Reset << X << ": " << Y \
             << endl;

    #define Err(X, Y, Z)                                                      \
        cout << Color_Red << "Err >>> " << Color_Reset << X << ": " << Y ", " \
             << Z << endl;

#else

    #define log(X, Y)
    #define log(X, Y, Z)
    #define Err(X, Y)
    #define Err(X, Y, Z)

#endif

#endif
