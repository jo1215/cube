#include <string>
#include <fstream>

class Cube{
    private:
        int cube[6][9];
        int turnCount = 0;
        std::string validMoves[67] = {"U","D","L","R","F","B","u","d","l","r","f","b","U'","D'","L'","R'","F'","B'","u'","d'","l'","r'","f'","b'","U2","D2","L2","R2","F2","B2","u2","d2","l2","r2","f2","b2","U2'","D2'","L2'","R2'","F2'","B2'","u2'","d2'","l2'","r2'","f2'","b2'","x","x'","x2","y","y'","y2","z","z'","z2","M","M'","M2","E","E'","E2","S","S'","S2","exit"};
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