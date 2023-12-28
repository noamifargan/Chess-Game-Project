//
// Created by Ron on 24/11/2020.
//

#ifndef CPP_GAMEPLAY_H
#define CPP_GAMEPLAY_H


class GamePlay {
    public:
        GamePlay();
        //DESTRUCTOR
        //COPY CONSTRUCTOR
        void Move(string);
        int convertLetter(char);
        Board currBoard();
        int getTurns();
        bool whosTurn();
        bool CheckSTDIN(string);
        bool Check();
        bool CheckMate();
        bool Promotion();
        bool AllowedCastle();
        void DidMovedCastle();
//        bool EnPasnat();
////        void SetAllowedEnPas(bool);
////        bool GetAllowedEnPas();
    private:
        Board n_Board;
        int kingRow,kingCol,attRow,attCol;
        int src_row,src_col,dest_row,dest_col;
        char src_val,dest_val;
        int turns;
        bool AllowedEnPas;
        int EnPasntRow;
        bool MovedCastleW[3];//[k,lr,rr]
        bool MovedCastleB[3];//[K,lR,rR]
};


#endif //CPP_GAMEPLAY_H
