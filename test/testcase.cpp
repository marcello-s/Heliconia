#include <catch2/catch_test_macros.hpp>

static int Get42()
{
    return 42;
}

TEST_CASE("Always get 42 (pass)", "[single-file]")
{
    REQUIRE(Get42() == 42);
}