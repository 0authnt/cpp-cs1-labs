#include <iostream>
using namespace std;
//compute BMR for men
double bmrMen(double weight, int whyinches, int age); // bmr has a fractional part, declaring the function here as a double
//compute BMR for women
double bmrWomen(double weight, int whyinches, int age);


int main(){
double weight;
char gender;
int heightft, heightin, ft2in, whyinches;
int age;
const int cals = 150;
int numcook;


cout << "Enter Gender (M/F): ";
cin >> gender;
if (gender == 'm' || gender =='M'){
    cout << "Enter weight [lbs]: ";
    cin >> weight;
    cout << "How many feet tall are you?: ";
    cin >> heightft; // apply an operation to heightft to reflect one foot 12 inches
    cout << "How many inches?: ";
    cin >> heightin;
    ft2in = heightft * 12;
    whyinches = ft2in + heightin; // contains the summation of height
    cout << "Enter age: ";
    cin >> age;
    // User has entered weight, height, gender, age. Now perform bmr calculations
    double result = bmrMen(weight, whyinches, age);
    numcook = result / cals;
    cout << "Your BMR is: " << result << endl;
    cout << "Consumable cookies is: " << numcook << endl;
}

else if (gender == 'f' || gender == 'F'){
cout << "Enter weight [lbs]: ";
    cin >> weight;
    cout << "How many feet tall are you?: ";
    cin >> heightft; // apply an operation to heightft to reflect one foot 12 inches
    cout << "How many inches?: ";
    cin >> heightin;
    ft2in = heightft * 12;
    whyinches = ft2in + heightin; // contains the summation of height
    cout << "Enter age: ";
    cin >> age;
    // User has entered weight, height, gender, age. Now perform bmr calculations
    double result = bmrWomen(weight, whyinches, age);
    numcook = result / cals;
    cout << "Your BMR is: " << result << endl;
    cout << "Consumable cookies is: " << numcook << endl;

}

else{

    cout << "Incorrect input, program will end now.";
    return 0;
}



}
//function bmrMen to calculate bmr for men
double bmrMen(double weight, int whyinches, int age){ // may want to add cookie in here
    //for men: 66 + (6.3 x weight in pounds) + (12.9 x height in inches) - (6.8 x age in years)
    const int var0 = 66; // we 0 index over here partner.
    const double var1 = 6.3;
    const double var2 = 12.9;
    const double var3 = 6.8;
    double bmr;
    bmr = (var0 + (var1 * weight) + (var2 * whyinches) - (var3 * age));
    return bmr;
}

//function bmrWomen to calculate bmr for women
double bmrWomen(double weight, int whyinches, int age){ // may want to add cookie in here
//for women: 655 + (4.3 x weight in pounds) + (4.7 x height in inches) - (4.7 x age in years)
    const int var0 = 655; // as previously stated
    const double var1 = 4.3;
    const double var2 = 4.7;
    const double var3 = 4.7;
    double bmr;
    bmr = (var0 + (var1 * weight) + (var2 * whyinches) - (var3 * age));
    return bmr;
}
