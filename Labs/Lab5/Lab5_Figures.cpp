#include <iostream>


void filledSquare(int var1, char var2) {
    // solid square
    for (int var3 = 0; var3 < var1; var3++) {
        for (int var4 = 0; var4 < var1; var4++) {
            std::cout << var2;
        }
        std::cout << '\n';
    }

}

void backslash(int var1, char var2) {
    // diagonal: top-left -> bottom-right
    for (int var3 = 0; var3 < var1; var3++) {
        for (int var4 = 0; var4 < var1; var4++) {
            if (var4 == var3) std::cout << var2;
            else              std::cout << ' ';
        }
        std::cout << '\n';
    }

}

void slash(int var1, char var2) {
    // diagonal: top-right -> bottom-left
    for (int var3 = 0; var3 < var1; var3++) {
        for (int var4 = 0; var4 < var1; var4++) {
            if (var4 == (var1 - 1 - var3)) std::cout << var2;
            else                            std::cout << ' ';
        }
        std::cout << '\n';
    }

}

void hollowsquare(int var1, char var2) {
    // hollow square
    for (int var3 = 0; var3 < var1; var3++) {
        for (int var4 = 0; var4 < var1; var4++) {
            if (var3 == 0) std::cout << var2;
            else if (var3 == var1 - 1) std::cout << var2;
            else if (var4 == 0) std::cout << var2;
            else if (var4 == var1 - 1) std::cout << var2;
            else std::cout << ' ';
        }
        std::cout << '\n';
    }

}

void x(int var1, char var2) {
    // X shape
    for (int var3 = 0; var3 < var1; var3++) {
        for (int var4 = 0; var4 < var1; var4++) {
            if (var4 == var3 || var4 == (var1 - 1 - var3)) std::cout << var2;
            else                                           std::cout << ' ';
        }
        std::cout << '\n';
    }

}

int main() {
    std::cout << "Input figure size: ";
    int var1;
    std::cin >> var1;

    std::cout << "Input paint character: ";
    char var2;
    std::cin >> var2;

    filledSquare(var1, var2);
    std::cout << '\n';

    backslash(var1, var2);
    std::cout << '\n';

    slash(var1, var2);
    std::cout << '\n';

    hollowsquare(var1, var2);
    std::cout << '\n';

    x(var1, var2);

    return 0;
}
