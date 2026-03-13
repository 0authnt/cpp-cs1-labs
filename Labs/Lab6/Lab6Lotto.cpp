#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void assign(int chosen[], int size);
bool check(int num, int chosen[], int size);
void draw(int chosen[], int size);
int entry();
void printOut(int chosen[], int size);
int main()
{
const int size = 10;
int chosen[size];
srand(time(0)); //seed the random number generator
assign(chosen, size);
draw(chosen, size);
for (int tries = 0; tries < 5; tries++){
    int guess = entry();
    if (check(guess, chosen, size)){
        cout << "You guessed right!" << endl;
    printOut(chosen,size);
    return 0;
    }
}

cout << "Sorry, you didn't guess any of the numbers." << endl;
printOut(chosen,size);
return 0;

}

void assign(int chosen[], int size){
for (int i = 0; i < size; i++)
chosen[i] = -1;
}

bool check(int num, int chosen[], int size){
for (int i = 0; i < size; i++){
    if (chosen[i] == num)
        return true;
}
return false; // bc we bool we must return something
}

void draw(int chosen[], int size){
int count = 0;
while (count < size){
   int rnum = rand() % 100;
    if (!check(rnum, chosen, size)){
        chosen[count] = rnum;
        count++;
    }
}
}

int entry(){
int sign;
cout << "Enter a number between 0 and 99: ";
cin >> sign;
return sign;
}

void printOut(int chosen[], int size){
cout << "Lottery numbers were: ";
for (int i = 0; i < size; i++) {
cout << chosen[i] << " ";
}
cout << endl;
}
