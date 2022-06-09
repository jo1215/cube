#include <string>
#include <fstream>

class Cube{
    private:
        int cube[6][9];
        int turnCount = 0;
    public:
        std::ofstream outputFile;
        Cube();
        void initialize();
        void print();
        void scramble();
        void writeTurn(std::string);
        void turn(std::string);
        bool validMove(std::string);
        bool checkIfSolved();
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