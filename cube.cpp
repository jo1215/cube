#include "cube.h"
#include <ctime>
#include <iostream>
#include <random>

Cube::Cube(){}

void Cube::initialize(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            cube[i][j] = i;
        }
    }
    scramble();
    print();
}

void Cube::scramble(){
    std::string moves[18] = {"R", "R'", "R2", "L", "L'", "L2", "U", "U'", "U2", "D", "D'", "D2", "F", "F'", "F2", "B", "B'", "B2"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    outputFile.open("recon.txt", std::ofstream::out | std::ofstream::app);
    outputFile << "Scramble: ";
    outputFile.close();

    for(int i = 0; i < 30; i++){
        float rng = dis(gen) * 1000000;
        int move = static_cast<int>(rng) % 18;
        turn(moves[move]);
        turnCount--;
    }
    outputFile.open("recon.txt", std::ofstream::out | std::ofstream::app);
    outputFile << "\nSolution: \n";
    outputFile.close();
}

void Cube::print(){
    std::cout << std::string(20, '-') << '\n';
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            switch(cube[i][j]){
                case 0:
                    std::cout << "W ";
                    break;
                case 1:
                    std::cout << "G ";
                    break;
                case 2:
                    std::cout << "R ";
                    break;
                case 3:
                    std::cout << "B ";
                    break;
                case 4:
                    std::cout << "O ";
                    break;
                case 5:
                    std::cout << "Y ";
                    break;
            }
        }
        std::cout << "\n";
    }
    std::cout << std::string(20, '-') << '\n';
}

void Cube::writeTurn(std::string m){
    outputFile.open("recon.txt" , std::ofstream::out | std::ofstream::app);
    outputFile << m << " ";
    outputFile.close();
}

void Cube::turn(std::string m){
    if(!(m == "x" || m == "x'" || m == "x2" || m == "y" || m == "y'" || m == "y2" || m == "z" || m == "z'" || m == "z2")){
        turnCount++;
    }
    writeTurn(m);

    if(m == "R"){
        R();
    }
    else if(m == "R'"){
        R();
        R();
        R();
    }
    else if(m == "R2" || m == "R2'"){
        R();
        R();
    }
    else if(m == "L"){
        L();
    }
    else if(m == "L'"){
        L();
        L();
        L();
    }
    else if(m == "L2" || m == "L2'"){
        L();
        L();
    }
    else if(m == "U"){
        U();
    }
    else if(m == "U'"){
        U();
        U();
        U();
    }
    else if(m == "U2" || m == "U2'"){
        U();
        U();
    }
    else if(m == "D"){
        D();
    }
    else if(m == "D'"){
        D();
        D();
        D();
    }
    else if(m == "D2" || m == "D2'"){
        D();
        D();
    }
    else if(m == "F"){
        F();
    }
    else if(m == "F'"){
        F();
        F();
        F();
    }
    else if(m == "F2" || m == "F2'"){
        F();
        F();
    }
    else if(m == "B"){
        B();
    }
    else if(m == "B'"){
        B();
        B();
        B();
    }
    else if(m == "B2" || m == "B2'"){
        B();
        B();
    }
    else if(m == "M"){
        M();
    }
    else if(m == "M'"){
        M();
        M();
        M();
    }
    else if(m == "M2" || m == "M2'"){
        M();
        M();
    }
    else if(m == "E"){
        E();
    }
    else if(m == "E'"){
        E();
        E();
        E();
    }
    else if(m == "E2" || m == "E2'"){
        E();
        E();
    }
    else if(m == "S"){
        S();
    }
    else if(m == "S'"){
        S();
        S();
        S();
    }
    else if(m == "S2" || m == "S2'"){
        S();
        S();
    }
    else if(m == "x"){
        R();
        M();
        M();
        M();
        L();
        L();
        L();
    }
    else if(m == "x'"){
        R();
        R();
        R();
        M();
        L();
    }
    else if(m == "x2"){
        R();
        R();
        M();
        M();
        L();
        L();
    }
    else if(m == "y"){
        U();
        E();
        E();
        E();
        D();
        D();
        D();
    }
    else if(m == "y'"){
        U();
        U();
        U();
        E();
        D();
    }
    else if(m == "y2"){
        U();
        U();
        E();
        E();
        D();
        D();
    }
    else if(m == "z"){
        F();
        S();
        B();
        B();
        B();
    }
    else if(m == "z'"){
        F();
        F();
        F();
        S();
        S();
        S();
        B();
    }
    else if(m == "z2"){
        F();
        F();
        S();
        S();
        B();
        B();
    }
    else if(m == "r"){
        R();
        M();
        M();
        M();
    }
    else if(m == "r'"){
        R();
        R();
        R();
        M();
    }
    else if(m == "r2" || m == "r2'"){
        R();
        R();
        M();
        M();
    }
    else if(m == "l"){
        L();
        M();
    }
    else if(m == "l'"){
        L();
        L();
        L();
        M();
        M();
        M();
    }
    else if(m == "l2" || m == "l2'"){
        L();
        L();
        M();
        M();
    }
    else if(m == "u"){
        U();
        E();
        E();
        E();
    }
    else if(m == "u'"){
        U();
        U();
        U();
        E();
    }
    else if(m == "u2" || m == "u2'"){
        U();
        U();
        E();
        E();
    }
    else if(m == "d"){
        D();
        E();
    }
    else if(m == "d'"){
        D();
        D();
        D();
        E();
        E();
        E();
    }
    else if(m == "d2" || m == "d2'"){
        D();
        D();
        E();
        E();
    }
    else if(m == "f"){
        F();
        S();
    }
    else if(m == "f'"){
        F();
        F();
        F();
        S();
        S();
        S();
    }
    else if(m == "f2" || m == "f2'"){
        F();
        F();
        S();
        S();
    }
}

