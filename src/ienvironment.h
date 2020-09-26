#pragma once

#import <string>
#import <vector>

//! Where to do everything, this is separated mostly for testing
class IEnvironment {
public:
    virtual int run(std::string program,
                    std::vector<std::string> arguments) = 0;

    virtual ~IEnvironment() = default;
};
