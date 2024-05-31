cmake_minimum_required(VERSION 3.10)
project(Pizza-Finder VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(src/Area)
include_directories(src/Location)
include_directories(src/Main)
include_directories(src/Menu)
include_directories(src/PizzaBranch)

# Add executable
add_executable(Pizza src/Main/main.cpp)

# Linking other source files
target_sources(Pizza PRIVATE
    src/Area/Area.cpp
    src/PizzaBranch/kdTree.cpp
    src/PizzaBranch/branchClass.cpp
    src/PizzaBranch/dataStructure.cpp
    src/Location/Location.cpp
    src/Menu/MainFunctions.cpp
    src/Menu/menu.cpp
)
