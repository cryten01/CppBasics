# Creates a library with the given source files
# Add files here that should be tested with google test
add_library(
        ${ALGODAT}
        03_DataStructures/Datastructures.h
        04_Algorithms/Algorithms.h
        04_Algorithms/Search.cpp
)

# Add files here that do not need google test to run
add_executable(
        ${CONCEPTS}
        main.cpp
        01_General/GeneralConcepts.h
        02_Specific/SpecificConcepts.h
)