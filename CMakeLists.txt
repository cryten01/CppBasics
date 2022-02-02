cmake_minimum_required(VERSION 3.10)
project(CppBasics)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppBasics src/main.cpp src/Concepts.cpp src/Concepts.h src/Preprocessor.cpp src/Preprocessor.h src/DynamicArray.cpp src/DynamicArray.h src/SuperclassA.cpp src/SuperclassA.h src/Templates.h src/Container.cpp src/Container.h)