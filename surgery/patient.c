#ifdef SURGERY
// Put includes the patient needs here
#include <string.h>
#include <unistd.h>

// Put functions you do not want to test, but the patient depends on, in stubs.h
#include "stubs.h"
#endif

// ONCE YOU HAVE THE PATIENT HERE YOU SHOULD NOT EDIT ANYTHING IN THIS FILE UNTIL IT IS UNDER TEST!

void grep(char const* substring) {
    char buf[80];
    while(readline(STDIN_FILENO, buf))
    {
        char *ptr = strstr(buf, substring);
        if(NULL != ptr)
            printf("%s\n", ptr);
    }
    char slogans[500];
    fetchMarketingSlogans(substring, slogans);
    printf("This basic grep was brought to you by:\n%s\n", slogans);

}