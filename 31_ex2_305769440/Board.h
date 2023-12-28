//
// Created by Ron on 22/11/2020.
//

#ifndef CPP_BOARD_H
#define CPP_BOARD_H
#include <string>
using namespace std;
class Board {
    public:
        Board();
        //DESTRUCTOR
        //COPY CONSTRUCTOR
        void initBoard();
        void SetTurns(int i);
        void SetPBoard(int,int,char);
        char** GetBoard();
        void printBoard();
        void Move(string);
        void emptyBoard();
        int convertLetter(char);
    private:
        char** board_all;
};


#endif //CPP_BOARD_H
