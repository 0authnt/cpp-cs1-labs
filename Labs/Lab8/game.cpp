#include "maze.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//Include directives as needed for i/o and seeding

int main(){
char show;
srand(1); //seeding to move
RoomPair walls[numWalls]; //Declare wall Array
build(walls); // Build maze walls
Room current = startRoom;

//Create Game Loop
while (true){
std::cout << "You are Here: ";
printRoom(current); //Current Position
std::cout << std::endl;
Room proposed = nextMove(current); // pass start room into nextMove function
if (proposed.x == -1 && proposed.y == '*') break;
//edge between current and proposed
RoomPair attempt;
attempt.one = current;
attempt.two = proposed;

//wall check
    if (checkMaze(walls, attempt)){

    std::cout << "wall" << std::endl;
    continue;
    }
//move succeeds
current = proposed;
// win condition

    if (matchRoom(current, cheeseRoom)) {
    std::cout << "cheese!" << std::endl;
    break;
    }
}
return 0;
}
