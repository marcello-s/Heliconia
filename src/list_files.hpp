// scan_directory.hpp
#pragma once

#include <filesystem>
#include <vector>

std::vector<std::filesystem::path> list_directory(const std::filesystem::path &root);