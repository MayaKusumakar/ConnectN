#ifndef INPUTVALIDATION_H
    #define INPUTVALIDATION_H
    #include <stdbool.h>
    bool isValidFormat(const int numArgsRead, const int numArgsNeed);
    bool isBetween(int value, int lower, int upper);
#endif