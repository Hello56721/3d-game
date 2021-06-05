find_path(
    GLFW_INCLUDE_PATH
    NAMES "GLFW/glfw3.h"
    PATHS "${CMAKE_SOURCE_DIR}/libs/GLFW/include"
)

if (WIN32)
    if (MSVC)
        find_library(
            GLFW_LIBRARY
            NAMES "glfw3.lib" "glfw3dll.lib"
            PATHS "${CMAKE_SOURCE_DIR}/libs/GLFW/lib" "${CMAKE_SOURCE_DIR}/libs/GLFW/src" 
                  "${CMAKE_SOURCE_DIR}/libs/GLFW/build/src" "${CMAKE_BINARY_DIR}"
        )
    else()
        find_library(
            GLFW_LIBRARY
            NAMES "libglfw3.a" "libglfw3dll.a"
            PATHS "${CMAKE_SOURCE_DIR}/libs/GLFW/lib" "${CMAKE_SOURCE_DIR}/libs/GLFW/src" 
                  "${CMAKE_SOURCE_DIR}/libs/GLFW/build/src" "${CMAKE_BINARY_DIR}"
        )
    endif()
else()
    find_library(
        GLFW_LIBRARY
        NAMES "libglfw3.a" "libglfw.so"
        PATHS "${CMAKE_SOURCE_DIR}/libs/GLFW/lib" "${CMAKE_SOURCE_DIR}/libs/GLFW/src" 
              "${CMAKE_SOURCE_DIR}/libs/GLFW/build/src" "${CMAKE_BINARY_DIR}"
    )
endif()

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("GLFW" DEFAULT_MSG GLFW_LIBRARY GLFW_INCLUDE_PATH)