#define APPROVALS_CATCH

#include "ApprovalTests.hpp"

extern "C"
{
#include "stubs.h"
#include "patient.c"
}

TEST_CASE ("Grep") {

    strcpy(input[0], "hello");
    strcpy(input[1], "world!");
    currentInputLine = 0;
    currentOutputLine = 0;

    SECTION("grep doesn't find anything") {
        grep("something");
        REQUIRE(std::string(output[0]) == "This basic grep was brought to you by:\n%s\n");
        REQUIRE(std::string(output[1]) == "");
    }
    SECTION("grep finds something") {
        grep("hello");
        REQUIRE(std::string(output[0]) == "%s\n");
        REQUIRE(std::string(output[1]) == "This basic grep was brought to you by:\n%s\n");
    }
}

