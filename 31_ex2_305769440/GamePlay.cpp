/*
Student: Ron Vaknin
ID: 305769440
Assignment no.2
Program: GamePlay.cpp
24/11/2020
*/

//
// Created by Ron on 24/11/2020.
//
#include <string>
#include "Board.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "GamePlay.h"
#include "Pieces.h"
using namespace std;
#define IllegalErr cerr << "Illegal move; please enter a move:"<<endl;
#define InvalidErr cerr << "Invalid input; please enter a move:"<<endl;

GamePlay::GamePlay():n_Board(),turns(1){
    for (int i = 0; i < 3 ; ++i) {
        MovedCastleW[i] = false;
        MovedCastleB[i] = false;
    }
}

Board GamePlay::currBoard()
{
    return n_Board;
}
bool GamePlay::CheckSTDIN(string input){//check's if input is valid input
    string promotion_options="QRBN";
    if (input.length() > 5 && (input[5] != ' ' || promotion_options.find(input[6]) > promotion_options.length()-1))
    {
        return false;
    }
    if (!isupper(input[0]) || !isupper(input[3]) || !isdigit(input[1]) || !isdigit(input[4])
        || input.length() > 7 ||  input[0] < 64 || input[0]  > 73 || input[3]  < 64 || input[3]> 73
        || input[1] < 49 || input[1]  > 56 || input[4]  < 49 || input[4]> 56 || input[2] != ' ' ){return false;}

    return true;
}
void GamePlay::Move(string move_command) {
    if (!CheckSTDIN(move_command)){InvalidErr;return;}  //check's if the input from the user is a valid input
    if (Check()){IllegalErr;return;} //CHECK
    if (CheckMate()){   //CHECKMATE
        if (whosTurn()){cout << "White wins with checkmate!"<<endl;}
        if (!whosTurn()){cout << "Black wins with checkmate!"<<endl;}

        return;}

    //Stalemate
    //

    src_row=(move_command[1]- '0')-1;//SOURCE ROW
    src_col=convertLetter(move_command[0])-1;//SOURCE COLLUM
    dest_row=(move_command[4]- '0')-1;//DESTINATION ROW
    dest_col=convertLetter(move_command[3])-1;//DESTINATION COLLUM
    dest_val = n_Board.GetBoard()[dest_row][dest_col];//the value of the destination
    src_val = n_Board.GetBoard()[src_row][src_col];//the value of the source
    Pieces chk(n_Board.GetBoard(),whosTurn(),AllowedEnPas,EnPasntRow,AllowedCastle());//new pieces object
    if (chk.MvPiece(src_row,src_col,dest_row,dest_col))
    {
        if (Promotion()){//will change the pawn if promotion is activated
            if (whosTurn()){
                n_Board.GetBoard()[dest_row][dest_col] = (char)tolower(move_command[6]);
                n_Board.GetBoard()[src_row][src_col] = '.';
            }
            else{
                n_Board.GetBoard()[dest_row][dest_col] = move_command[6];
                n_Board.GetBoard()[src_row][src_col] = '.';
            }

        }
        else if (AllowedEnPas)//will change the pawn if en pasant is activated
        {
            n_Board.GetBoard()[dest_row][dest_col] = n_Board.GetBoard()[src_row][src_col];
            n_Board.GetBoard()[src_row][src_col] = '.';
        } else if (AllowedCastle()){//castling will change king location and rook location according to the side of the castling
            if (whosTurn()) {
                if (dest_col > 4) {
                    n_Board.GetBoard()[dest_row][dest_col] = n_Board.GetBoard()[src_row][src_col];
                    n_Board.GetBoard()[src_row][src_col] = '.';
                    n_Board.GetBoard()[dest_row][dest_col - 1] = 'r';
                    n_Board.GetBoard()[dest_row][dest_col + 1] = '.';
                } else {
                    n_Board.GetBoard()[dest_row][dest_col] = n_Board.GetBoard()[src_row][src_col];
                    n_Board.GetBoard()[src_row][src_col] = '.';
                    n_Board.GetBoard()[dest_row][dest_col + 1] = 'r';
                    n_Board.GetBoard()[dest_row][dest_col - 2] = '.';

                }
            }
            else if(!whosTurn()){
                        if(dest_col > 4){
                            n_Board.GetBoard()[dest_row][dest_col] = n_Board.GetBoard()[src_row][src_col];
                            n_Board.GetBoard()[src_row][src_col] = '.';
                            n_Board.GetBoard()[dest_row][dest_col-1] = 'R';
                            n_Board.GetBoard()[dest_row][dest_col+1] = '.';
                        }
                        else{
                            n_Board.GetBoard()[dest_row][dest_col] = n_Board.GetBoard()[src_row][src_col];
                            n_Board.GetBoard()[src_row][src_col] = '.';
                            n_Board.GetBoard()[dest_row][dest_col+1] = 'R';
                            n_Board.GetBoard()[dest_row][dest_col-2] = '.';
                        }
            }
        }
        else//move the piece
        {
            n_Board.GetBoard()[dest_row][dest_col] = n_Board.GetBoard()[src_row][src_col];
            n_Board.GetBoard()[src_row][src_col] = '.';
        }
    }
    else
    {
        IllegalErr;
        return;
    }
    DidMovedCastle();//chcek's if current team turn King and rooks didnt moved in this turn
    turns++;
    return;
}
bool GamePlay::Check() {

    Pieces ChkifCaptureK(n_Board.GetBoard(),whosTurn(),AllowedEnPas,EnPasntRow,AllowedCastle());
    if (whosTurn())//white turn
    {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (n_Board.GetBoard()[i][j] == 'k') {
                    kingRow = i, kingCol = j;
                }
            }
        }
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (isupper(n_Board.GetBoard()[i][j])) {
                    if (ChkifCaptureK.MvPiece(i, j, kingRow, kingCol)) {attRow=i;attCol=j;return true; }
                }
            }
        }
    }
    else if(!whosTurn()) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (n_Board.GetBoard()[i][j] == 'K') {
                    kingRow = i, kingCol = j;
                }
            }
        }
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (islower(n_Board.GetBoard()[i][j])) {
                    if (ChkifCaptureK.MvPiece(i, j, kingRow, kingCol)) { attRow=i;attCol=j;return true; }
                }
            }
        }
    }
    return false;
}
int GamePlay::convertLetter(char c){
    switch (c)
    {
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'C':
            return 3;
        case 'D':
            return 4;
        case 'E':
            return 5;
        case 'F':
            return 6;
        case 'G':
            return 7;
        case 'H':
            return 8;
        default:
            InvalidErr;
    }
    return 0;
}
int GamePlay::getTurns(){return turns;}
bool GamePlay::whosTurn(){return turns % 2;}//whos turn , even black's odd white's
bool GamePlay::Promotion(){//check if promotion available
    if (whosTurn() && src_val == 'p' && dest_row == 7)//white turn
    {
        return true;
    }
    else if (!whosTurn() && src_val == 'P' && dest_row == 1)//black turn
    {
         return true;
    }
    return false;
}
 bool GamePlay::AllowedCastle( ) {
    if (src_val == 'k' || src_val == 'K') {
        //CHECK IF K IN CHECK FIRST
        if (Check()){return false;}
        ///HERE
        if (whosTurn())
        { //white's
            //check if king, right rook didn't moved, and if the path is clear
            if (!MovedCastleW[0] && (dest_row == 0 && dest_col == 6 && !MovedCastleW[2])) {
                for (int col = 5; col < 7; ++col) {
                    if (n_Board.GetBoard()[0][col] != '.') { return false;}
                }
                return true;
            }
            //check if king, left rook didn't moved, and if the path is clear
            if (!MovedCastleW[0] && (dest_row == 0 && dest_col == 2 && !MovedCastleW[1])) {
                for (int col = 3; col > 0; --col) {
                    if (n_Board.GetBoard()[0][col] != '.') { return false; }
                }
                return true;
            }
        }
        else if (!whosTurn())//black's
        {
            //check if king, right rook didn't moved, and if the path is clear
            if (!MovedCastleB[0] && (dest_row == 7 && dest_col == 6 && !MovedCastleB[2])) {
                for (int col = 5; col < 7; ++col) {
                    if (n_Board.GetBoard()[7][col] != '.') { return false; }
                }
                return true;
            }
                //check if king, left rook didn't moved, and if the path is clear
                if (!MovedCastleB[0] && (dest_row == 7 && dest_col == 2 && !MovedCastleB[1])) {
                    for (int col = 3; col > 0; --col) {
                        if (n_Board.GetBoard()[7][col] != '.') { return false; }
                    }
                    return true;
                }
        }

    }
    return false;
}
void GamePlay::DidMovedCastle() {
    if (whosTurn())//white Turn
    {
        //white's king has moved
        if (src_val == 'k' && src_row==0 && src_col==4) {MovedCastleW[0] = true;}
        else if(src_val == 'r')
        {
            //left rook white team has moved
            if (src_col == 0 && src_row == 0){MovedCastleW[1] = true;}
            //right rook white team has moved
            else if (src_col == 7 && src_row == 0){ MovedCastleW[2] = true;}
        }
    }
    else if( !whosTurn()){
        //black's king has moved
        if (src_val == 'K' && src_row==7 && src_col == 4) {
            MovedCastleB[0] = true;
        }
        else if(src_val == 'R')
        {
            //left rook black team
            if (src_row==7 && src_col == 0){
                MovedCastleB[1] = true;
            }
            //right rook black team
            else if (src_row==7 && src_col == 7){
                MovedCastleB[2] = true;
            }
        }
    }
}

