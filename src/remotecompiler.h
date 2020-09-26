#pragma once

#import "icompiler.h"
#import <memory>
#import <string>

std::unique_ptr<ICompiler> createRemoteCompiler(std::string compiler);
