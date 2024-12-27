// #include "file.h"

#include <stdio.h>


int main() {

    #if defined(_WIN32) || defined(_WIN64)
        printf("Running on Windows\n");
    #elif defined(__linux__)
        printf("Running on Linux\n");
    #elif defined(__APPLE__) && defined(__MACH__)
        printf("Running on macOS\n");
    #elif defined(__unix__)
        printf("Running on Unix\n");
    #else
        printf("Unknown operating system\n");
    #endif

    return 0;
}