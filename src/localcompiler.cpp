
#import "localcompiler.h"
#import "ienvironment.h"

namespace {

struct LocalCompiler : ICompiler {
    LocalCompiler(std::string compilerName,
                  std::shared_ptr<IEnvironment> environment)
        : compilerName(compilerName), environment(std::move(environment)) {
    }

    std::string compile(std::vector<std::string> arguments) override {
        environment->run(compilerName, arguments);
        return 0;
    }

    std::string compilerName;
    std::shared_ptr<IEnvironment> environment;
};

} // namespace

std::unique_ptr<ICompiler> createLocalCompiler(
    std::string compiler, std::shared_ptr<IEnvironment> environment) {
    return std::make_unique<LocalCompiler>(compiler, std::move(environment));
}
