# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gerhard/CLionProjects/CppBasics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gerhard/CLionProjects/CppBasics/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CppBasics.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CppBasics.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CppBasics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CppBasics.dir/flags.make

CMakeFiles/CppBasics.dir/src/main.cpp.o: CMakeFiles/CppBasics.dir/flags.make
CMakeFiles/CppBasics.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/CppBasics.dir/src/main.cpp.o: CMakeFiles/CppBasics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CppBasics.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CppBasics.dir/src/main.cpp.o -MF CMakeFiles/CppBasics.dir/src/main.cpp.o.d -o CMakeFiles/CppBasics.dir/src/main.cpp.o -c /Users/gerhard/CLionProjects/CppBasics/src/main.cpp

CMakeFiles/CppBasics.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppBasics.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gerhard/CLionProjects/CppBasics/src/main.cpp > CMakeFiles/CppBasics.dir/src/main.cpp.i

CMakeFiles/CppBasics.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppBasics.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gerhard/CLionProjects/CppBasics/src/main.cpp -o CMakeFiles/CppBasics.dir/src/main.cpp.s

CMakeFiles/CppBasics.dir/src/Concepts.cpp.o: CMakeFiles/CppBasics.dir/flags.make
CMakeFiles/CppBasics.dir/src/Concepts.cpp.o: ../src/Concepts.cpp
CMakeFiles/CppBasics.dir/src/Concepts.cpp.o: CMakeFiles/CppBasics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CppBasics.dir/src/Concepts.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CppBasics.dir/src/Concepts.cpp.o -MF CMakeFiles/CppBasics.dir/src/Concepts.cpp.o.d -o CMakeFiles/CppBasics.dir/src/Concepts.cpp.o -c /Users/gerhard/CLionProjects/CppBasics/src/Concepts.cpp

CMakeFiles/CppBasics.dir/src/Concepts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppBasics.dir/src/Concepts.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gerhard/CLionProjects/CppBasics/src/Concepts.cpp > CMakeFiles/CppBasics.dir/src/Concepts.cpp.i

CMakeFiles/CppBasics.dir/src/Concepts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppBasics.dir/src/Concepts.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gerhard/CLionProjects/CppBasics/src/Concepts.cpp -o CMakeFiles/CppBasics.dir/src/Concepts.cpp.s

CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o: CMakeFiles/CppBasics.dir/flags.make
CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o: ../src/Preprocessor.cpp
CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o: CMakeFiles/CppBasics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o -MF CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o.d -o CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o -c /Users/gerhard/CLionProjects/CppBasics/src/Preprocessor.cpp

CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gerhard/CLionProjects/CppBasics/src/Preprocessor.cpp > CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.i

CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gerhard/CLionProjects/CppBasics/src/Preprocessor.cpp -o CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.s

CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o: CMakeFiles/CppBasics.dir/flags.make
CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o: ../src/DynamicArray.cpp
CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o: CMakeFiles/CppBasics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o -MF CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o.d -o CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o -c /Users/gerhard/CLionProjects/CppBasics/src/DynamicArray.cpp

CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gerhard/CLionProjects/CppBasics/src/DynamicArray.cpp > CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.i

CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gerhard/CLionProjects/CppBasics/src/DynamicArray.cpp -o CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.s

CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o: CMakeFiles/CppBasics.dir/flags.make
CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o: ../src/SuperclassA.cpp
CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o: CMakeFiles/CppBasics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o -MF CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o.d -o CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o -c /Users/gerhard/CLionProjects/CppBasics/src/SuperclassA.cpp

CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gerhard/CLionProjects/CppBasics/src/SuperclassA.cpp > CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.i

CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gerhard/CLionProjects/CppBasics/src/SuperclassA.cpp -o CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.s

CMakeFiles/CppBasics.dir/src/Container.cpp.o: CMakeFiles/CppBasics.dir/flags.make
CMakeFiles/CppBasics.dir/src/Container.cpp.o: ../src/Container.cpp
CMakeFiles/CppBasics.dir/src/Container.cpp.o: CMakeFiles/CppBasics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CppBasics.dir/src/Container.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CppBasics.dir/src/Container.cpp.o -MF CMakeFiles/CppBasics.dir/src/Container.cpp.o.d -o CMakeFiles/CppBasics.dir/src/Container.cpp.o -c /Users/gerhard/CLionProjects/CppBasics/src/Container.cpp

CMakeFiles/CppBasics.dir/src/Container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppBasics.dir/src/Container.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gerhard/CLionProjects/CppBasics/src/Container.cpp > CMakeFiles/CppBasics.dir/src/Container.cpp.i

CMakeFiles/CppBasics.dir/src/Container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppBasics.dir/src/Container.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gerhard/CLionProjects/CppBasics/src/Container.cpp -o CMakeFiles/CppBasics.dir/src/Container.cpp.s

# Object files for target CppBasics
CppBasics_OBJECTS = \
"CMakeFiles/CppBasics.dir/src/main.cpp.o" \
"CMakeFiles/CppBasics.dir/src/Concepts.cpp.o" \
"CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o" \
"CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o" \
"CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o" \
"CMakeFiles/CppBasics.dir/src/Container.cpp.o"

# External object files for target CppBasics
CppBasics_EXTERNAL_OBJECTS =

CppBasics: CMakeFiles/CppBasics.dir/src/main.cpp.o
CppBasics: CMakeFiles/CppBasics.dir/src/Concepts.cpp.o
CppBasics: CMakeFiles/CppBasics.dir/src/Preprocessor.cpp.o
CppBasics: CMakeFiles/CppBasics.dir/src/DynamicArray.cpp.o
CppBasics: CMakeFiles/CppBasics.dir/src/SuperclassA.cpp.o
CppBasics: CMakeFiles/CppBasics.dir/src/Container.cpp.o
CppBasics: CMakeFiles/CppBasics.dir/build.make
CppBasics: CMakeFiles/CppBasics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable CppBasics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppBasics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CppBasics.dir/build: CppBasics
.PHONY : CMakeFiles/CppBasics.dir/build

CMakeFiles/CppBasics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CppBasics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CppBasics.dir/clean

CMakeFiles/CppBasics.dir/depend:
	cd /Users/gerhard/CLionProjects/CppBasics/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gerhard/CLionProjects/CppBasics /Users/gerhard/CLionProjects/CppBasics /Users/gerhard/CLionProjects/CppBasics/cmake-build-debug /Users/gerhard/CLionProjects/CppBasics/cmake-build-debug /Users/gerhard/CLionProjects/CppBasics/cmake-build-debug/CMakeFiles/CppBasics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CppBasics.dir/depend

