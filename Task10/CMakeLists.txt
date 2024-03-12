cmake_minimum_required(VERSION 3.10)
project(Abstract_Factory)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(Abstract_Factory ${SOURCES})
