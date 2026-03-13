#include <iostream>
#include "maze.hpp"
#include <cstdlib>

void clearWalls(RoomPair rmp[]){
    for(int i=0; i<numWalls; i++){
        rmp[i].one.x = rmp[i].two.x = -1;
        rmp[i].one.y = rmp[i].two.y = '*';
        rmp[i].two.x = -1;
        rmp[i].two.y = '*';
    }

}

bool goodDirection(const Room &rm, const char dr){
    if(dr=='l' && rm.x-1 >=1){
        return true;
    }
    else if(dr=='r' && rm.x+1<= mazeSize){
        return true;
    }
    else if (dr=='u' && rm.y-1 >= 'a'){
        return true;
    }
    else if (dr =='d' && rm.y+1 <= 'a' + mazeSize - 1){
        return true;
    }
    else{
        return false;
    }

}


Room createAdjacent(const Room &rm, const char dr){
Room nextRoom = rm;
if (dr == 'r'){
nextRoom.x++;
}
else if (dr == 'l'){
nextRoom.x--;
}
else if (dr == 'u'){
nextRoom.y--;
}
else if (dr == 'd'){
nextRoom.y++;
}
return nextRoom;
}


const Room pickAdjacent(const Room &rm){
char validDirs[4]; // Stores only valid directions
int count = 0; //Counts valid directions
char directions[4] = {'u', 'd', 'l', 'r'}; //array of possible directions
// Test each direction
for (int i = 0; i < 4; i++){
char dr = directions[i]; //Find current direction, store in dr
if (goodDirection(rm,dr) == true){ 
    validDirs[count] = directions[i];
    count++;
}
}
int randomIndex = rand() % count; //random index between 0 and count - 1
char randomDir = validDirs[randomIndex]; //Random Valid direction
return createAdjacent(rm, randomDir);

}


// selects a random wall, uses pickAdjacent()
const RoomPair pickPair(){
Room one;
int randomx = rand() % mazeSize +1; // random column
char randomy = 'a' + (rand()%mazeSize); //random row
one.x = randomx;
one.y = randomy;
Room two = pickAdjacent(one); //pick the adjacent wall
RoomPair wall = {one, two}; //forms pair
return wall;
}

//predicate returns true if coordinates of rooms match
//Already evaluates to boolean, just return bool directly
bool matchRoom(const Room &r1, const Room &r2){
    return (r1.x == r2.x && r1.y == r2.y);
}

// returns true if two pairs of adjacent rooms are the same, 
// returns false otherwise, uses matchRoom()
// note that r1|r2 matches r2|r1
bool matchPair(const RoomPair &r1, const RoomPair& r2){
    bool sameOrder;
    bool revOrder;
    sameOrder = matchRoom(r1.one, r2.one) && matchRoom(r1.two, r2.two);
    revOrder = matchRoom(r1.one, r2.two) && matchRoom(r1.two, r2.one);

 return (sameOrder || revOrder);
}
// returns true if rp matches one of the wall in the array
// false otherwise
// uses matchPair()
//walls holds the room pair array, generating a {a1, a2}
// by matching the roompair array to the room pair, we can
// evaluate if rp matches one of the walls in the array
bool checkMaze(const RoomPair walls[], const RoomPair &rp){
for (int i = 0; i < numWalls; i++){
if (matchPair(walls[i], rp)) 
return true;
}
return false; // "false otherwise"
}

// places internal walls in random locations of the maze
//Fill walls array with numWalls randomly placed adjacent-room pairs

void build(RoomPair walls[]){
clearWalls(walls); //init array to sentinel values
for (int i = 0; i < numWalls; i++){
RoomPair candidate = pickPair(); //Add call inside the loop, copy wall to every slot
walls[i] = candidate; // storing walls in candidate
}
}

//
// display functions
//
void printRoom(const Room &rm){ // prints the location of the room
std::cout << rm.y << rm.x;
} 
void printPair(const RoomPair &rp){ // prints the locations of the adjacent rooms
printRoom(rp.one);
std::cout << " | ";
printRoom(rp.two);
} 
void printMaze(const RoomPair walls[]){
    for (int i = 0; i < numWalls; i++){
        printPair(walls[i]);
        std::cout << " ";


    }
}
// prints the locations of all the internal 
//walls of the maze
// uses printPair

// game functions
//

// asks the user for the direction and generates the next room
// to move to
// uses goodDirection() to valid (does not go outside external walls) and
//      createAdjacent() to generate the room for the next move
// returns {-1,*} if the user wants to quit
const Room nextMove(const Room& currentRoom){
char dir;
//prompt
std::cout << "Move (u/d/l/r/q): ";
std::cin >> dir;

//quit path
if (dir == 'q') return Room{ -1, '*'};

// loop until the move stays inside external bounds
while (!(dir == 'u' || dir == 'd' || dir == 'l' || dir == 'r') || !goodDirection(currentRoom, dir)){
std::cout << "Wall\nmove (u/d/l/r/q): ";
std::cin >> dir;
if (dir == 'q') return Room{-1, '*'};
}
return createAdjacent(currentRoom, dir);
}

// note that checkMaze() is also used in the game
