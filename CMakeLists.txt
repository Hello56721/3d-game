cmake_minimum_required(VERSION 3.16)

project("3D Game")

# Use C++17
set(CMAKE_CXX_STANDARD 17)
# Set the place where I put package finders
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Add high warning levels
if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

option(OPENGL_DEBUG "Wether or not to enable (basic) OpenGL call checking." "on")

# Add the glad library
add_library("glad" "src/glad/glad.c")
# Find the GLFW library
find_package("GLFW")

# Add the include directories
include_directories("include" "${GLFW_INCLUDE_PATH}" "${CMAKE_BINARY_DIR}")

# Link the system specific libraries
if (WIN32)
    link_libraries("gdi32" "opengl32")
elseif(UNIX AND NOT APPLE)
    link_libraries("GL" "X11" "pthread" "Xrandr" "dl")
endif()

# Add the libraries
link_libraries("glad" "${GLFW_LIBRARY}")

configure_file("cmake_configuration.src.hpp" "cmake_configuration.hpp")

add_executable("3d-game")
add_library("3d-game-engine")

add_subdirectory("src")
add_subdirectory("include")

# Link the target libraries
target_link_libraries("3d-game" "3d-game-engine")