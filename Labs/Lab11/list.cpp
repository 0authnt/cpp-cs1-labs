// returns index of element containg "number" or -1 if none
#include <iostream>
#include "list.hpp"


int List::check(double number){
    for(int i = 0; i < size_; i++){
        //if the number is in the current position return position
        if(number == list_[i]){
            return i;
        }
    }
    return -1;
} 
// adds number to the List
void List::addNumber(double number){
    //check if the number is already there, if so then return
    if(check(number) != -1){
        return;
    }
    //otherwise add number to list
   //make a temporary array of size+1
    double *tmp = new double[size_+1];
   //copy everything from old array to new one
    for(int i = 0; i < size_; i++){
        tmp[i] = list_[i];
    }
   //add new number to end of the array
    tmp[size_] = number;
    size_++;
   //delete the old array
   if(list_ != nullptr){
    delete[] list_;
   }
   //replace the old array pointer with a new one
    list_ = tmp;

}
//deletes the number from the List
// shrinks the array

void List::removeNumber(double number){
    int index = check(number);
    if(index == -1){
        return;
    }
    if(size_ == 1){
        delete[] list_;
        list_ = nullptr;
        size_ = 0;
        return;
    }
    double *tmp = new double[size_-1]; //made an array of list size - 1
    for(int i = 0; i < index; i++){
        tmp[i] = list_[i]; //copy elements before the one being deleted
    }
    for(int i = index+1; i < size_; i++){
        tmp[i-1] = list_[i]; //copy elements after the one being deleted
    }

    delete[] list_; //delete old memory

    list_ = tmp; // updating list pointer to point at the new array
    size_--; //updating size
}

// prints the values of the List
void List::output(){
    std::cout << "[";
    for(int i = 0; i < size_; i++){
        std::cout << list_[i] << " ";
}
    std::cout << "]";
}

//Big Three

List::List(const List& other){ // copy constructor
    this->size_ = other.size_;
    if(size_ > 0){
        this->list_ = new double[size_];
        for(int i = 0; i < size_; i++){
            this->list_[i] = other.list_[i];
        }
    } else{
        this->list_ = nullptr;
    }

} 
List& List::operator=(const List& other){  // overloaded assignment
    if(&other == this){
        return *this;
    }
    if(list_ != nullptr){
        delete[] list_;
    }
    this->size_ = other.size_;
    if(size_ > 0){
        this->list_ = new double[size_];
        for(int i = 0; i < size_; i++){
            this->list_[i] = other.list_[i];
        }
    } else{
    this->list_ = nullptr;
    }
    return *this;
}
List::~List(){ // destructor
    if(list_ != nullptr){
        delete[] list_;
        list_ = nullptr; //helps avoid double deletion
    }

} 