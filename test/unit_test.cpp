
#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
// put your includes here
}

TEST_CASE ("Sample") {
    SECTION("sample section") {
        REQUIRE(true == false);
    }
}
