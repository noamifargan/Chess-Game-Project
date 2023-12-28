//
// Created by Ron on 24/11/2020.
//

#ifndef CPP_PIECES_H
#define CPP_PIECES_H
#include <string>
#include <iostream>
using namespace std;
class Pieces {
    public:
        Pieces(char**, bool,bool&,int&,bool);
        //DESTRUCTOR
        //COPY CONSTRUCTOR
        bool MvPiece(int,int,int,int);
        bool King();
        bool Queen();
        bool Rook();
        bool Bishop();
        bool Knight();
        bool Pawn();
        bool getAllowedPas();
    private:
        char** curr_board;
        char src_val,dest_val;
        int src_row,src_col,dest_row,dest_col;
        bool whosTurn;
        bool& EnPasantChk;
        int& EnPasntRow;
        bool Allowed_Caslte;
};


#endif //CPP_PIECES_H
