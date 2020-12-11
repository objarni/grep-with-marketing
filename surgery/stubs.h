#pragma once

#include <string.h>


int currentInputLine;
const int INPUT_LINE_COUNT = 2;
const int INPUT_LINE_LENGTH = 80;
char input[INPUT_LINE_COUNT][INPUT_LINE_LENGTH + 1];

int currentOutputLine;
const int OUTPUT_LINE_COUNT = 10;
const int OUTPUT_LINE_LENGTH = 80;
char output[OUTPUT_LINE_COUNT][OUTPUT_LINE_LENGTH+1];
int readline(int fd, char line[]);

void fetchMarketingSlogans(char const * searchTerm, char* slogans);

int printf( const char * format, ...);
