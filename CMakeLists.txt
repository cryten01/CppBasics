# Defines the minimum required cmake version
cmake_minimum_required(VERSION 3.14)
# Defines the minimum required C++ version
set(CMAKE_CXX_STANDARD 17)
# Sets the name of the project
project(cppbasics)

# Define global variables
set(ALGODAT algodatlib)
set(CONCEPTS conceptsexec)
set(TESTING testingexec)

# Add content of cmake file from the given subdirectory
add_subdirectory(src)
add_subdirectory(testing)
