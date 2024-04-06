Learning how to use CMake by following this playlist: https://www.youtube.com/playlist?list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4

Episode 1 Notes:
- Using MinGW compilers: cmake -DCMAKE_C_COMPILER="C:\path\to\gcc.exe" -DCMAKE_CXX_COMPILER="C:\path\to\g++.exe"
- Explicitly specify generator when running build: cmake -G"MinGW Makefiles" -S ..\..\ -B .\
- Downloaded make for Windows: https://gnuwin32.sourceforge.net/packages/make.htm

Episode 2 Notes:
- CMakeLists line for installing to directory (e.g. path for global access to .exe): install(TARGETS ${PROJECT_NAME} DESTINATION "C:\\Program Files (x86)\\GnuWin32\\bin")
- To run makefile for installing: make install
- Extensions: ".a" = static library, ".so" = shared object in Linux, ".dll" = dynamic link library in Windows (Linux's ".so" equivalent)
- When built lib is not accessible through path, directory needs to be specified in CMakeLists.txt: target_link_directories(test1 PRIVATE ${CMAKE_SOURCE_DIR}/path/to/lib)
- When only changing contents of files and not adding files to the build, don't typically need to re-run cmake command.
- "ARCHIVE DESTINATION" instead of "LIBRARY DESTINATION" when installing for ".a" library.

Episode 3 Notes:
- Don't want to push build files nor certain C++ files (see gitignore).
- git submodule add https://github.com/url/to/submodule.git path/to/dir -- example: git submodule add https://github.com/glfw/glfw.git external/glfw
- add_subdirectory(dir) -- dir must have CMakeLists.txt.
- target_link_directories() -- this directive paths starting from its build folder.
- See test0/CMakeLists.txt for downloading all submodules and checking them, for situations like sharing the repo with others so they don't have any missing submodules.

Episode 4 Notes:
- The define directive in the h.in file (test0_config.h.in for this project) must reflect the project name in CMakeLists.txt, so @test0_VERSION_MAJOR@ for this project.
- The pre-processor directive "#cmakedefine" is used by the "configure_file" directive in CMakeLists.txt, which is used in this example to pass the "USE_ADDER" value in the configure stage.

Episode 5 Notes:
- Using CMake lists for varying number of libraries; can turn adder library on for a total of 1 library or off for 0 libraries.

Episode 6 Notes:
- Using CMAKE_INSTALL_PREFIX for installation paths.