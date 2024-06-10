# Minimum CMake version required, we'll just use the latest version.
cmake_minimum_required(VERSION 3.22)
# Project name, version and description
project(ImageToAscii VERSION 1.0 DESCRIPTION "Image to ASCII converter")
 
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
 
# Create an executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    lib/lodepng.cpp
)
# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
