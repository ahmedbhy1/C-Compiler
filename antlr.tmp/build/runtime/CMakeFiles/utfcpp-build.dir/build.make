# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build

# Utility rule file for utfcpp-build.

# Include any custom commands dependencies for this target.
include runtime/CMakeFiles/utfcpp-build.dir/compiler_depend.make

# Include the progress variables for this target.
include runtime/CMakeFiles/utfcpp-build.dir/progress.make

runtime/CMakeFiles/utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Performing build step for 'utfcpp'"
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build && $(MAKE)
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure: runtime/utfcpp-prefix/tmp/utfcpp-cfgcmd.txt
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch_disconnected
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing configure step for 'utfcpp'"
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -DCMAKE_INSTALL_PREFIX=/home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp/install -Dgtest_force_shared_crt=ON "-GUnix Makefiles" -S /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp -B /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch_disconnected: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch-info.txt
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch_disconnected: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-update_disconnected
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No patch_disconnected step for 'utfcpp'"
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E echo_append
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch_disconnected

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-update_disconnected: runtime/utfcpp-prefix/tmp/utfcpp-gitupdate.cmake
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-update_disconnected: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-update-info.txt
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-update_disconnected: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing disconnected update step for 'utfcpp'"
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -Dcan_fetch=NO -P /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/tmp/utfcpp-gitupdate.cmake
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-update_disconnected

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-gitinfo.txt
runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing download step (git clone) for 'utfcpp'"
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/thirdparty && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -P /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/tmp/utfcpp-gitclone.cmake
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/thirdparty && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download

runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'utfcpp'"
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -Dcfgdir= -P /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/tmp/utfcpp-mkdirs.cmake
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir

utfcpp-build: runtime/CMakeFiles/utfcpp-build
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-build
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-configure
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-download
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-mkdir
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-patch_disconnected
utfcpp-build: runtime/utfcpp-prefix/src/utfcpp-stamp/utfcpp-update_disconnected
utfcpp-build: runtime/CMakeFiles/utfcpp-build.dir/build.make
.PHONY : utfcpp-build

# Rule to build all files generated by this target.
runtime/CMakeFiles/utfcpp-build.dir/build: utfcpp-build
.PHONY : runtime/CMakeFiles/utfcpp-build.dir/build

runtime/CMakeFiles/utfcpp-build.dir/clean:
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime && $(CMAKE_COMMAND) -P CMakeFiles/utfcpp-build.dir/cmake_clean.cmake
.PHONY : runtime/CMakeFiles/utfcpp-build.dir/clean

runtime/CMakeFiles/utfcpp-build.dir/depend:
	cd /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/runtime /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime /home/abelhadjyo/Téléchargements/compilateur/pld-comp/antlr.tmp/build/runtime/CMakeFiles/utfcpp-build.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : runtime/CMakeFiles/utfcpp-build.dir/depend

