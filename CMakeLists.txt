cmake_minimum_required(VERSION 3.15...4.0)

project(
	Heliconia 
	VERSION 1.0 
	DESCRIPTION "gardening project" 
	LANGUAGES CXX)

add_executable(heliconia src/helloworld.cpp)

target_include_directories(heliconia PRIVATE src)

