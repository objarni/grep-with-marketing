#pragma once

void grep(char const* substring);

typedef void (*cloudService_T)(char const * searchTerm, char* slogans);
void setMarketingSlogansService(cloudService_T ptr);

typedef int (*readline_T)(int fd, char line[]);
void setReadline(readline_T ptr);
