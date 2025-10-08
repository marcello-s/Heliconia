#include <filesystem>
#include <iostream>
#include <vector>
#include "scan.hpp"

namespace fs = std::filesystem;

// -----------------------------------------------------------
// recursive scan – returns a vector with every regular file
// -----------------------------------------------------------
std::vector<fs::path> scan_directory(const fs::path &root)
{
    std::vector<fs::path> files;
    files.reserve(4'096); // small speed-up

    std::error_code ec; // avoid exceptions
    fs::recursive_directory_iterator it(root, ec), end{};
    if (ec)
    {
        return files; // root does not exist
    }

    for (; it != end; ++it)
    {
        if (ec) // permission / reparse error
        {
            it.disable_recursion_pending(); // skip subtree
            ec.clear();
            continue;
        }

        if (it->is_regular_file())
        {
            files.push_back(it->path());
        }
    }

    return files;
}