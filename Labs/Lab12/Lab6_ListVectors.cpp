#include <iostream>
#include <vector>
#include "ListVectors.hpp"
using namespace std;

int main(){
   char op = '?';
   char num;
    vector<char> tomato;
   while(op != 'q'){
      cout << "enter operation [a/r/q] and character: ";
      cin >> op;
      if(op == 'q'){
         break;
      }
      cin >> num;
      if(check(tomato,num) != -1){
         cout << "number is present in the array" << endl;
      }
      if(op == 'a'){
         addNumber(tomato,num);
      }
      if(op == 'r'){
         removeNumber(tomato,num);
      }
      cout << "The list is now ";
      output(tomato);
      cout << endl;
   }
   cout << "The final list is ";
   output(tomato);
}
