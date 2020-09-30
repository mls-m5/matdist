

#include "streamcompiler.h"
#include "filetools.h"
#include "filterargs.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace {

//! The remote compiler is a interface for a connection to another network or a
//! collection of other computers
struct StreamCompiler : public virtual IStreamCompiler {
    StreamCompiler(IEnvironment *environment, std::string compilerName)
        : compilerName(compilerName), environment(environment) {

        codePath = path.path / "source.cpp";
        codePipe.open(codePath);

        objectPath = path.path / "obj.o";
    }

    std::string compile(std::vector<std::string> args) override {
        (void)args;

        codePipe.close();

        args = filterArgs(move(args), "-o", true);
        args = filterArgs(move(args), "-I", true);
        args = filterArgsExtension(move(args), ".cpp");

        args.emplace_back(codePath);
        args.emplace_back("-o");
        args.emplace_back(objectPath);

        if (environment->run(compilerName, args)) {
            throw std::runtime_error("compilation failed");
        }

        objectPipe.open(objectPath);

        return {};
    }

    std::ostream &input() override {
        if (!codePipe.is_open()) {
            throw std::runtime_error("code stream not open (yet?)");
        }
        return codePipe;
    }

    std::istream &output() override {
        if (!objectPipe.is_open()) {
            throw std::runtime_error("object stream is not open");
        }
        return objectPipe;
    }

    operator bool() override {
        return static_cast<bool>(objectPipe);
    }

    std::string compilerName;

    std::filesystem::path objectPath;
    std::ifstream objectPipe;

    std::filesystem::path codePath;
    std::ofstream codePipe;

    TmpPath path = TmpPath("/tmp");

    IEnvironment *environment;
};

} // namespace

std::unique_ptr<IStreamCompiler> createStreamCompiler(IEnvironment *environment,
                                                      std::string compiler) {
    return std::make_unique<StreamCompiler>(environment, compiler);
}
