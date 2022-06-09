#include <iostream>
#include <vector>
#include "cube.h"

int main(){
    Cube cube;
    std::vector<std::string> turns;
    std::string newTurn, repeat;
    cube.outputFile.open("recon.txt");
    cube.outputFile.close();
    
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
                turns.push_back(newTurn);
            };

            for(std::string t : turns){
                cube.turn(t);
            }
            cube.print();
            turns.clear();
            cube.outputFile.open("recon.txt" , std::ofstream::out | std::ofstream::app);
            cube.outputFile << '\n';
            cube.outputFile.close();
        }
        std::cout << "Enter \'n\' for a new scramble or anything else to quit: ";
        std::cin >> repeat;
    }
    while(repeat == "n" || repeat == "N");

    return 0;
}