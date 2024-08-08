# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wallace/Projects/binary_trees/btree_dsl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wallace/Projects/binary_trees/btree_dsl/build

# Include any dependencies generated for this target.
include CMakeFiles/program.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/program.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program.dir/flags.make

CMakeFiles/program.dir/dsl_compiler.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/dsl_compiler.cpp.o: /home/wallace/Projects/binary_trees/btree_dsl/dsl_compiler.cpp
CMakeFiles/program.dir/dsl_compiler.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wallace/Projects/binary_trees/btree_dsl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program.dir/dsl_compiler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/dsl_compiler.cpp.o -MF CMakeFiles/program.dir/dsl_compiler.cpp.o.d -o CMakeFiles/program.dir/dsl_compiler.cpp.o -c /home/wallace/Projects/binary_trees/btree_dsl/dsl_compiler.cpp

CMakeFiles/program.dir/dsl_compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/dsl_compiler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wallace/Projects/binary_trees/btree_dsl/dsl_compiler.cpp > CMakeFiles/program.dir/dsl_compiler.cpp.i

CMakeFiles/program.dir/dsl_compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/dsl_compiler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wallace/Projects/binary_trees/btree_dsl/dsl_compiler.cpp -o CMakeFiles/program.dir/dsl_compiler.cpp.s

CMakeFiles/program.dir/dsl_tokenizer.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/dsl_tokenizer.cpp.o: /home/wallace/Projects/binary_trees/btree_dsl/dsl_tokenizer.cpp
CMakeFiles/program.dir/dsl_tokenizer.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wallace/Projects/binary_trees/btree_dsl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/program.dir/dsl_tokenizer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/dsl_tokenizer.cpp.o -MF CMakeFiles/program.dir/dsl_tokenizer.cpp.o.d -o CMakeFiles/program.dir/dsl_tokenizer.cpp.o -c /home/wallace/Projects/binary_trees/btree_dsl/dsl_tokenizer.cpp

CMakeFiles/program.dir/dsl_tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/dsl_tokenizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wallace/Projects/binary_trees/btree_dsl/dsl_tokenizer.cpp > CMakeFiles/program.dir/dsl_tokenizer.cpp.i

CMakeFiles/program.dir/dsl_tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/dsl_tokenizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wallace/Projects/binary_trees/btree_dsl/dsl_tokenizer.cpp -o CMakeFiles/program.dir/dsl_tokenizer.cpp.s

CMakeFiles/program.dir/dsl_tree.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/dsl_tree.cpp.o: /home/wallace/Projects/binary_trees/btree_dsl/dsl_tree.cpp
CMakeFiles/program.dir/dsl_tree.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wallace/Projects/binary_trees/btree_dsl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/program.dir/dsl_tree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/dsl_tree.cpp.o -MF CMakeFiles/program.dir/dsl_tree.cpp.o.d -o CMakeFiles/program.dir/dsl_tree.cpp.o -c /home/wallace/Projects/binary_trees/btree_dsl/dsl_tree.cpp

CMakeFiles/program.dir/dsl_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/program.dir/dsl_tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wallace/Projects/binary_trees/btree_dsl/dsl_tree.cpp > CMakeFiles/program.dir/dsl_tree.cpp.i

CMakeFiles/program.dir/dsl_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/program.dir/dsl_tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wallace/Projects/binary_trees/btree_dsl/dsl_tree.cpp -o CMakeFiles/program.dir/dsl_tree.cpp.s

# Object files for target program
program_OBJECTS = \
"CMakeFiles/program.dir/dsl_compiler.cpp.o" \
"CMakeFiles/program.dir/dsl_tokenizer.cpp.o" \
"CMakeFiles/program.dir/dsl_tree.cpp.o"

# External object files for target program
program_EXTERNAL_OBJECTS =

/home/wallace/Projects/binary_trees/btree_dsl/program: CMakeFiles/program.dir/dsl_compiler.cpp.o
/home/wallace/Projects/binary_trees/btree_dsl/program: CMakeFiles/program.dir/dsl_tokenizer.cpp.o
/home/wallace/Projects/binary_trees/btree_dsl/program: CMakeFiles/program.dir/dsl_tree.cpp.o
/home/wallace/Projects/binary_trees/btree_dsl/program: CMakeFiles/program.dir/build.make
/home/wallace/Projects/binary_trees/btree_dsl/program: CMakeFiles/program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/wallace/Projects/binary_trees/btree_dsl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable /home/wallace/Projects/binary_trees/btree_dsl/program"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/program.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program.dir/build: /home/wallace/Projects/binary_trees/btree_dsl/program
.PHONY : CMakeFiles/program.dir/build

CMakeFiles/program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/program.dir/cmake_clean.cmake
.PHONY : CMakeFiles/program.dir/clean

CMakeFiles/program.dir/depend:
	cd /home/wallace/Projects/binary_trees/btree_dsl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wallace/Projects/binary_trees/btree_dsl /home/wallace/Projects/binary_trees/btree_dsl /home/wallace/Projects/binary_trees/btree_dsl/build /home/wallace/Projects/binary_trees/btree_dsl/build /home/wallace/Projects/binary_trees/btree_dsl/build/CMakeFiles/program.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/program.dir/depend

