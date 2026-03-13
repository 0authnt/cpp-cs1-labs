#include <iostream>
#include "ListVectors.hpp"

// prints the values in vector "vec"
void output(std::vector<char> &vec){
    //iterates through vector and prints each character followed by a space
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }

}

// Find and return the index of the letter or -1 if not found
int check(std::vector<char> &vec, char letter){
    //Iterate through the vector
    //If a match is found
    //Return position
    //After all letters are checked, with no match
    //Return -1
    for(auto it = vec.begin(); it < vec.end(); it++){
        if(*it == letter){ //deref iterator & follow for value
            return it - vec.begin();
        }
    }
    return -1;
}

//Adds a letter to the vector if it is not a duplicate
void addNumber(std::vector<char> &vec, char letter){
    //Use check to find the position of the letter
    //if its not found add it to the end
    //if not found, exit function
    if(check(vec,letter) == -1){
        vec.push_back(letter);
    }
    return;
}

//Removes a letter from the vector if it is present
void removeNumber(std::vector<char> &vec, char letter){
    //Use check to find position of letter
    //If it is found, remove
    //If not, exit function
    int index = check(vec,letter); //storing result
    if(index != -1){
        vec.erase(vec.begin() + index);
    }
    return;
}