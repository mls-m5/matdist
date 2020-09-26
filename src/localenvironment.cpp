
#import "localenvironment.h"
#import <iostream>
#import <sstream>

namespace {

std::string concatArguments(std::vector<std::string> args) {
    std::ostringstream ss;

    for (auto &arg : args) {
        ss << " \"" << arg << "\"";
    }

    return ss.str();
}

struct StandardEnvironment : public IEnvironment {
    int run(std::string program, std::vector<std::string> args) override {
        //        return system((program + concatArguments(args)).c_str());
        std::cout << "should have run: " + program + concatArguments(args)
                  << "\n";

        return 0;
    }
};

} // namespace

std::unique_ptr<IEnvironment> createLocalEnvironment() {
    return std::make_unique<StandardEnvironment>();
}
