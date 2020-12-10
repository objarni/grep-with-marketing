#ifdef SURGERY
#include "grep.h"
#endif


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
