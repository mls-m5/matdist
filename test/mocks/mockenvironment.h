#pragma once

#import "ienvironment.h"
#import <functional>
#import <type_traits>

#define MOCK_METHOD(ret, name, args)                                           \
    MockedFunction<ret args> mocked_##name = MockedFunction<ret args>(this);   \
    ret name##Mock(args);

class MockEnvironment : public IEnvironment {
public:
    // This will be extracted in the future

    template <typename Signature>
    class MockedFunction {
    public:
        MockedFunction(MockEnvironment *parent) : parent(parent) {
        }

        int operator()(std::string program,
                       std::vector<std::string> arguments) {
            ++numCalls;
            return onCall(program, arguments);
        }

        int returnValue = {};
        MockEnvironment *parent;
        std::function<int(std::string, std::vector<std::string>)> onCall;
        size_t numCalls = 0;
    };

    using runType = int(std::string program,
                        std::vector<std::string> arguments);

    MockedFunction<runType> runMock = MockedFunction<runType>(this);

    template <typename Signature>

    int run(std::string program, std::vector<std::string> arguments) override {
        return runMock();
    }

    //    MOCK_METHOD(int, apa, (char));

    MockedFunction<int(char)> mocked_apa = MockedFunction<int(char)>(this);
};
