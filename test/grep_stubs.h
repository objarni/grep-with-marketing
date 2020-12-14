#pragma once

#include <string.h>

// stub prototypes
int readline(int fd, char line[]);
int printf( const char * format, ...);
void fetchMarketingSlogans(char const * searchTerm, char* slogans);

// communication with tests
void resetOutput();
void resetInput();
char* getOutput();
void setInput(char** lines, int numLines);