#include <iostream>
using namespace std;
int main() {
    double earning;
    char employeeclass;
    cout << "employee earnings: ";
    cin >> earning;
    cout << "employee code: ";
    cin >> employeeclass;

    switch(employeeclass){


        case('d'):
        cout << "amount to withold: " << earning*15/100 << "\nTake Home:" << earning*85/100;
        break;

        case('h'):
        cout <<"Amount to withhold:" << earning*20/100 << "\nTake Home:" << 


    }




}