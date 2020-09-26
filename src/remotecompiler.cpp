
#import "remotecompiler.h"
#import <iostream>

namespace {

struct RemoteCompiler : public ICompiler {
    RemoteCompiler(std::string compilerName) : compilerName(compilerName) {
    }

    std::string compile(std::vector<std::string> args) override {
        (void)args;

        // Pipe to other computer

        return 0;
    }

    std::string compilerName;
};

} // namespace

std::unique_ptr<ICompiler> createRemoteCompiler(std::string compiler) {
    return std::make_unique<RemoteCompiler>(compiler);
}
