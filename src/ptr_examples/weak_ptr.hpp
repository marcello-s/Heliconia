#include <iostream>
#include <memory>

namespace heliconia::ptr_examples {

struct Widget {
    std::weak_ptr<Widget> partner;
    int id = 0;

    ~Widget() {
        std::cout << "Widget " << id << " destroyed\n";
    }

    void pingPartner() {
        if (auto p = partner.lock()) {
            std::cout << "Widget " << id << " pinging partner " << p->id << "\n";
        } else {
            std::cout << "Widget " << id << " has no partner\n";
        }
    }
};

} // namespace heliconia::ptr_examples