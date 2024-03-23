cmake_minimum_required(VERSION 3.27.2)

project(cmake_study)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION "C:\\Program Files (x86)\\GnuWin32\\bin")