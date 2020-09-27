#pragma once

#import <string>
#import <vector>

class ICompiler {
public:
    virtual std::string compile(std::vector<std::string> argument) = 0;

    template <typename... Args>
    std::string compile(Args &&... args) {
        return compile(std::vector<std::string>{args...});
    }

    virtual ~ICompiler() = default;
};
