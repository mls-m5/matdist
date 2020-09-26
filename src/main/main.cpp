
#import "localcompiler.h"
#import "localenvironment.h"
#import <iostream>
#import <string>
#import <vector>

int main(int argc, char *argv[]) {
    auto args = std::vector<std::string>(argv + 1, argv + argc);

    auto compiler =
        createLocalCompiler("/usr/bin/g++", createLocalEnvironment());

    compiler->compile(args);

    return 0;
}
