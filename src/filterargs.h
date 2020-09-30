#pragma once

#include <string>
#include <vector>

//! Removes the argument in vector args, if removeNext is set to true two object
//! is removed from the vector used for when you want to remove for example
//! "-o main.o"
std::vector<std::string> filterArgs(std::vector<std::string> args,
                                    std::string value,
                                    bool removeNext = false);

//! Remove argument if they match a file with extension
std::vector<std::string> filterArgsExtension(std::vector<std::string> args,
                                             std::string extension);
