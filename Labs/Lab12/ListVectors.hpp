#include <iostream>
#include <vector>

#ifndef LISTVECTORS_HPP
#define LISTVECTORS_HPP

// prints the values in vector "vec" of "size" 
void output(std::vector<char> &vec);

// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(std::vector<char> &vec, char letter);

// adds "number" to the array pointed to by "colPtr" of "size". 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased. 
void addNumber(std::vector<char> &vec, char letter);

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(std::vector<char> &vec, char letter);

#endif // LIST_HPP