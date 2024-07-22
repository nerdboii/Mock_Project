#include <Grid.h>

#include <iostream>

void drawGrid(int size) {
    std::cout << "   ";  // Offset for row numbers
    for (int i = 0; i < size; ++i) {
        std::cout << " " << i << "  ";
    }
    std::cout << "\n";

    // Grid
    for (int i = 0; i < size; ++i) {
        std::cout << "  +";
        for (int j = 0; j < size; ++j) {
            std::cout << "---+";
        }
        std::cout << "\n";

        std::cout << i << " |";  // Row number
        for (int j = 0; j < size; ++j) {
            std::cout << "   |";  // Empty cell
        }
        std::cout << "\n";
    }



    std::cout << "  +";
    for (int j = 0; j < size; ++j) {
        std::cout << "---+";
    }
    std::cout << "\n";
}