#pragma once

#include <filesystem>

std::filesystem::path generateRandomPathName();

struct TmpPath {
    TmpPath(std::filesystem::path root);
    ~TmpPath();
    TmpPath(const TmpPath &) = delete;
    TmpPath(TmpPath &&) = default;
    TmpPath &operator=(const TmpPath &) = delete;
    TmpPath &operator=(TmpPath &&other) = default;

    std::filesystem::path path;

    operator const std::filesystem::path &() const {
        return path;
    }
};
