#define APPROVALS_CATCH

#include "ApprovalTests.hpp"

#include "stubs.h"

extern "C"
{
#include "grep.c"
}


TEST_CASE ("SuiteName", "test case name") {
    std::vector<std::string> input = {"hello", "world"};
    grep("something");
}
