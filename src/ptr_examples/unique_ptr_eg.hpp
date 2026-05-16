#pragma once
#include <memory>
#include <string>

namespace heliconia::ptr_examples {

class Resource {
public:
    Resource(const std::string& name);
    ~Resource();
    void use();

private:
    std::string name_;
};

std::unique_ptr<Resource> createResource(const std::string& name);
void takeOwnership(std::unique_ptr<Resource> res);

} // namespace heliconia::ptr_examples