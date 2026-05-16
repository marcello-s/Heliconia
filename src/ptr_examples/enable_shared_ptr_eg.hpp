#include <iostream>
#include <memory>

namespace heliconia::ptr_examples {

class Controller : public std::enable_shared_from_this<Controller> {
public:
    void registerSelf() {
        auto self = shared_from_this();
        std::cout << "Controller registered with shared pointer count: " << self.use_count() << std::endl;
    }

    static std::shared_ptr<Controller> create() {
        return std::shared_ptr<Controller>(new Controller());
    }
};

} // namespace heliconia::ptr_examples