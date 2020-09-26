#pragma once

#import "ienvironment.h"
#import <memory>

std::unique_ptr<IEnvironment> createLocalEnvironment();