bool Cube::validMove(std::string m){
    if (m == "U" || m == "D" || m == "L" || m == "R" || m == "F" || m == "B" || m == "u" || m == "d" || m == "l" || m == "r" || m == "f" || m == "b" || m == "U'" || m == "D'" || m == "L'" || m == "R'" || m == "F'" || m == "B'" || m == "u'" || m == "d'" || m == "l'" || m == "r'" || m == "f'" || m == "b'" || m == "U2" || m == "D2" || m == "L2" || m == "R2" || m == "F2" || m == "B2" || m == "u2" || m == "d2" || m == "l2" || m == "r2" || m == "f2" || m == "b2" || m == "U2'" || m == "D2'" || m == "L2'" || m == "R2'" || m == "F2'" || m == "B2'" || m == "u2'" || m == "d2'" || m == "l2'" || m == "r2'" || m == "f2'" || m == "b2'" || m == "x" || m == "x'" || m == "x2" || m == "y" || m == "y'" || m == "y2" || m == "z" || m == "z'" || m == "z2" || m == "M" || m == "M'" || m == "M2" || m == "E" || m == "E'" || m == "E2" || m == "S" || m == "S'" || m == "S2" || m == "exit"){
        return true;
    }
    else{
        return false;
    }
}

bool Cube::checkIfSolved(){
    for(int i = 0; i < 6; i++){
        for(int j = 1; j < 9; j++){
            if(cube[i][j] != cube[i][0]){
                return false;
            }
        }
    }
    std::cout << "Cube solved in " << turnCount << " moves! Scramble and solution avaible in recon.txt.\n";
    return true;
}

void Cube::U(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    for(int i = 0; i < 6; i += 2){
        cube[0][i+2] = temp[0][i];
    }
    cube[0][0] = temp[0][6];
    for(int i = 1; i < 7; i += 2){
        cube[0][i+2] = temp[0][i];
    }
    cube[0][1] = temp[0][7];
    for(int j = 0; j < 3; j++){
        cube[4][j] = temp[1][j];
        for(int i = 1; i < 4; i++){
            cube[i][j] = temp[i+1][j];
        }
    }
}

void Cube::D(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    for(int i = 0; i < 6; i += 2){
        cube[5][i+2] = temp[5][i];
    }
    cube[5][0] = temp[5][6];
    for(int i = 1; i < 7; i += 2){
        cube[5][i+2] = temp[5][i];
    }
    cube[5][1] = temp[5][7];
    for(int j = 6; j > 3; j--){
        cube[1][j] = temp[4][j];
        for(int i = 1; i < 4; i++){
                cube[i+1][j] = temp[i][j];
        }
    }
}

