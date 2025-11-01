cmake_minimum_required(VERSION 3.15...4.0)

project(
	Heliconia 
	VERSION 1.0 
	DESCRIPTION "gardening project" 
	LANGUAGES CXX)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(libs/json)

add_executable(heliconia 
	src/helloworld.cpp
	src/scan.cpp
	src/list_files.cpp)

target_include_directories(heliconia PRIVATE src)

target_link_libraries(heliconia PRIVATE nlohmann_json::nlohmann_json)
target_compile_features(heliconia PRIVATE cxx_std_23)


add_subdirectory(libs/catch2)

add_executable(tests 
	test/testcase.cpp)

target_include_directories(tests PRIVATE test)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_compile_features(tests PRIVATE cxx_std_23)

include(CTest)
include(Catch)
catch_discover_tests(tests)