bool GamePlay::CheckMate() {
    if (!Check()){return false;}
    bool ChkArray[]={false, false, false};//[C,P,R]

    Pieces ChkifCaptureK(n_Board.GetBoard(),whosTurn(),AllowedEnPas,EnPasntRow,AllowedCastle());
    if (whosTurn())//white turn
    {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (islower(n_Board.GetBoard()[i][j])) {
                    ///CAPTURE THE ATTACKER
                    if (ChkifCaptureK.MvPiece(i, j, attRow, attCol)) {ChkArray[0] = true;}
                    /// PROTECT///UNFINISHED
                    if (attCol == kingCol)//if they are at the same collum
                    {
                        if (attRow > kingRow)//up
                        {

                        }
                        else if (attRow < kingRow)//down
                        {

                        }
                    }
                    if (attRow == kingRow)
                    {
                        if (attCol > kingCol)//right
                        {

                        }
                        else if (attCol < kingCol)//left
                        {

                        }

                    }
                    if (attCol < kingCol && attRow > kingRow)//if left diagonal  up
                    {

                    }
                    if (attCol > kingCol && attRow > kingRow)//if right diagonal  up
                    {

                    }
                    ///RUN AWAY///UNFINISHED //

                }
            }
        }
    }
    else if(!whosTurn()) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (isupper(n_Board.GetBoard()[i][j])) {
                    if (ChkifCaptureK.MvPiece(i, j, attRow, attCol)) {ChkArray[0] = true;}
                }
            }
        }
    }

    return false;

}

