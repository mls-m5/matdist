
#import "localcompiler.h"
#import "mls-unit-test/unittest.h"
#import "mocks/mockenvironment.h"

auto mockEnvironment = std::make_shared<MockEnvironment>();

TEST_SUIT_BEGIN

TEST_CASE("print something") {
    auto compiler = createLocalCompiler("g++", mockEnvironment);
    std::cout << "hello\n";
}

TEST_SUIT_END
