
#include "ApprovalTests.hpp"
#include "Catch.hpp"

extern "C"
{
#include "stubs.h"
#include "grep.h"
}


TEST_CASE ("Grep") {
    resetInput();
    resetOutput();
    setMarketingSlogansService(fetchMarketingSlogans);
    setReadline(readline);

    auto toApprove = std::stringstream();

    SECTION("empty input")
    {
        toApprove << "Scenario: empty input" << std::endl;
        char **lines = nullptr;
        setInput(lines, 0);
        grep("something");

        toApprove << getOutput();
        ApprovalTests::Approvals::verify(toApprove.str());
    }

    SECTION("two lines of input")
    {
        // set up the stub input to the grep function
        char line1[] = "hello";
        char line2[] = "world of software!";
        char* input[] = {line1, line2};
        setInput(input, 2);

        SECTION("find nothing")
        {
            toApprove << "Scenario: grep for something and find nothing" << std::endl;

            grep("something");

            toApprove << getOutput();
            ApprovalTests::Approvals::verify(toApprove.str());
        }
        SECTION("find on first line")
        {
            toApprove << "Scenario: grep for hello and find it on the first line" << std::endl;
            grep("hello");

            toApprove << getOutput();
            ApprovalTests::Approvals::verify(toApprove.str());
        }
        SECTION("find on second line") {
            toApprove << "Scenario: grep for world and find it on the second line" << std::endl;
            grep("world");

            toApprove << getOutput();
            ApprovalTests::Approvals::verify(toApprove.str());
        }
    }

}

