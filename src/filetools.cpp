
#include "filetools.h"
#include <random>

namespace {

std::mt19937 randomEngine([] { return std::random_device(); }()());

}

std::filesystem::path generateRandomPathName() {
    std::uniform_int_distribution<char> dist('a', 'z');
    std::string str;
    str.reserve(16);
    for (size_t i = 0; i < str.capacity(); ++i) {
        str.push_back(dist(randomEngine));
    }
    return str;
}

TmpPath::TmpPath(std::filesystem::path root) {
    do {
        path = root / generateRandomPathName();
    } while (std::filesystem::exists((path)));

    std::filesystem::create_directory(path);
}

TmpPath::~TmpPath() {
    if (!path.empty()) {
        std::filesystem::remove_all(path);
    }
}
