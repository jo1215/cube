#include <string>
#include <fstream>
#include <vector>

class Cube{
    private:
        int cube[6][9];
        int turnCount, solveNum;
        std::string validMoves[67];
        std::vector<std::string> turns;
        std::ofstream outputFile;
    public:
        Cube();
        void initialize();
        void print();
        void scramble();
        void writeTurn(std::string);
        void turn(std::string);
        bool validMove(std::string);
        bool checkIfSolved();
        void nextLine();
        void addTurn(std::string);
        void solveTurn();
        void makeRecon();
        void R();
        void L();
        void U();
        void D();
        void F();
        void B();
        void M();
        void E();
        void S();
};