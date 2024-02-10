cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(pbr VERSION 1.0)

# Add library and directory
add_subdirectory(gui)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(pbr main.cpp)

# Link Libraries
target_link_libraries(pbr PRIVATE gui)

