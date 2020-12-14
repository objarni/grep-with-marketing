#ifdef SURGERY
// Put includes the patient needs here
#include <string.h>
#include <unistd.h>

// Put functions you do not want to test, but the patient depends on, in stubs.h
#include "stubs.h"

#endif

#include "patient.h"

// ONCE YOU HAVE THE PATIENT HERE YOU SHOULD NOT EDIT ANYTHING IN THIS FILE UNTIL IT IS UNDER TEST!

cloudService_T fetchMarketingSlogans_Ptr;
readline_T readline_Ptr;
printf_T printf_Ptr;

void setMarketingSlogansService(cloudService_T ptr) {
    fetchMarketingSlogans_Ptr = ptr;
}

void setReadline(readline_T ptr)
{
    readline_Ptr = ptr;
}

void setPrintf(printf_T ptr)
{
    printf_Ptr = ptr;
}

void grep(char const* substring) {
    char buf[80];
    while(readline_Ptr(STDIN_FILENO, buf))
    {
        char *ptr = strstr(buf, substring);
        if(NULL != ptr)
            printf_Ptr("%s\n", ptr);
    }
    char slogans[500];
    fetchMarketingSlogans_Ptr(substring, slogans);
    printf("This basic grep was brought to you by:\n%s\n", slogans);

}
