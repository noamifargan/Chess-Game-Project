/*
Student: Ron Vaknin
ID: 305769440
Assignment no.2
Program: Pieces.cpp
24/11/2020
*/
#include "Board.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <string>
#include "Pieces.h"
#include "GamePlay.h"
#include "ChessPGM.h"
using namespace std;
Pieces::Pieces(char** cb,bool t,bool& Enps,int& epsr,bool alc)
:curr_board(cb),whosTurn(t),EnPasantChk(Enps),EnPasntRow(epsr),Allowed_Caslte(alc)
{

}

bool Pieces::MvPiece(int src_row,int src_col, int dest_row, int dest_col)
{
    this->src_row = src_row;
    this->src_col = src_col;
    this->dest_row = dest_row;
    this->dest_col = dest_col;
    this->src_val = curr_board[src_row][src_col];
    this->dest_val = curr_board[dest_row][dest_col];
    //(!whosTurn()) &&
    if ((isupper(src_val)))//black player - and source is upper case letter
    {
        if (isupper(dest_val)){return false;}
        switch (src_val) {
            case 'K': {
                return King();
            }
            case 'Q': {
                return Queen();
            }
            case 'R': {
                return Rook();
            }
            case 'B': {
                return Bishop();
            }
            case 'N': {
                return Knight();
            }
            case 'P': {
                return Pawn();
            }
        }
    }
    ///(whosTurn()) &&
    else if ((islower(src_val)))
    {
        if (islower(dest_val)) { return false; }
        switch (src_val) {
            case 'k': {
                return King();
            }
            case 'q': {
                return Queen();
            }
            case 'r': {
                return Rook();
            }
            case 'b': {
                return Bishop();
            }
            case 'n': {
                return Knight();
            }
            case 'p': {
                return Pawn();
            }
        }
    }
    return false;
}
bool Pieces::King()
{
    if (src_col == dest_col){
        if (abs(src_row - dest_row) > 1) { return false;}

    }
    if (abs(src_col - dest_col) > 1  && !Allowed_Caslte) { return false;}
    if (abs(src_row-dest_row) > 2 && Allowed_Caslte){return false;}
    return true;
}
bool Pieces::Queen() {


        if (src_col == dest_col)//go straight
        {
            if (src_row < dest_row) {//straight forward
                for (int i = src_row + 1; i < dest_row; ++i) {
                    if (curr_board[i][src_col] != '.') { return false; }
                }
                return true;
            } else if (src_row > dest_row)//straight backward
            {
                for (int i = src_row - 1; i > dest_row; --i) {
                    if (curr_board[i][src_col] != '.') { return false; }
                }
                return true;
            }
        }
        else if (src_row == dest_row)//go left or right white's
        {

            if (src_col > dest_col) {//go left
                for (int i = src_col - 1; i > dest_col; --i) {

                    if (curr_board[src_row][i] != '.') {return false; }
                }
                return true;
            }
            else if (src_col < dest_col)//go right
            {
                for (int i = src_col + 1; i < dest_col; ++i) {
                    if (curr_board[src_row][i] != '.') { return false; }
                }
                return true;
            }
        }
        //DIAGONALS
        else if (src_col < dest_col && src_row < dest_row)//Diagonal White Right UP | Black Left UP
        {

            if(abs(src_col-src_row) != abs(dest_col-dest_row)){return false;}
            for (int i = src_row + 1, j = src_col + 1; (i < dest_row) && (j < dest_col); i++, j++) {
                if (curr_board[i][j] != '.') {
                    return false;
                }
            }
            return true;
        }
        else if (src_col < dest_col && src_row > dest_row)//Diagonal White Left Down | Black Right Down
        {
            //cout<<"D\n";
            if((src_col+src_row) != (dest_col+dest_row)){;return false;}
            for (int i = src_row - 1, j = src_col + 1; (i > dest_row) && (j < dest_col); i--, j++) {
                if (curr_board[i][j] != '.') {
                    ;return false;
                }
            }
            return true;
        }
        else if (src_col > dest_col && src_row < dest_row)//Diagonal White Left UP | Black Right UP
        {
            if((src_col+src_row) != (dest_col+dest_row)){;return false;}
            for (int i = src_row + 1, j = src_col - 1; (i < dest_row) && (j > dest_col); i++, j--) {
                if (curr_board[i][j] != '.') {
                    ;return false;
                }
            }
            return true;
        }
        else if (src_col > dest_col && src_row > dest_row)//Diagonal White Right Down | Black Left Down
        {
            if(abs(src_col-src_row) != abs(dest_col-dest_row)){return false;}
            for (int i = src_row - 1, j = src_col - 1; (i > dest_row) && (j > dest_col); i--, j--) {
                if (curr_board[i][j] != '.') {
                    ;return false;
                }
            }
            return true;
        }

    return false;
}

