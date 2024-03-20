#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Hello" << std::endl;

    if (argc > 1) {
        std::cout << "There are " << argc << " arguments provided:" << std::endl;

        for(unsigned int i = 0; i < argc; ++i)
            std::cout << argv[i] << std::endl;
    }
    
    return(0);
}