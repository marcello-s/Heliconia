#include <iostream>
#include <memory>
#include <fstream>

namespace heliconia::ptr_examples {

// custom deleter as lambda
auto fileDeleter = [](std::FILE* f) {
    if (f) {
        std::cout << "Closing file\n";
        std::fclose(f);
        std::cout << "File closed\n";
    }
};

} // namespace heliconia::ptr_examples