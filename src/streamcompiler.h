#pragma once

#include "ienvironment.h"
#include "istreamcompiler.h"
#include <memory>
#include <string>

std::unique_ptr<IStreamCompiler> createStreamCompiler(
    IEnvironment *environmente, std::string compiler);
