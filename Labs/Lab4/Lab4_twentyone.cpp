#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout; using std::cin; using std::endl;
int main(){
srand(time(nullptr)); // initializes seed before any rand calls
int player = 1 + rand() % 13; // random in [1, 13]
int comp = 1 + rand() % 21; // random in [1, 21] , dealer
cout << "Welcome to B's Blackjack!" << endl;
cout << "Your current value is: " << player << endl;

char answr; // stores player answer
while(true) {
    cout << "Would you like to hit or stand? [h/s] ";
    cin >> answr;
    bool yes =(answr =='h' || answr == 'H'); // store boolean expression in bool to determine what var will equal
    bool no =(answr =='s' || answr == 'S'); // store boolean expression in bool to determine what var will equal
if (yes) {
    cout << "Player has decided to hit" << endl;
    int draw = 1 + rand() % 13;
    player += draw;
    cout << "You drew: " << draw << '\n' << "New Total: " << player << endl;
if (player > 21){
    cout << "Bust! You lose.\n";
    break;
}
} else if (no) {
    cout << "Standing on: " << player << ".\n";
    cout << "Dealers hand: " << comp << ".\n";

    int playerDiff = 21 - player; // accounts for current player score
    int compDiff = 21 - comp; // accounts for current dealer score

    if (playerDiff < compDiff) {
        cout << "You win! \n";
    } else if (playerDiff == compDiff) {
        cout << "Tie goes to the dealer - you lose.\n";
    } else {
        cout << "Dealer wins.\n";
    }
    break;
} else {
    cout << "Please type y or n.\n";
}
}
return 0;
}