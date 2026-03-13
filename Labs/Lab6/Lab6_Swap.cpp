#include <iostream>
using std::cin; using std::cout; using std::endl;

void swap(int& left, int& right) {
    int tmp = left;
    left = right;
    right = tmp;
}

int main() {
    cout << "Enter three numbers: ";
    int x, y, z;
    cin >> x >> y >> z;

    // orders x and y
    if (x > y) {
        swap(x, z); // FIX HERE: should swap(x, y)
    }

    // orders y and z
    if (y < z) {    // FIX HERE: should be (y > z)
        swap(y, z);
    }

    // re-check x and y after swapping y and z
    if (x < y) {    // FIX HERE: should be (x > y)
        swap(x, y);
    }

    cout << "The sorted numbers are: "
         << x << " " << y << " " << z << endl;
}