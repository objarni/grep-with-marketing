#define APPROVALS_CATCH

#include "ApprovalTests.hpp"

#include "stubs.h"

extern "C"
{
#include "patient.c"
}


TEST_CASE ("SuiteName", "test case name") {
    std::vector<std::string> input = {"hello", "world"};
    grep("something");
}
