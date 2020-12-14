#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "src/cloudservice.h"

#define CLOUD_SERVICE_ENABLED 1

static int readline(int fd, char line[]) {
    int result = read(0, line, 80);
    return result != 0;
}

void grep(char const* substring) {
    char buf[80];
    while(readline(STDIN_FILENO, buf))
    {
        char *ptr = strstr(buf, substring);
        if(NULL != ptr)
            printf("%s\n", ptr);
    }
    if(CLOUD_SERVICE_ENABLED) {
        char slogans[500];
        fetchMarketingSlogans(substring, slogans);
        printf("This basic grep was brought to you by:\n%s\n", slogans);
    }
}

int main(int argc, char* argv[]) {
  if(argc != 2)
  {
      printf("Example:\n");
      printf("   cat somefile | basicgrep somestring\n");
      printf("This will print any line of 'somefile' containing 'somestring'\n");
      return 0;
  }
  grep(argv[1]);
  return 0;
}
