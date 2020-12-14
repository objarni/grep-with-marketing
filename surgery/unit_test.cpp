
#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
#include "stubs.h"
#include "patient.h"
#include "patient.c"
}

TEST_CASE ("Sample") {
    SECTION("sample section") {
        REQUIRE(true == false);
    }
}
