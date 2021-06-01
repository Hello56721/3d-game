cmake_minimum_required(VERSION 3.16)

project("3D Game")

# Use C++17
set(CMAKE_CXX_STANDARD 17)

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

# Add the include directories
include_directories("include")

add_executable("${3D_GAME_EXE_NAME}")

add_subdirectory("src")
add_subdirectory("include")