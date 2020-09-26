#pragma once

#import <string>
#import <vector>

class ICompiler {
public:
    virtual std::string compile(std::vector<std::string> argument) = 0;
    virtual ~ICompiler() = default;
};
