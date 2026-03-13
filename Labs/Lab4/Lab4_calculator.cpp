#include <iostream>
#include <cstdlib>
#include <cmath>
using std::cout; using std::endl; using std::cin;
int main(){
cout << "1.) Absolute Value" << endl;
cout << "2.) Square Root" << endl;
cout << "3.) Floor" << endl;
cout << "4.) Power" << endl;

while(true){
int tmp;
cout << "Select an operation (1, 2, 3..)" << endl;
cin >> tmp;
double base;
double exp;


switch(tmp){
    case 1:
    cout << "Enter base" << endl;
    cin >> base;
    cout << "Absolute Value: " << abs(base) << endl;
    break;
    case 2:
    cout << "Enter base" << endl;
    cin >> base;
    cout << "Base: " << sqrt(base) << endl;
    break;
    case 3:
    cout << "Enter base" << endl;
    cin >> base;
    cout << "Floor: " << floor(base) << endl;
    break;
    case 4:
    cout << "Enter base" << endl;
    cin >> base;

    cout << "Enter exponent" << endl;
    cin >> exp;
    cout << "Power: " << pow(base, exp) << endl;
    break;

    default:
    cout << "Error ";

    return 0;

}

}

}