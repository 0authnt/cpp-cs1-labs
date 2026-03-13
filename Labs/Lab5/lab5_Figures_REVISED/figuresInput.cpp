#include <iostream>
#include "figures.hpp"

int main() {
    std::cout << "Input figure size: ";
    int var1;
    std::cin >> var1;

    std::cout << "Input paint character: ";
    char var2;
    std::cin >> var2;

    std::cout << "Select figure:\n";
    std::cout << "1. Filled Square\n";
    std::cout << "2. Backslash\n";
    std::cout << "3. Slash\n";
    std::cout << "4. Hollow Square\n";
    std::cout << "5. X\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        filledSquare(var1, var2);
    } else if (choice == 2) {
        backslash(var1, var2);
    } else if (choice == 3) {
        slash(var1, var2);
    } else if (choice == 4) {
        hollowsquare(var1, var2);
    } else if (choice == 5) {
        x(var1, var2);
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
