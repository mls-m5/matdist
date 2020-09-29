#pragma once

#include "icompiler.h"
#include <memory>
#include <string>

std::unique_ptr<ICompiler> createRemoteCompiler(std::string compiler);
