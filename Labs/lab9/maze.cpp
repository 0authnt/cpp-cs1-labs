#include <iostream>
#include "maze.hpp"


// selects a random room within the maze
 void Room::pick(){

    x_ = (rand() % 4) + 1;
    y_ = (rand() % 4) + 'a';
    
 }; 
// selects a random adjacent room
// uses goodDirection() and createAdjacent()
const Room Room::pickAdjacent(){
    //pick a dir at random
    //Check if direction is good
    //if it is use create adjacent
    //otherwise repeat until we find a good direction
    while(true){
        char dirs[] = {'u','d','l','r'}; //Creates directions
        int dir = (rand() % 4); // Index of direction, represents random selection by comparison
        if (goodDirection(dirs[dir])){
            return createAdjacent(dirs[dir]);
        }
    }
}; 

// asks the user for the room to move adjacent to this room
// returns {-1,*} if the user wants to quit
// uses goodDirection() and createAdjacent()
const Room Room::nextMove() const{
    char move;
    std::cout << "Next Move? (u/d/r/l)" << std::endl;
    std::cin >> move;
    //see if the move is right
    if(goodDirection(move)){
        return createAdjacent(move); // if the move is right create adjacent
    }
    if(move == 'q'){
        Room tmp;
        tmp.x_ = -1;
        tmp.y_ = '*';
        return tmp;
    }
    return *this; 
}

// prints room coordinates in format "a1"
void Room::print() const{
    std::cout << y_ << x_;

};   

// predicate returns true if the coordinates of the two rooms match
bool matchRoom(const Room& rom1, const Room& rom2){
    if (rom1.x_ == rom2.x_)
    {
     if (rom1.y_ == rom2.y_){
        return true;
     };
    };
    return false;

};

    // checks if this direction keeps the mouse inside the maze
bool Room::goodDirection(const char dir) const{
    if(dir == 'u' && y_ == 'a'){
        return false;
    }
    if(dir == 'l' && x_ == 1){
        return false;
    }
    if(dir == 'd' && y_ == ('a' + mazeSize_ - 1)){
        return false;
    }
    if(dir == 'r' && x_ == mazeSize_){
        return false;
    }
    return true;
    /*
    if(dir == 'q'){
    std::cout << "User has Decided to quit";
    break;
    }
    */
};

// returns the room adjacent to this room in the specified direction
// assumes the direction is inside the maze
const Room Room::createAdjacent(const char dir) const{
    Room result;
    result.x_ = x_;
    result.y_ = y_;
    if(dir == 'u'){
        result.y_ -= 1;
    }
    if(dir == 'l'){
        result.x_ -= 1;
    }
    if(dir == 'd'){
        result.y_ += 1;
    }
    if(dir == 'r'){
        result.x_ += 1;
    }
    return result;
};

//RoomPair Functions
//selects a random wall, uses Room::pickAdjacent()
void RoomPair::pick(){
    // RoomPair one;
    // Room tmp; // create room
    // tmp.pick(); //randomizes room
    one_.pick();
    two_ = one_.pickAdjacent();

}; 
// prints the locations of the two rooms in format a1|b1
// uses Room::print()
void RoomPair::print() const {
    
    one_.print();
    std::cout << "|";
    two_.print();

}; 

// returns true if two pairs of adjacent rooms are the same,
// returns false otherwise, uses matchRoom() note that r1|r2 matches r2|r1
bool matchPair(const RoomPair& rp1, const RoomPair& rp2){

    if(matchRoom(rp1.one_,rp2.one_)){
        if(matchRoom(rp1.two_,rp2.two_)){
            return true;
        }
    }
    if(matchRoom(rp1.one_,rp2.two_)){
        if(matchRoom(rp1.two_,rp2.one_)){
            return true;
        }
    }
    return false;
};


// Maze Functions
// prints the locations of all the internal walls of the maze
// and current mouse location
void Maze::print() const{
    for(int i = 0; i < numWalls_; i++){
        walls_[i].print();
        std::cout << " ";
    }
    std::cout << " \n Mouse Room: ";
    currentRoom_.print();
    std::cout << "\n";
}; 


// places internal walls in random locations of the maze
// all walls are different
void Maze::build() {
    int i = 0;
    while(i<numWalls_){
        walls_[i].pick();
        if(checkMaze(walls_[i])==false){
            i++;
        }
    }
}; 

// takes the room to move the mouse to
// moves the mouse there and returns true if no walls (move is possible)
// does not move the mouse and returns false if wall
bool Maze::move(const Room& rm){
    // check if any walls are between the current room and rm
    // if not move the mouse to rm and return true
    // otherwise return false without moving
    RoomPair rp1(currentRoom_,rm);
    if(checkMaze(rp1)){
        return false;
    }
    else{
        currentRoom_ = rm;
        return true;
    }

};
 // returns true if RoomPair matches one of the walls in the maze
bool Maze::checkMaze(const RoomPair& rp1) const{
    for(int i = 0; i < numWalls_; i++){
        if(matchPair(rp1,walls_[i])){
            return true;
        }
    }
    return false;
}