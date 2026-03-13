#include <iostream>

int main() {
double cost, tmp;

std::cout << "Input the cost: ";
std::cin >> cost;

if(cost > 0) {

    tmp = cost * 1.4;
    std::cout << "Profit Price: $" << tmp;


}



}