#pragma once

#include "icompiler.h"
#include "ienvironment.h"
#include <memory>
#include <string>

std::unique_ptr<ICompiler> createLocalCompiler(
    std::string compiler, std::shared_ptr<IEnvironment> environment);
