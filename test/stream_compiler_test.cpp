
#include "localenvironment.h"
#include "mls-unit-test/unittest.h"
#include "mocks/mockenvironment.h"
#include "streamcompiler.h"

const std::string testCode = R"_(
        int main(int argc, char **argv) {
            return 0;
        }
)_";

TEST_SUIT_BEGIN

TEST_CASE("create") {
    MockEnvironment environment;
    auto compiler = createStreamCompiler(&environment, "clang++");
}

TEST_CASE("compile") {
    MockEnvironment environment;
    auto compiler = createStreamCompiler(&environment, "clang++");

    environment.mock_run.expectNum(1);

    compiler->compile("hello");
}

TEST_CASE("compile a simple program") {
    auto environment = createLocalEnvironment();
    auto compiler = createStreamCompiler(environment.get(), "clang++");

    *compiler << testCode;

    compiler->compile({"-o", "main.o", "-c", "main.cpp"});

    std::string result;
    *compiler >> result;

    ASSERT_EQ(false, result.empty());
}

TEST_SUIT_END
