
#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
#include "stubs.h"
#include "patient.c"
}

/*
 * convert the lines held in the output array of char* into a c++ string we can use with approvals
 */
std::string gatherOutput() {
    auto* to_approve = new std::stringstream();
    for (int i = 0; i < currentOutputLine; i++ ) {
        (*to_approve) << output[i] << "\n";
    }
    return to_approve->str();
}

TEST_CASE ("Grep") {
    currentInputLine = 0;
    currentOutputLine = 0;

    SECTION("empty input") {
        actualInputLineCount = 0;
        grep("something");

        auto allOutput = gatherOutput();
        ApprovalTests::Approvals::verify(allOutput);
    }

    SECTION("two lines of input") {
        // set up the stub input to the grep function
        strcpy(input[0], "hello");
        strcpy(input[1], "world of software!");
        actualInputLineCount = 2;

        SECTION("find nothing") {
            grep("something");

            auto allOutput = gatherOutput();
            ApprovalTests::Approvals::verify(allOutput);
        }
        SECTION("find on first line") {
            grep("hello");

            auto allOutput = gatherOutput();
            ApprovalTests::Approvals::verify(allOutput);
        }
        SECTION("find on second line") {
            grep("world");

            auto allOutput = gatherOutput();
            ApprovalTests::Approvals::verify(allOutput);
        }
    }

}

