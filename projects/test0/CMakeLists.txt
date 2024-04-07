cmake_minimum_required(VERSION 3.27.2)

project(test0 VERSION 1.0)

option(USE_ADDER "Library for adding two ints or floats." ON)
if(USE_ADDER)
    add_subdirectory(adder)
    list(APPEND LIST_LIB_DIRS "${PROJECT_SOURCE_DIR}/adder")
    list(APPEND LIST_INCL_DIRS "${PROJECT_SOURCE_DIR}/adder")
    list(APPEND LIST_LINKS adder)

    # target_include_directories(${PROJECT_NAME} PUBLIC adder)
    # target_link_directories(${PROJECT_NAME} PRIVATE adder)
endif()

configure_file(test0_config.h.in test0_config.h)
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# include(CmakePrintHelpers)
# cmake_print_variables(PROJECT_BINARY_DIR PROJECT_SOURCE_DIR CMAKE_INSTALL_PREFIX)

# Download all the submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)

    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# Check all the submodules
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL ERROR "The glfw submodules was not downloaded! GIT SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
    ${LIST_INCL_DIRS}
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
    ${LIST_LIB_DIRS}
)

target_link_libraries(${PROJECT_NAME} glfw ${LIST_LINKS})

install(TARGETS ${PROJECT_NAME})
install(FILES "${PROJECT_BINARY_DIR}/test0_config.h" DESTINATION "./include")

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${test0_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${test0_VERSION_MINOR}")
include(CPack)