#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main()
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
}
