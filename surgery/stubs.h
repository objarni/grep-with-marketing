#pragma once

#include <string.h>

// index of line we will return when readline is next called
int currentInputLine;
// the actual total number of lines we will return
int actualInputLineCount;
// max number of input lines we are capable of returning from the stub
const int MAX_INPUT_LINE_COUNT = 2;
// max length of a line of stub input
const int INPUT_LINE_LENGTH = 80;
// an array of lines of input to return from readline stub
char input[MAX_INPUT_LINE_COUNT][INPUT_LINE_LENGTH + 1];
// stub prototype
int readline(int fd, char line[]);

// index of the line we most recently stored in output
int currentOutputLine;
// maximum lines of output we can store
const int OUTPUT_LINE_COUNT = 10;
// maximum length of one line of output that we can store
const int OUTPUT_LINE_LENGTH = 80;
// an array of lines that have been written to output
char output[OUTPUT_LINE_COUNT][OUTPUT_LINE_LENGTH+1];
// stub prototype
int printf( const char * format, ...);

// stub prototype
void fetchMarketingSlogans(char const * searchTerm, char* slogans);