bool Pieces::Rook(){

    if (dest_col != src_col && src_row != dest_row){return false;}
    if (src_col == dest_col)//go straight
    {
        if (src_row < dest_row) {//straight forward
            for (int i = src_row + 1; i < dest_row; ++i) {
                if (curr_board[i][src_col] != '.') { return false; }
            }
            return true;
        } else if (src_row > dest_row)//straight backward
        {
            for (int i = src_row - 1; i > dest_row; --i) {
                if (curr_board[i][src_col] != '.') { return false; }
            }
            return true;
        }
    }
    else if (src_row == dest_row)//go left or right white's
    {

        if (src_col > dest_col) {//go left

            for (int i = src_col - 1; i > dest_col; --i) {

                if (curr_board[src_row][i] != '.') { return false; }
            }
            return true;
        }
        else if (src_col < dest_col)//go right
        {
            for (int i = src_col + 1; i < dest_col; ++i) {
                if (curr_board[src_row][i] != '.') { return false; }
            }
            return true;
        }
    }

    return false;
}
bool Pieces::Bishop() {
    if (dest_col == src_col || src_row == dest_row){return false;}
    if (src_col < dest_col && src_row < dest_row)//Diagonal White Right UP | Black Left UP
    {
        if (abs(src_col - src_row) != abs(dest_col - dest_row)) {
            return false;
        }
        for (int i = src_row + 1, j = src_col + 1; (i < dest_row) && (j < dest_col); i++, j++) {
            if (curr_board[i][j] != '.') {
                return false;
            }
        }
        return true;
    }
    else if (src_col < dest_col && src_row > dest_row)//Diagonal White Left Down | Black Right Down
    {
        if ((src_col + src_row) != (dest_col + dest_row)) {
            return false;
        }
        for (int i = src_row - 1, j = src_col + 1; (i > dest_row) && (j < dest_col); i--, j++) {
            if (curr_board[i][j] != '.') { ;
                return false;
            }
        }
        return true;
    }
    else if (src_col > dest_col && src_row < dest_row)//Diagonal White Left UP | Black Right UP
    {
        if ((src_col + src_row) != (dest_col + dest_row)) {
            return false;
        }
        for (int i = src_row + 1, j = src_col - 1; (i < dest_row) && (j > dest_col); i++, j--) {
            if (curr_board[i][j] != '.') { ;
                return false;
            }
        }
        return true;
    }
    else if (src_col > dest_col && src_row > dest_row)//Diagonal White Right Down | Black Left Down
    {
        if (abs(src_col - src_row) != abs(dest_col - dest_row)) {
            return false;
        }
        for (int i = src_row - 1, j = src_col - 1; (i > dest_row) && (j > dest_col); i--, j--) {
            if (curr_board[i][j] != '.') { ;
                return false;
            }
        }
        return true;
    }
    return false;
}
bool Pieces::Knight(){
    if (abs(src_col-dest_col)*abs(src_row-dest_row)== 2)
    {
        return true;
    }
    return false;}
bool Pieces::Pawn(){
    if (EnPasantChk){
        if ((src_col == dest_col + 1 || src_col == dest_col - 1) && (abs(src_col - dest_col) == 1))
        {
            EnPasantChk= false;
            curr_board[EnPasntRow][dest_col] = '.';
            return true;
        }
        EnPasantChk= false;
    }
    else if ((src_col == dest_col + 1 || src_col == dest_col - 1) && (abs(src_col - dest_col) == 1))
    {
        if (!whosTurn && islower(dest_val)){
            return true;
        }
        if (whosTurn && isupper(dest_val)){
            return true;
        }
    }
    else if ((src_col == dest_col) && (abs(src_row - dest_row) == 1))
    {
            return true;
    }
    else if ((src_col == dest_col) && (abs(src_row - dest_row) == 2) && (src_row == 1 || src_row == 6))
    {
        //save the row of the pawn for en pasant if the condition is true
        if (whosTurn && (curr_board[dest_row][dest_col+1] =='P' || curr_board[dest_row][dest_col-1] =='P' )){ EnPasntRow=dest_row;EnPasantChk=true;}
        if (!whosTurn && (curr_board[dest_row][dest_col+1] =='p' || curr_board[dest_row][dest_col-1] =='p')){ EnPasntRow=dest_row;EnPasantChk=true;}
        if (whosTurn && (curr_board[src_row+1][src_col] != '.') || !whosTurn && (curr_board[src_row-1][src_col] != '.'))
            {
                return false;
            }
        return true;
    }
    return false;
}
