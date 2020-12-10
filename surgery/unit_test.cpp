#define APPROVALS_CATCH

#include "ApprovalTests.hpp"

extern "C"
{
#include "grep.c"
}


TEST_CASE ("SuiteName", "test case name") {
    grep("something");
}
