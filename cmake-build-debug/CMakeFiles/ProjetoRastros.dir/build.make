# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/103/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/103/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mariana/GitHub/LI2-PL8-Grp12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjetoRastros.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetoRastros.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetoRastros.dir/flags.make

CMakeFiles/ProjetoRastros.dir/main.c.o: CMakeFiles/ProjetoRastros.dir/flags.make
CMakeFiles/ProjetoRastros.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjetoRastros.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoRastros.dir/main.c.o   -c /home/mariana/GitHub/LI2-PL8-Grp12/main.c

CMakeFiles/ProjetoRastros.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoRastros.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/GitHub/LI2-PL8-Grp12/main.c > CMakeFiles/ProjetoRastros.dir/main.c.i

CMakeFiles/ProjetoRastros.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoRastros.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/GitHub/LI2-PL8-Grp12/main.c -o CMakeFiles/ProjetoRastros.dir/main.c.s

CMakeFiles/ProjetoRastros.dir/Mapa.c.o: CMakeFiles/ProjetoRastros.dir/flags.make
CMakeFiles/ProjetoRastros.dir/Mapa.c.o: ../Mapa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjetoRastros.dir/Mapa.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoRastros.dir/Mapa.c.o   -c /home/mariana/GitHub/LI2-PL8-Grp12/Mapa.c

CMakeFiles/ProjetoRastros.dir/Mapa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoRastros.dir/Mapa.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/GitHub/LI2-PL8-Grp12/Mapa.c > CMakeFiles/ProjetoRastros.dir/Mapa.c.i

CMakeFiles/ProjetoRastros.dir/Mapa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoRastros.dir/Mapa.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/GitHub/LI2-PL8-Grp12/Mapa.c -o CMakeFiles/ProjetoRastros.dir/Mapa.c.s

CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.o: CMakeFiles/ProjetoRastros.dir/flags.make
CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.o: ../Logica_Programa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.o   -c /home/mariana/GitHub/LI2-PL8-Grp12/Logica_Programa.c

CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/GitHub/LI2-PL8-Grp12/Logica_Programa.c > CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.i

CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/GitHub/LI2-PL8-Grp12/Logica_Programa.c -o CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.s

CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.o: CMakeFiles/ProjetoRastros.dir/flags.make
CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.o: ../Camada_Interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.o   -c /home/mariana/GitHub/LI2-PL8-Grp12/Camada_Interface.c

CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/GitHub/LI2-PL8-Grp12/Camada_Interface.c > CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.i

CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/GitHub/LI2-PL8-Grp12/Camada_Interface.c -o CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.s

CMakeFiles/ProjetoRastros.dir/Camada_dados.c.o: CMakeFiles/ProjetoRastros.dir/flags.make
CMakeFiles/ProjetoRastros.dir/Camada_dados.c.o: ../Camada_dados.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ProjetoRastros.dir/Camada_dados.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoRastros.dir/Camada_dados.c.o   -c /home/mariana/GitHub/LI2-PL8-Grp12/Camada_dados.c

CMakeFiles/ProjetoRastros.dir/Camada_dados.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoRastros.dir/Camada_dados.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/GitHub/LI2-PL8-Grp12/Camada_dados.c > CMakeFiles/ProjetoRastros.dir/Camada_dados.c.i

CMakeFiles/ProjetoRastros.dir/Camada_dados.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoRastros.dir/Camada_dados.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/GitHub/LI2-PL8-Grp12/Camada_dados.c -o CMakeFiles/ProjetoRastros.dir/Camada_dados.c.s

# Object files for target ProjetoRastros
ProjetoRastros_OBJECTS = \
"CMakeFiles/ProjetoRastros.dir/main.c.o" \
"CMakeFiles/ProjetoRastros.dir/Mapa.c.o" \
"CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.o" \
"CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.o" \
"CMakeFiles/ProjetoRastros.dir/Camada_dados.c.o"

# External object files for target ProjetoRastros
ProjetoRastros_EXTERNAL_OBJECTS =

ProjetoRastros: CMakeFiles/ProjetoRastros.dir/main.c.o
ProjetoRastros: CMakeFiles/ProjetoRastros.dir/Mapa.c.o
ProjetoRastros: CMakeFiles/ProjetoRastros.dir/Logica_Programa.c.o
ProjetoRastros: CMakeFiles/ProjetoRastros.dir/Camada_Interface.c.o
ProjetoRastros: CMakeFiles/ProjetoRastros.dir/Camada_dados.c.o
ProjetoRastros: CMakeFiles/ProjetoRastros.dir/build.make
ProjetoRastros: CMakeFiles/ProjetoRastros.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ProjetoRastros"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjetoRastros.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetoRastros.dir/build: ProjetoRastros

.PHONY : CMakeFiles/ProjetoRastros.dir/build

CMakeFiles/ProjetoRastros.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjetoRastros.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjetoRastros.dir/clean

CMakeFiles/ProjetoRastros.dir/depend:
	cd /home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariana/GitHub/LI2-PL8-Grp12 /home/mariana/GitHub/LI2-PL8-Grp12 /home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug /home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug /home/mariana/GitHub/LI2-PL8-Grp12/cmake-build-debug/CMakeFiles/ProjetoRastros.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjetoRastros.dir/depend

