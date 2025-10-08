#include <filesystem>
#include <generator>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

// -----------------------------------------------------------
// lazy recursive generator (C++23)
// -----------------------------------------------------------
std::generator<fs::path> enumerate_files(const fs::path &root)
{
    std::error_code ec;
    for (auto it = fs::recursive_directory_iterator(root, ec);
         it != fs::recursive_directory_iterator{};
         ++it)
    {
        if (ec) // permission / reparse-point error
        {
            it.disable_recursion_pending(); // skip subtree
            ec.clear();
            continue;
        }
        if (it->is_regular_file())
            co_yield it->path(); // hand path to caller
    }
}

// -----------------------------------------------------------
// eager helper: return everything in a vector
// -----------------------------------------------------------
std::vector<fs::path> list_directory(const fs::path &root)
{
    std::vector<fs::path> result;
    result.reserve(4'096); // small speed-up
    for (fs::path p : enumerate_files(root))
        result.push_back(std::move(p));
    return result;
}
