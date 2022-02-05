# Defines the minimum required cmake version
cmake_minimum_required(VERSION 3.14)
# Defines the minimum required C++ version
set(CMAKE_CXX_STANDARD 17)
# Sets the name of the project
project(cppbasics)

# Defines a path variable
set(DATASTRUCTURES src/03_DataStructures)
# Defines a variable for the library name
set(LIBNAME datastructures)
# Creates a library with the given source files
add_library(
    ${LIBNAME}
        ${DATASTRUCTURES}/OrderedArray.h
        ${DATASTRUCTURES}/OrderedArray.cpp
        ${DATASTRUCTURES}/LinkedList.h
        ${DATASTRUCTURES}/LinkedList.cpp
)

# Add content of cmake file from the given subdirectory
add_subdirectory(testing)
