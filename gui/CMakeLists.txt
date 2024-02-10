cmake_minimum_required(VERSION 3.10)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the required packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)

# Name the library
add_library(gui gui.cpp gui.hpp)

# Specify the include directory for the library
target_include_directories(gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Link the executable to the OpenGL, GLEW, and GLFW libraries
target_link_libraries(gui PUBLIC GL GLEW glfw)
target_link_libraries(gui PUBLIC glm::glm)
