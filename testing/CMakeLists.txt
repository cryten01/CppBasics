include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Ensures that each of the named dependencies are populated and potentially added to the build by the time it returns
FetchContent_MakeAvailable(googletest)

# Enables testing for this directory and below
enable_testing()

# Adds an executable target called <name> to be built from the source files listed
add_executable(
        ${TESTING}
        t01_UnorderedArrayTests.cpp
        t02_LinkedListTests.cpp
        t03_StackTests.cpp
        t04_DequeueTests.cpp
        t05_HashTableTests.cpp
        t06_TreeTests.cpp
        ta01_SearchTests.cpp
        ta02_SortTests.cpp
)

# Linking testingExec with gtest_main and src library
target_link_libraries(${TESTING} gtest_main)
target_link_libraries(${TESTING} ${ALGODAT})

# Loads and runs CMake code from the file given
include(GoogleTest)
gtest_discover_tests(${TESTING})