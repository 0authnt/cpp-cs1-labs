//Implementation file
#include <iostream>
#include "list.hpp"
using namespace std;

int main(){
   char op = '?';
   double num;
   List tomato;
   while(op != 'q'){
      cout << "Enter Operation [a/r/q]: ";
      cin >> op;
      if(op == 'q'){
         break;
      }
      cout << "and a number: ";
      cin >> num;
      if(tomato.check(num) != -1){
         cout << "number is present in the array" << endl;
      }
      if(op == 'a'){
         tomato.addNumber(num);
      }
      if(op == 'r'){
         tomato.removeNumber(num);
      }
      cout << "The list is now ";
      tomato.output();
   }
   cout << "The final list is ";
   tomato.output();
}
