// testing the implementation of class list
// Mikhail Nesterenko
// 11/16/2020

#include <iostream>
#include "list.hpp"

using std::cout; using std::endl;


void testfunc(List); // function to test pass-by-value for list

int main(){

   List c1;

   // testing regular member functions
   c1.addNumber(1.);
   c1.addNumber(2.);
   c1.addNumber(3.);
   c1.addNumber(3.); // trying to add duplicate, should not add it
   
   cout << "c1 size is after number addition is: " << c1.size() << endl;

   if(c1.check(1.) != -1) // check() returns -1 if number not present
      cout << "1 is present in the array" << endl;

   if(c1.check(5.) != -1)
      cout << "5 is present in the array" << endl;

   cout << "c1 before removal of 2.0: "; c1.output();
   c1.removeNumber(2.);
   cout << "c1 after removal of 2.0: "; c1.output();

   //copy constructor runs here
   List copiedList = List(c1);
   //List copiedList(c1);
   //List copiedList = c1;

   testfunc(c1); // testing copy constructor
   
   cout << "c1 after testfunc call: ";
   c1.output(); // if destructor is implemented correctly
                // this should print properly after testfunc completes

   List c2, c3;

   c3=c2=c1; // testing stackability of the overloaded assignment
   cout << "c3 after stackable assingment: ";
   c3.output();

   c3=c3; // testing protection against self-assingment
   cout << "c3 after self-assignment: ";
   c3.output();

   //free c1.array_
   //free c2.array_
   //free c3.array_
}

//use c3

// tests pass-by-value for object of class list
void testfunc(List c){ // copy constructor is invoked on "c"
   c.removeNumber(5.5);
    cout << "parameter c: "; 
    c.output(); 
} // destructor is invoked when "c" goes out of scope