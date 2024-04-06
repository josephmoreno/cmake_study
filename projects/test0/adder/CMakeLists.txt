cmake_minimum_required(VERSION 3.27.2)

add_library(adder adder.cpp)

install(TARGETS adder DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES adder.hpp DESTINATION "${CMAKE_INSTALL_PREFIX}/include")