// This program sorts 4 integers
// Bilal Quamine
// 8/27/2025

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(){

  // inputs the numbers
  cout << "Enter Four numbers: ";
  int x, y, z, w;
  cin >> x >> y >> z >> w;

  int tmp;

  // orders x and y
  if (x > y){
    tmp = x;
    x = y;
    y = tmp;
  }

  // orders y and z
  if (y > z){
    tmp = y;
    y = z;
    z = tmp;
  }

  // orders z and w
  if (z > w){
    tmp = z;
    z = w;
    w = tmp;
  }

  // second pass (to fix ripple effects)
  if (x > y){
    tmp = x;
    x = y;
    y = tmp;
  }

  if (y > z){
    tmp = y;
    y = z;
    z = tmp;
  }

  if (z > w){
    tmp = z;
    z = w;
    w = tmp;
  }

  // final check
  if (x > y){
    tmp = x;
    x = y;
    y = tmp;
  }

  // outputs the sorted numbers
  cout << "The sorted numbers are: ";
  cout << x << " " << y << " " << z << " " << w << endl;
}