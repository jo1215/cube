#include <iostream>
#include "cube.h"

int main(){
    Cube cube;
    std::string newTurn, repeat;
    cube.makeRecon();
    
    std::cout << "Enter moves separated by spaces, use uppercase for layer moves and lowercase for wide moves. Slice moves and cube rotations are supported.\n";
    std::cout << "After entering a string of moves, enter any non-move text to apply the moves to the cube.\n";
    std::cout << "Scrambles and solutions are viewable in recon.txt.\n";
    std::cout << "Enter 'exit' at any time to exit the program.\n";

    do{
        cube.initialize();
        while(!cube.checkIfSolved()){
            std::cout << "Enter moves: \n";

            while((std::cin >> newTurn) && cube.validMove(newTurn)){
                if(newTurn == "exit"){
                    return 0;
                }
                cube.addTurn(newTurn);
            };

            cube.solveTurn();
            cube.print();
            cube.nextLine();
        }
        std::cout << "Enter \'n\' to get a new scramble or enter any other text to exit the program: ";
        std::cin >> repeat;
    }
    while(repeat == "n" || repeat == "N");

    return 0;
}