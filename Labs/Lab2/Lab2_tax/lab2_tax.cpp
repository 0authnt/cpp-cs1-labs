#include <iostream>

int main() {
// declared variables to store employee code and determine rate of withholding
char emp_c; //char instead of string to use switch case
double tmp; // tmp counter variable
double wth; // withholding counter
    std::cout << "Input Employee Code: ";
    std::cin >> emp_c;
    std::cout << "Input Employee Earning: ";
    std::cin >> tmp;


switch (emp_c) {
    case 'd':
    wth = tmp * .15; // stores amount to withold
    std::cout << "Employee Earnings: " << tmp << " Employee Code: " << emp_c << " Amount to Withhold: " << wth 
    << " Take Home: " << tmp - wth;
    break;
    case 'f':
    wth = tmp * .20;
    std::cout << "Employee Earnings: " << tmp << " Employee Code: " << emp_c << " Amount to Withhold: " << wth
    << " Take Home: " << tmp - wth;
    break;
    case 'h':
    wth = tmp * .60;
    std::cout << "Employee Earnings: " << tmp << " Employee Code: " << emp_c << " Amount to Withhold: " << wth
    << " Take Home: " << tmp - wth;
    break;
    case 'o':
    wth = tmp * .65;
    std::cout << "Employee Earnings: " << tmp << " Employee Code: " << emp_c << " Amount to Withhold: " << wth
    << " Take Home: " << tmp - wth;
    break;
    default: // Default to output unknown employee code
    std::cout << "Employee Earnings: " << tmp << " Employee Code: " << emp_c << " Unknown Employee Code: " << emp_c;

}


}
