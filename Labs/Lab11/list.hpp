// List of doubles class
// Mikhail Nesterenko
// 11/09/2020


#ifndef LIST_HPP_
#define LIST_HPP_

class List{
public:
  List(): size_(0), list_(nullptr) {}; // void constructor
  int size() const {return size_;} // returns the size of the array

  int check(double); // returns index of element containg "number" or -1 if none
  void addNumber(double);    // adds number to the List
  void removeNumber(double); // deletes the number from the List
  void output();      // prints the values of the List

  // big three
  List(const List&); // copy constructor
  List& operator=(const List&); // overloaded assignment
  ~List(); // destructor

private:
  double *list_; // pointer to the dynamically allocated array holding List of doubles
  int size_;   // array size
};

#endif /* COLLECTION_HPP_ */

//note to make definition file




