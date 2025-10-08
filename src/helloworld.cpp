#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "scan.hpp"
#include "list_files.hpp"

namespace fs = std::filesystem;
using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[])
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    // read file
    auto json = json::parse("{\"entry1\": \"string\"}");

    // mutate the json
    json["entry1"] = "kilroy was here!";

    // write to a stream, or the same file
    std::cout << json; // print the json

    // file scan
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << "  <directory>\n";
        return 1;
    }

    const fs::path root = argv[1];
    if (!fs::exists(root) || !fs::is_directory(root))
    {
        std::cerr << "error: '" << root << "' is not a directory\n";
        return 1;
    }

    std::vector<fs::path> files = scan_directory(root);
    for (const auto &p : files)
    {
        std::cout << p << '\n';
    }

    std::cout << "\nTotal files: " << files.size() << '\n';

    std::cout << "\n\n"
              << endl;

    auto list = list_directory(root);
    for (auto &p : list)
    {
        std::cout << p << '\n';
    }
}
