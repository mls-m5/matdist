#pragma once

#import "ienvironment.h"
#import <functional>
#import <iostream>
#import <mls-unit-test/unittestvars.h>
#import <type_traits>

#define MOCK_METHOD(ret, name, args)                                           \
    MockedFunction<ret(args)> mocked_##name =                                  \
        MockedFunction<ret(args)>(#name);                                      \
    ret name##Mock(args) { /* how to solve? */                                 \
    }

template <typename T>
class MockedFunction {};

// template <typename Signature>
template <typename ReturnT, typename... ArgsT>
class MockedFunction<ReturnT(ArgsT...)> {
public:
    MockedFunction(std::string name) : name(name) {
    }

    ReturnT operator()(ArgsT... args) {
        ++numCalls;
        if (onCall) {
            return onCall(args...);
        }
        else {
            return {};
        }
    }

    ~MockedFunction() {
        if (numCalls != expectedNumCalls) {
            std::cerr << "function " << name << " expected to be called "
                      << expectedNumCalls << " but was called " << numCalls
                      << " times \n";
            unittest::failTest();
        }
    }

    void expectCall(size_t num) {
        expectedNumCalls = num;
    }

private:
    int returnValue = {};
    std::function<ReturnT(ArgsT...)> onCall;
    size_t numCalls = 0;
    size_t expectedNumCalls = 0;
    std::string name;
};

class MockEnvironment : public IEnvironment {
public:
    using runType = int(std::string program,
                        std::vector<std::string> arguments);

    MockedFunction<runType> runMock = MockedFunction<runType>("run");

    int run(std::string program, std::vector<std::string> arguments) override {
        return runMock(program, arguments);
    }

    //    MOCK_METHOD(int, run, (std::string, std::vector.std::string >));
};
