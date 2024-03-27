cmake_minimum_required(VERSION 3.27.2)

# set(CMAKE_INSTALL_PREFIX "C:\\Program Files\\mingw64\\lib")

include(CmakePrintHelpers)
cmake_print_variables(CMAKE_BINARY_DIR CMAKE_INSTALL_PREFIX CMAKE_LIBRARY_PATH)

project(lib_test0)
add_library(lib_test0 adder.cpp)
set_target_properties(lib_test0 PROPERTIES PUBLIC_HEADER adder.hpp)
install(TARGETS lib_test0 ARCHIVE DESTINATION "C:\\Program Files\\mingw64\\lib" PUBLIC_HEADER DESTINATION "C:\\Program Files\\mingw64\\include")