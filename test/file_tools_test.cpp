
#include "mls-unit-test/unittest.h"

#include "filetools.h"
#include <fstream>

TEST_SUIT_BEGIN

TEST_CASE("random filename") {
    auto filenameA = generateRandomPathName();
    auto filenameB = generateRandomPathName();

    ASSERT_NE(filenameA, filenameB);
}

TEST_CASE("create tmp path") {
    auto path = TmpPath("/tmp/");

    ASSERT(std::filesystem::exists(path), "path not created");
    ASSERT(std::filesystem::is_directory(path), "path is not directory");
}

TEST_CASE("path is removed after destructor") {
    std::filesystem::path rawPath;

    {
        auto path = TmpPath("/tmp");
        rawPath = path;
    }

    ASSERT_EQ(false, std::filesystem::exists(rawPath));
}

TEST_CASE("remove tmp path with files in it") {
    std::filesystem::path rawPath;

    {
        auto path = TmpPath("/tmp/");
        rawPath = path;

        {
            std::ofstream file(path.path / "text.txt");
            file << "hej\n";
        }
    }

    ASSERT_EQ(false, std::filesystem::exists(rawPath));
}

TEST_CASE("moved from path object should be empty") {
    auto path1 = TmpPath("/tmp");

    auto path2 = std::move(path1);

    ASSERT_EQ(true, path1.path.empty());
}

TEST_SUIT_END
