
#include <stdarg.h>

#include "stubs.h"

int readline(int fd, char line[])
{
    strcpy(line, input[currentInputLine]);
    currentInputLine++;
    if (currentInputLine == INPUT_LINE_COUNT)
        return 0; // end of input
    else
        return 1;
}

int printf( const char *restrict fmt, ... )
{
    strcpy(output[currentOutputLine], fmt);
    currentOutputLine++;
    return 0;
}

void fetchMarketingSlogans(char const *searchTerm, char *slogans)
{
}

