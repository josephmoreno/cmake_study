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