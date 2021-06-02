cmake_minimum_required(VERSION 3.16)

project("3D Game")

# Use C++17
set(CMAKE_CXX_STANDARD 17)
# Set the place where I put package finders
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Add a extension to the executable on linux based systems
if (UNIX AND NOT APPLE)
    set(3D_GAME_EXE_NAME "3d-game.out")
else()
    set(3D_GAME_EXE_NAME "3d-game")
endif()

# Add high warning levels
if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

# Add the glad library
add_library("glad" "src/glad/glad.c")
# Find the GLFW library
find_package("GLFW")

# Add the include directories
include_directories("include")

# Link the system specific libraries
if (WIN32)
    link_libraries("gdi32" "opengl32")
elseif(UNIX AND NOT APPLE)
    link_libraries("GL" "X11" "pthread" "Xrandr" "dl")
endif()

# Add the libraries
link_libraries("glad" "${GLFW_LIBRARY}")

add_executable("${3D_GAME_EXE_NAME}")

add_subdirectory("src")
add_subdirectory("include")