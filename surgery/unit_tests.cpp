#include <iostream>

#extern "C" {
    #include "patient.c"
}

int main()
{
    std::cout << "hello world\n";
    grep("something");
    return 0;
}
