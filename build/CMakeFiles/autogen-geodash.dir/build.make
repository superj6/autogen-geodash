# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/rythm/projects/games/autogen-geodash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rythm/projects/games/autogen-geodash/build

# Include any dependencies generated for this target.
include CMakeFiles/autogen-geodash.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/autogen-geodash.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/autogen-geodash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/autogen-geodash.dir/flags.make

CMakeFiles/autogen-geodash.dir/src/game.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/game.cpp.o: ../src/game.cpp
CMakeFiles/autogen-geodash.dir/src/game.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/autogen-geodash.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/game.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/game.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/game.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/game.cpp

CMakeFiles/autogen-geodash.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/game.cpp > CMakeFiles/autogen-geodash.dir/src/game.cpp.i

CMakeFiles/autogen-geodash.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/game.cpp -o CMakeFiles/autogen-geodash.dir/src/game.cpp.s

CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o: ../src/game_level.cpp
CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/game_level.cpp

CMakeFiles/autogen-geodash.dir/src/game_level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/game_level.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/game_level.cpp > CMakeFiles/autogen-geodash.dir/src/game_level.cpp.i

CMakeFiles/autogen-geodash.dir/src/game_level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/game_level.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/game_level.cpp -o CMakeFiles/autogen-geodash.dir/src/game_level.cpp.s

CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o: ../src/game_object.cpp
CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/game_object.cpp

CMakeFiles/autogen-geodash.dir/src/game_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/game_object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/game_object.cpp > CMakeFiles/autogen-geodash.dir/src/game_object.cpp.i

CMakeFiles/autogen-geodash.dir/src/game_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/game_object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/game_object.cpp -o CMakeFiles/autogen-geodash.dir/src/game_object.cpp.s

CMakeFiles/autogen-geodash.dir/src/main.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/autogen-geodash.dir/src/main.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/autogen-geodash.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/main.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/main.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/main.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/main.cpp

CMakeFiles/autogen-geodash.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/main.cpp > CMakeFiles/autogen-geodash.dir/src/main.cpp.i

CMakeFiles/autogen-geodash.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/main.cpp -o CMakeFiles/autogen-geodash.dir/src/main.cpp.s

CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o: ../src/resource_manager.cpp
CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/resource_manager.cpp

CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/resource_manager.cpp > CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.i

CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/resource_manager.cpp -o CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.s

CMakeFiles/autogen-geodash.dir/src/shader.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/shader.cpp.o: ../src/shader.cpp
CMakeFiles/autogen-geodash.dir/src/shader.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/autogen-geodash.dir/src/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/shader.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/shader.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/shader.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/shader.cpp

CMakeFiles/autogen-geodash.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/shader.cpp > CMakeFiles/autogen-geodash.dir/src/shader.cpp.i

CMakeFiles/autogen-geodash.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/shader.cpp -o CMakeFiles/autogen-geodash.dir/src/shader.cpp.s

CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o: ../src/sprite_renderer.cpp
CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/sprite_renderer.cpp

CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/sprite_renderer.cpp > CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.i

CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/sprite_renderer.cpp -o CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.s

CMakeFiles/autogen-geodash.dir/src/texture.cpp.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/src/texture.cpp.o: ../src/texture.cpp
CMakeFiles/autogen-geodash.dir/src/texture.cpp.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/autogen-geodash.dir/src/texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/src/texture.cpp.o -MF CMakeFiles/autogen-geodash.dir/src/texture.cpp.o.d -o CMakeFiles/autogen-geodash.dir/src/texture.cpp.o -c /home/rythm/projects/games/autogen-geodash/src/texture.cpp

CMakeFiles/autogen-geodash.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autogen-geodash.dir/src/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rythm/projects/games/autogen-geodash/src/texture.cpp > CMakeFiles/autogen-geodash.dir/src/texture.cpp.i

CMakeFiles/autogen-geodash.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autogen-geodash.dir/src/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rythm/projects/games/autogen-geodash/src/texture.cpp -o CMakeFiles/autogen-geodash.dir/src/texture.cpp.s

CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o: CMakeFiles/autogen-geodash.dir/flags.make
CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o: ../vendor/glad/src/glad.c
CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o: CMakeFiles/autogen-geodash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o -MF CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o.d -o CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o -c /home/rythm/projects/games/autogen-geodash/vendor/glad/src/glad.c

CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rythm/projects/games/autogen-geodash/vendor/glad/src/glad.c > CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.i

CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rythm/projects/games/autogen-geodash/vendor/glad/src/glad.c -o CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.s

# Object files for target autogen-geodash
autogen__geodash_OBJECTS = \
"CMakeFiles/autogen-geodash.dir/src/game.cpp.o" \
"CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o" \
"CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o" \
"CMakeFiles/autogen-geodash.dir/src/main.cpp.o" \
"CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o" \
"CMakeFiles/autogen-geodash.dir/src/shader.cpp.o" \
"CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o" \
"CMakeFiles/autogen-geodash.dir/src/texture.cpp.o" \
"CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o"

# External object files for target autogen-geodash
autogen__geodash_EXTERNAL_OBJECTS =

../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/game.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/game_level.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/game_object.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/main.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/resource_manager.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/shader.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/sprite_renderer.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/src/texture.cpp.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/vendor/glad/src/glad.c.o
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/build.make
../bin/autogen-geodash: CMakeFiles/autogen-geodash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rythm/projects/games/autogen-geodash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../bin/autogen-geodash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/autogen-geodash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/autogen-geodash.dir/build: ../bin/autogen-geodash
.PHONY : CMakeFiles/autogen-geodash.dir/build

CMakeFiles/autogen-geodash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/autogen-geodash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/autogen-geodash.dir/clean

CMakeFiles/autogen-geodash.dir/depend:
	cd /home/rythm/projects/games/autogen-geodash/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rythm/projects/games/autogen-geodash /home/rythm/projects/games/autogen-geodash /home/rythm/projects/games/autogen-geodash/build /home/rythm/projects/games/autogen-geodash/build /home/rythm/projects/games/autogen-geodash/build/CMakeFiles/autogen-geodash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/autogen-geodash.dir/depend

