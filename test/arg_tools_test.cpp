
#include "filterargs.h"
#include "mls-unit-test/unittest.h"

TEST_SUIT_BEGIN

TEST_CASE("filter out two argument") {
    std::vector<std::string> args = {"-o", "main.o", "-c", "main.cpp"};

    args = filterArgs(move(args), "-o", true);

    ASSERT_EQ(args.size(), 2);
    ASSERT_EQ(args.back(), "main.cpp");
}

TEST_CASE("filter out single argument") {
    std::vector<std::string> args = {"-o", "main.o", "-v", "-c", "main.cpp"};

    args = filterArgs(move(args), "-v", false);

    ASSERT_EQ(args.size(), 4);
    ASSERT_NE(args.at(2), "-v");
}

TEST_CASE("filter out by extension") {
    std::vector<std::string> args = {"-o", "main.o", "-v", "-c", "main.cpp"};

    args = filterArgsExtension(move(args), ".cpp");

    ASSERT_EQ(args.size(), 4);
    ASSERT_EQ(args.back(), "-c");
}

TEST_SUIT_END
