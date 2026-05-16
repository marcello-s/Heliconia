#include <iostream>
#include <memory>
#include <vector>

namespace heliconia::ptr_examples {

struct Node {
    std::string value;
    std::shared_ptr<Node> next;

    explicit Node(const std::string v) : value(std::move(v)) {
        std::cout << "Node created: " << value << std::endl;
    }
    ~Node() {
        std::cout << "Node destroyed: " << value << std::endl;
    }
};

} // namespace heliconia::ptr_examples