
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
    char **output = nullptr;
    getOutput(output);
    if (*output != nullptr)
        return std::string(*output);
    else
        return "";
}

TEST_CASE ("Grep") {
    resetInput();
    resetOutput();
    auto toApprove = std::stringstream();

    SECTION("empty input") {
        toApprove << "Scenario: empty input";
        char **lines = nullptr;
        setInput(lines, 0);
        grep("something");

        toApprove << gatherOutput();
        ApprovalTests::Approvals::verify(toApprove);
    }

//    SECTION("two lines of input") {
//        toApprove << "Scenario: two lines of input";
//        // set up the stub input to the grep function
//        strcpy(input[0], "hello");
//        strcpy(input[1], "world of software!");
//        actualInputLineCount = 2;
//
//        SECTION("find nothing") {
//            grep("something");
//
//            auto allOutput = gatherOutput(toApprove);
//            ApprovalTests::Approvals::verify(allOutput);
//        }SECTION("find on first line") {
//            grep("hello");
//
//            auto allOutput = gatherOutput(toApprove);
//            ApprovalTests::Approvals::verify(allOutput);
//        }SECTION("find on second line") {
//            grep("world");
//
//            auto allOutput = gatherOutput(toApprove);
//            ApprovalTests::Approvals::verify(allOutput);
//        }
//    }

}

