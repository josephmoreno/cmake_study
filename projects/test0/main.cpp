#include <iostream>
#include <adder.hpp>
#include <GLFW/glfw3.h>
#include <test0_config.h>

int main(int argc, char** argv) {
    std::cout << mearlymath::add(5, 23) << std::endl;

    std::cout << argv[0] << " Version " << TEST0_VERSION_MAJOR << "." << TEST0_VERSION_MINOR << std::endl; 

    GLFWwindow* window;

    if( !glfwInit() ) {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "whatever", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    while( !glfwWindowShouldClose(window) ) {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return(0);
}