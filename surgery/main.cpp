#include <iostream>
#define CLOUD_SERVICE_ENABLED 1
#include "grep.c"

int main()
{
    std::cout << "hello world\n";
    grep("something");
    return 0;
}
