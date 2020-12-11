
#include <stdarg.h>
#include <stdio.h>

#include "stubs.h"

// readline global state
// index of line we will return when readline is next called
int currentInputLine;
// the actual total number of lines we will return
int actualInputLineCount;
// max number of input lines we are capable of returning from the stub
#define MAX_INPUT_LINE_COUNT 2
// max length of a line of stub input
#define INPUT_LINE_LENGTH 80
// an array of lines of input to return from readline stub
char input[MAX_INPUT_LINE_COUNT][INPUT_LINE_LENGTH + 1];

int readline(int fd, char line[])
{
    if (currentInputLine == actualInputLineCount) {
        return 0;
    }
    strcpy(line, input[currentInputLine]);
    currentInputLine++;
    return 1;
}

// printf global state
static char buffer[10000];
static char *next = buffer;

int printf(const char *fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    const int ret = vsnprintf(next, sizeof buffer-(next-buffer), fmt, argp);
    next += ret;
    va_end(argp);
    return ret;
}

void fetchMarketingSlogans(char const *searchTerm, char *slogans)
{
    strcpy(slogans, "-- ProAgile --");
}

void resetOutput() {
    next = buffer;
}

void resetInput() {
    currentInputLine = 0;
}

char* getOutput() {
    return buffer;
}

void setInput(char** lines, int numLines) {
    for (int i = 0; i < numLines; ++i) {
        strcpy(input[i], lines[i]);
    }
    actualInputLineCount = numLines;
}
