#include "unique_ptr_eg.hpp"
#include <iostream>
#include <memory>
#include <string>

Resource::Resource(const std::string& name) : name_(name) {
    std::cout << "Resource " << name_ << " acquired.\n";
}

Resource::~Resource() {
    std::cout << "Resource " << name_ << " released.\n";
}

void Resource::use() {
    std::cout << "Using resource " << name_ << ".\n";
}

// Factory returning a unique_ptr to a Resource
std::unique_ptr<Resource> createResource(const std::string& name) {
    return std::make_unique<Resource>(name);
}

void takeOwnership(std::unique_ptr<Resource> res) {
    std::cout << "Taking ownership of resource.\n";
    res->use();
}
