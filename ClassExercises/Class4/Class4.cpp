#include <iostream>


int main() {

char flower;

std::cout << " Enter a case: ";
std::cin >> flower;

switch(flower) {

case 'r':
std::cout << "Rose";
break;
case 'd':
std::cout << "Daffadil";
break;
case 'l':
std::cout << "Lily";
break;
case 's':
std::cout << "Sunflower";
break;
case 'p': 
std::cout << "Poppy";
default:
std::cout << "Invalid";

}

}