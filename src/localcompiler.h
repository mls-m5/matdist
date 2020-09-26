#pragma once

#import "icompiler.h"
#import "ienvironment.h"
#import <memory>
#import <string>

std::unique_ptr<ICompiler> createLocalCompiler(
    std::string compiler, std::shared_ptr<IEnvironment> environment);
