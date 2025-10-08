// scan_directory.hpp
#pragma once

#include <filesystem>
#include <vector>

// Returns a vector containing the absolute path of every regular file
// found under `root` (recursive).  Non-existent or inaccessible paths
// are silently ignored; the function never throws.
std::vector<std::filesystem::path> scan_directory(const std::filesystem::path &root);