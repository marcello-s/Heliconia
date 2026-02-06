# HELICONIA

Learn about the latest C++ standard. How to build using CMake and how to unit-test.


## Build Instructions

```
$ cmake -S . -B build
$ cmake --build build --config Release --target heliconia --verbose
$ cmake --build build --config Release --target tests --verbose
```

### Libraries

json, https://github.com/nlohmann/json

for cmake, https://json.nlohmann.me/integration/cmake/#external
```
$ git submodule add https://github.com/nlohmann/json.git libs/json
$ git submodule update --init --recursive
```

unit-tests catch2, https://github.com/catchorg/Catch2.git
for cmake, https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md

```
$ git submodule add https://github.com/catchorg/Catch2.git libs/catch2
$ git submodule update --init --recursive
```