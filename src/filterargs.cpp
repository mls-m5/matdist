
#include "filterargs.h"
#include <algorithm>
#include <filesystem>

std::vector<std::string> filterArgs(std::vector<std::string> args,
                                    std::string value,
                                    bool removeNext) {
    for (auto it = args.begin(); it != args.end();) {
        if (*it == value) {
            it = args.erase(it);

            if (it != args.end() && removeNext) {
                it = args.erase(it);
            }
        }
        else {
            ++it;
        }
    }

    return args;
}

std::vector<std::string> filterArgsExtension(std::vector<std::string> args,
                                             std::string extension) {
    auto it = std::remove_if(args.begin(), args.end(), [&](auto &&value) {
        return std::filesystem::path(value).extension() == extension;
    });

    args.erase(it, args.end());

    return args;
}
