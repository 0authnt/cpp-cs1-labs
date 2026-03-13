#include <iostream>

int main() {
int i;
int w=0; // sum variable
std::cout << "Input a sequence of numbers";
while (true) // while (true) creates an infinite loop
{ 
std::cin >> i;
if (i>0){
w = w+i;
}

if (i==0){

    break;
}
}

std::cout << "The sum of the sequence of numbers is: " << w;
}