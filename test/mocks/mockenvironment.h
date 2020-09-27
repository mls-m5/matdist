#pragma once

#import "ienvironment.h"
#import <mls-unit-test/mock.h>

class MockEnvironment : public IEnvironment {
public:
    MOCK_METHOD2(int,
                 run,
                 (std::string program, std::vector<std::string> arguments))
};
