
#ifndef COLOR_H
#define COLOR_H

// enable color == true
#define COLOR true

#if COLOR

    #define Color_Reset "\033[0m"
    #define Color_Red "\033[0;31m"
    #define Color_Red_Dark "\033[38;2;160;0;0m"
    #define Color_Green "\033[0;32m"
    #define Color_Yellow_Dark "\033[0;33m"
    #define Color_Yellow "\033[38;2;200;200;0m"
    #define Color_Blue "\033[0;34m"
    #define Color_Purple "\033[0;35m"
    #define Color_Aqua "\033[38;2;0;255;255m"
    #define Color_Orange "\033[38;2;255;80;0m"
    #define Color_Gray "\033[38;2;128;128;128m"
    #define Color_Deep_Pink "\033[38;2;250;40;155m"
    #define Color_Green_Blue "\033[38;2;0;200;80m"

#else

    #define Color_Reset
    #define Color_Red
    #define Color_Red_Dark
    #define Color_Green
    #define Color_Yellow
    #define Color_Yellow_Dark
    #define Color_Blue
    #define Color_Purple
    #define Color_Aqua
    #define Color_Orange
    #define Color_Gray
    #define Color_Deep_Pink
    #define Color_Green_Blue

#endif

#endif
