cmake_minimum_required(VERSION 3.0)
project(FactoryTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Boost library
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Include directories
include_directories(${Boost_INCLUDE_DIRS})

# Executable for test
add_executable(Factory_test Factory_test.cpp)

# Link Boost library
target_link_libraries(Factory_test ${Boost_LIBRARIES})