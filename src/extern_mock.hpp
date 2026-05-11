#include <iostream>
#include <memory>
#include <cstdlib>

// extern C API, mock for testing
extern "C" {
    // Simulates a C function that allocates and returns via out-parameter
    void c_api_create(int** out_handle) {
        *out_handle = static_cast<int*>(std::malloc(sizeof(int)));
        **out_handle = 42; // mock value
    }

    void c_api_destroy(int* handle) {
        std::free(handle);
    }
}