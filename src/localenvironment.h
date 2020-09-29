#pragma once

#include "ienvironment.h"
#include <memory>

std::unique_ptr<IEnvironment> createLocalEnvironment();