void Cube::R(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    for(int i = 0; i < 6; i += 2){
        cube[2][i+2] = temp[2][i];
    }
    cube[2][0] = temp[2][6];
    for(int i = 1; i < 7; i += 2){
        cube[2][i+2] = temp[2][i];
    }
    cube[2][1] = temp[2][7];
    for(int j = 2; j < 5; j++){
        cube[0][j] = temp[1][j];
        cube[1][j] = temp[5][j];
    }
    cube[3][0] = temp[0][4];
    cube[3][7] = temp[0][3];
    cube[3][6] = temp[0][2];
    cube[5][2] = temp[3][6];
    cube[5][3] = temp[3][7];
    cube[5][4] = temp[3][0];
}

void Cube::L(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    for(int i = 0; i < 6; i += 2){
        cube[4][i+2] = temp[4][i];
    }
    cube[4][0] = temp[4][6];
    for(int i = 1; i < 7; i += 2){
        cube[4][i+2] = temp[4][i];
    }
    cube[4][1] = temp[4][7];

    cube[0][6] = temp[3][2];
    cube[0][7] = temp[3][3];
    cube[0][0] = temp[3][4];
    cube[3][2] = temp[5][6];
    cube[3][3] = temp[5][7];
    cube[3][4] = temp[5][0];
    cube[5][6] = temp[1][6];
    cube[5][7] = temp[1][7];
    cube[5][0] = temp[1][0];
    cube[1][6] = temp[0][6];
    cube[1][7] = temp[0][7];
    cube[1][0] = temp[0][0];
}

void Cube::F(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    for(int i = 0; i < 6; i += 2){
        cube[1][i+2] = temp[1][i];
    }
    cube[1][0] = temp[1][6];
    for(int i = 1; i < 7; i += 2){
        cube[1][i+2] = temp[1][i];
    }
    cube[1][1] = temp[1][7];

    cube[0][4] = temp[4][2];
    cube[0][5] = temp[4][3];
    cube[0][6] = temp[4][4];
    cube[2][6] = temp[0][4];
    cube[2][7] = temp[0][5];
    cube[2][0] = temp[0][6];
    cube[5][0] = temp[2][6];
    cube[5][1] = temp[2][7];
    cube[5][2] = temp[2][0];
    cube[4][2] = temp[5][0];
    cube[4][3] = temp[5][1];
    cube[4][4] = temp[5][2];
}

void Cube::B(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    for(int i = 0; i < 6; i += 2){
        cube[3][i+2] = temp[3][i];
    }
    cube[3][0] = temp[3][6];
    for(int i = 1; i < 7; i += 2){
        cube[3][i+2] = temp[3][i];
    }
    cube[3][1] = temp[3][7];

    cube[0][0] = temp[2][2];
    cube[0][1] = temp[2][3];
    cube[0][2] = temp[2][4];
    cube[4][6] = temp[0][0];
    cube[4][7] = temp[0][1];
    cube[4][0] = temp[0][2];
    cube[5][4] = temp[4][6];
    cube[5][5] = temp[4][7];
    cube[5][6] = temp[4][0];
    cube[2][2] = temp[5][4];
    cube[2][3] = temp[5][5];
    cube[2][4] = temp[5][6];
}

void Cube::M(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    cube[0][1] = temp[3][5];
    cube[0][8] = temp[3][8];
    cube[0][5] = temp[3][1];
    cube[1][1] = temp[0][1];
    cube[1][8] = temp[0][8];
    cube[1][5] = temp[0][5];
    cube[5][1] = temp[1][1];
    cube[5][8] = temp[1][8];
    cube[5][5] = temp[1][5];
    cube[3][1] = temp[5][5];
    cube[3][8] = temp[5][8];
    cube[3][5] = temp[5][1];
}

void Cube::E(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    for(int i = 1; i < 4; i++){
        cube[i+1][7] = temp[i][7];
        cube[i+1][8] = temp[i][8];
        cube[i+1][3] = temp[i][3];
    }
    cube[1][7] = temp[4][7];
    cube[1][8] = temp[4][8];
    cube[1][3] = temp[4][3];
}

void Cube::S(){
    int temp[6][9];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            temp[i][j] = cube[i][j];
        }
    }
    cube[0][7] = temp[4][5];
    cube[0][8] = temp[4][8];
    cube[0][3] = temp[4][1];
    cube[2][1] = temp[0][7];
    cube[2][8] = temp[0][8];
    cube[2][5] = temp[0][3];
    cube[5][7] = temp[2][5];
    cube[5][8] = temp[2][8];
    cube[5][3] = temp[2][1];
    cube[4][1] = temp[5][7];
    cube[4][8] = temp[5][8];
    cube[4][5] = temp[5][3];
}