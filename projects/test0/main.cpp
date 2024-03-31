#include <iostream>
// #include <adder.hpp>
#include <GLFW/glfw3.h>
#include <test0_config.h>

#ifdef USE_ADDER
    #include <adder.hpp>
#endif

int main(int argc, char** argv) {

#ifdef USE_ADDER
    std::cout << mearlymath::add(5, 23) << std::endl;
#else
    std::cout << "HALLO" << std::endl;
#endif

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