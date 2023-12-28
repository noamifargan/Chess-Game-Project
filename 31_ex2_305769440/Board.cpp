/*
Student: Ron Vaknin
ID: 305769440
Assignment no.2
Program: Board.cpp
22/11/2020
*/
#include "Board.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Pieces.h"
using namespace std;

Board::Board(){
    initBoard();
}
char** Board::GetBoard(){
    return board_all;
}
void Board::SetPBoard(int i,int j,char val){board_all[i][j] = val;}//for debug
void Board::initBoard(){
    board_all = new char *[8];
    for(int i = 0; i <8; i++)
        board_all[i] = new char [8];
    for (int row = 0; row < 8 ; ++row) {
        for (int col = 0; col < 8; col++) {
            if (row == 1) {
                board_all[row][col] = 'p';
            }
            else if (row == 6) {
                board_all[row][col] = 'P';
            } else {
                board_all[row][col] = '.';
            }
       }
    }
    //set knight black's
    board_all[7][1] = 'N';
    board_all[7][6] = 'N';
    //set knight white's
    board_all[0][1] = 'n';
    board_all[0][6] = 'n';
    //set rook black's
      board_all[7][0] = 'R';
    board_all[7][7] = 'R';
    //set rook white's
        board_all[0][0] = 'r';
    board_all[0][7] = 'r';
    //set bishop black's
    board_all[7][2] = 'B';
    board_all[7][5] = 'B';
    //set bishop white's
    board_all[0][2] = 'b';
    board_all[0][5] = 'b';
    //set queen and king black's
        board_all[7][3] = 'Q';
    board_all[7][4] = 'K';
    //set queen and king white's
    board_all[0][3] = 'q';
    board_all[0][4] = 'k';
}
void Board::emptyBoard(){//for debug
    for (int row = 0; row < 8 ; ++row) {
        for (int col = 0; col < 8; col++) {
                board_all[row][col] = '.';
        }
    }
}
void Board::printBoard(){
    for (int row = 8-1; row >= 0 ; --row) {
        cout << row+1 << " ";
        for (int col = 0; col < 8; ++col) {
            cout << board_all[row][col] << " ";
        }
        cout << endl;
    }
    cout << "  A B C D E F G H" << endl;


}
