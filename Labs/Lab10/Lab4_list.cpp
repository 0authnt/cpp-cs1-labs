#include <iostream>
using namespace std;

int main() {
    double* list = nullptr;   // pointer to dynamic array
    int size = 0;             // how many numbers are in the list
    char op;                  // operation: a = add, r = remove, q = quit
    double num;               // number input by user

    while (true) {
        cout << "enter operation [a/r/q] and number: ";
        cin >> op;

        // quit if q
        if (op == 'q')
            break;

        // for add/remove, read the number
        cin >> num;

        if (op == 'a') {
            // check for duplicate
            bool found = false;
            for (int i = 0; i < size; i++) {
                if (list[i] == num) {
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << "duplicate!" << endl;
            } else {
                // make new array with one extra slot
                double* newList = new double[size + 1];
                for (int i = 0; i < size; i++)
                    newList[i] = list[i];
                newList[size] = num;
                delete[] list;
                list = newList;
                size++;
            }
        }
        else if (op == 'r') {
            // check if number exists
            int index = -1;
            for (int i = 0; i < size; i++) {
                if (list[i] == num) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                cout << "not present!" << endl;
            } else {
                // make new array with one fewer slot
                double* newList = new double[size - 1];
                for (int i = 0, j = 0; i < size; i++) {
                    if (i != index)
                        newList[j++] = list[i];
                }
                delete[] list;
                list = newList;
                size--;
            }
        }

        // print current list
        cout << "your numbers:";
        for (int i = 0; i < size; i++)
            cout << " " << list[i];
        cout << endl;
    }

    delete[] list;
    return 0;
}
