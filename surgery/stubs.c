
#include <stdarg.h>
#include <stdio.h>

#include "stubs.h"

int readline(int fd, char line[])
{
    if (currentInputLine == actualInputLineCount) {
        return 0;
    }
    strcpy(line, input[currentInputLine]);
    currentInputLine++;
    return 1;
}

int printf( const char *restrict fmt, ... )
{
    va_list ap;
    int r;
    va_start(ap, fmt);
    r = vsprintf(output[currentOutputLine], fmt, ap);
    va_end(ap);
    currentOutputLine++;
    return r;
}

void fetchMarketingSlogans(char const *searchTerm, char *slogans)
{
    strcpy(slogans, "-- ProAgile --");
}

