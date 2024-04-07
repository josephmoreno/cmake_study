cmake_minimum_required(VERSION 3.27.2)

add_library(adder adder.cpp)

install(TARGETS adder DESTINATION "./lib")
install(FILES adder.hpp DESTINATION "./include")