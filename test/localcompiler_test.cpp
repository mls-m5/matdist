
#import "localcompiler.h"
#import "mls-unit-test/unittest.h"
#import "mocks/mockenvironment.h"

TEST_SUIT_BEGIN

TEST_CASE("print something") {
    auto mockEnvironment = std::make_shared<MockEnvironment>();
    auto compiler = createLocalCompiler("g++", mockEnvironment);

    mockEnvironment->runMock.expectCall(1);

    compiler->compile("-c main.cpp", "-o main.o");

    std::cout << "hello\n";
}

TEST_SUIT_END
