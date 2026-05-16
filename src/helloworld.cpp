#include <filesystem>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "scan.hpp"
#include "list_files.hpp"
#include "ptr_examples/unique_ptr_eg.hpp"
#include "ptr_examples/shared_ptr_eg.hpp"
#include "ptr_examples/weak_ptr.hpp"
#include "ptr_examples/enable_shared_ptr_eg.hpp"
#include "ptr_examples/extern_mock.hpp"
#include "ptr_examples/custom_deleter.hpp"

namespace fs = std::filesystem;
using namespace std;
using json = nlohmann::json;
using Resource = heliconia::ptr_examples::Resource; 
using Node = heliconia::ptr_examples::Node;
using Widget = heliconia::ptr_examples::Widget;

using FilePtr = std::unique_ptr<std::FILE, decltype(heliconia::ptr_examples::fileDeleter)>;

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

    // unique_ptr example
    {
        auto res1 = heliconia::ptr_examples::createResource("Resource1");
        Resource* res2 = res1.get(); // get raw pointer to the resource
        heliconia::ptr_examples::takeOwnership(std::move(res1)); // transfer ownership to the function
        // res1 is now empty and cannot be used
        if (!res1)
        {
            std::cout << "Resource1 is no longer owned.\n";
        }
    } // res1 goes out of scope here, but the resource has already been released

    {
        auto node1 = std::make_shared<Node>("Node1");
        auto node2 = std::make_shared<Node>("Node2");
        node1->next = node2; // node1 points to node2
        node2->next = node1; // node2 points back to node1, creating a cycle

        std::vector<std::shared_ptr<Node>> nodes;
        nodes.push_back(node1);
        nodes.push_back(node2);

        node1.reset(); // release node1

        nodes.clear(); // clear the vector, which should release node2 as well, but due to the cycle, neither node1 nor node2 will be destroyed until the program ends
        node2.reset(); // release node2, but node1 is still alive due to the cycle, so neither node will be destroyed until the program ends
    }

    {
        auto widget1 = std::make_shared<Widget>();
        widget1->id = 1;

        auto widget2 = std::make_shared<Widget>();
        widget2->id = 2;

        widget1->partner = widget2; // widget1 holds a weak reference to widget2
        widget2->partner = widget1; // widget2 holds a weak reference to widget1

        widget1->pingPartner(); // should successfully ping widget2
        widget2->pingPartner(); // should successfully ping widget1

        widget2.reset(); // destroy widget2, widget1's weak_ptr should now be expired
        widget1->pingPartner(); // should indicate that widget1 has no partner
    } // both widgets go out of scope here and are destroyed, demonstrating that the weak_ptr does not create a strong reference cycle

    {
        auto controller = heliconia::ptr_examples::Controller::create();
        controller->registerSelf();
    } // controller goes out of scope here and is destroyed, demonstrating that enable_shared_from_this works correctly

    {
        // C++23: std:out_ptr adapts unique_ptr
        std::unique_ptr<int, decltype(&heliconia::ptr_examples::c_api_destroy)> handle(nullptr, heliconia::ptr_examples::c_api_destroy);

        heliconia::ptr_examples::c_api_create(std::out_ptr(handle));
        std::cout << "Value: " << *handle << "\n";
        // handle freed automatically via custom deleter

        // std::inout_ptr for re-initialization scenarios
        std::unique_ptr<int, decltype(&free)> ptr2(nullptr, &free);
        // If ptr2 already held a value, inout_ptr would reset it first
        heliconia::ptr_examples::c_api_create(std::inout_ptr(ptr2));
        std::cout << "Value 2: " << *ptr2 << "\n";
    }

    {
        // Using custom deleter with unique_ptr for file management
        FilePtr file(std::fopen("example.txt", "w"), heliconia::ptr_examples::fileDeleter);
        if (file) {
            std::fprintf(file.get(), "Hello, World!\n");
        }
    }
}
