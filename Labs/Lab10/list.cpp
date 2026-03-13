#include "list.hpp"
#include <iostream>

using namespace std;


// prints the values in array "colPtr" of "size" 
void output(double *colPtr, int size){
    // for each value in the array,
    for (int i = 0; i < size; i++){
        //print the value and a space.
        cout << colPtr[i] << " ";
    }
    //after the loop is finished print and endl;
    cout << endl;
}

// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(double *colPtr, double number, int size){
    for (int i = 0; i < size; i++){ //iterates through array
        if (number == colPtr[i]){ //check if number is in array
            return i;

        }
    }
    return -1;
}

// adds "number" to the array pointed to by "colPtr" of "size". 
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased. 
void addNumber(double *& colPtr, double number, int &size){
    int index = check(colPtr, number, size);
    if(index == -1){
        //create a new array of size + 1
        double* arr = new double[size + 1];
        //copy everything from the old array to the new array
        for(int i = 0; i < size; i++){
            arr[i] = colPtr[i]; // take what is at colPtr position i, and add a copy at arr position i
        }
        //delete old array first
        delete[] colPtr;
        //replace old array address with new array address
        colPtr = arr;
        //put the new number at the end
        colPtr[size] = number;
        //increase the size
        size++;
    }
}

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double *& colPtr, double number, int &size){
    //check if number exists
    int index = check(colPtr, number, size);
    //If number exists then do the following
    if(index > -1){
        //first make a new array of size - 1
        double* arr;
        arr = new double[size - 1];
        //loop from 0 to the found index
        for(int i = 0; i < index; i++){
            //copy from the old array to the new array, same index
            arr[i] = colPtr[i];
        }
        //loop from the found index +1 to size
        for(int i = index + 1; i < size; i++){
            //copy from old array to new array - 1 index
            arr[i - 1] = colPtr[i];
        }
        //Delete the old array
        delete[] colPtr;
        //Replace old array address with new array address
        colPtr = arr;
        // size--
        size--;
    }


}