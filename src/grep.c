
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "grep.h"

cloudService_T fetchMarketingSlogans_Ptr;
readline_T readline_Ptr;

void setMarketingSlogansService(cloudService_T ptr)
{
    fetchMarketingSlogans_Ptr = ptr;
}

void setReadline(readline_T ptr)
{
    readline_Ptr = ptr;
}

void grep(char const* substring) {
    char buf[80];
    while(readline_Ptr(STDIN_FILENO, buf))
    {
        char *ptr = strstr(buf, substring);
        if(NULL != ptr)
            printf("%s\n", ptr);
    }
    char slogans[500];
    fetchMarketingSlogans_Ptr(substring, slogans);
    printf("This basic grep was brought to you by:\n%s\n", slogans);

}