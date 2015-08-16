#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Sprout" << std::endl;
        std::cout << "Usage: sprout [sourcefile]" << std::endl;

    } else {
        std::string filePath = argv[1];
    }
}
