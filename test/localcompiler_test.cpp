
#import "localcompiler.h"
#import "mls-unit-test/unittest.h"
#import "mocks/mockenvironment.h"
#import <memory>

TEST_SUIT_BEGIN

TEST_CASE("should pass arguments to environment") {
    auto mockEnvironment = std::make_shared<MockEnvironment>();
    auto compiler = createLocalCompiler("g++", mockEnvironment);

    mockEnvironment->mock_run.expectNum(1).expectArgs(
        "g++", {"-c", "main.cpp", "-o", "main.o"});

    compiler->compile("-c", "main.cpp", "-o", "main.o");
}

TEST_SUIT_END
