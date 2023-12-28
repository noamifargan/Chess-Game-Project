/*
Student: Ron Vaknin
ID: 305769440
Assignment no.2
Program: ChessPGM.cpp
22/11/2020
*/


#include "ChessPGM.h"
#include <iostream>
#include "Board.h"
#include "Pieces.h"
#include "GamePlay.h"
#include <string>
using namespace std;

int main(){
    GamePlay Match;
    //UNFINISHED SHOULD LOOP HERE EACH TURN WILL PRINT MESSAGE
    //Match.currBoard().printBoard();
//    Match.currBoard().SetPBoard(7,0,'R');
//    Match.currBoard().SetPBoard(7,4,'K');
//    Match.currBoard().SetPBoard(7,7,'R');
//    Match.currBoard().SetPBoard(0,1,'r');
//    Match.currBoard().SetPBoard(0,4,'k');
//    Match.currBoard().SetPBoard(0,7,'r');
//    Match.currBoard().SetPBoard(3,1,'Q');
    Match.currBoard().printBoard();
    Match.Move("E1 E2");

//    cout<< "Turn Count: " << Match.getTurns() <<  endl;
    //Match.Move("E1 G1");
    //Match.currBoard().printBoard();
//    cout<< "Turn Count: " << Match.getTurns() <<  endl;
  //  Match.Move("E8 C8");
//    Match.currBoard().printBoard();

    //cout<< "Turn Count:" << Match.getTurns() <<  endl;

//    cout<< "Turn Count:" << Match.getTurns() <<  endl;
//    Match.Move("E1 E2");
//    cout<< "Turn Count:" << Match.getTurns() <<  endl;
//    Match.Move("E7 E8 Q");
//    cout<< "Turn Count:" << Match.getTurns() <<  endl;
//    Match.Move("E2 E3");
//    cout<< "Turn Count:" << Match.getTurns() <<  endl;
//    Match.Move("E7 E6");
//    //Match.currBoard().SetPBoard(4,2,'n');
////    Match.Move("D1 D6");
//    //Match.currBoard().printBoard();
//    cout<< "Turn Count:" << Match.getTurns() <<  endl;
////    Match.Move("D6 C5");
//    Match.currBoard().printBoard();
    //Match.currBoard().printBoard();
   // Match.Move("C4 C4");
    //Match.Move("C5 G1");
    //Match.Move("C4 F4");

//    Match.Move("G8 A8");

    //cout << "Turn Count: "<<Match.getTurns()<< endl;
    //Match.currBoard().printBoard();


//    Match.currBoard().SetPBoard(2,1,'p');
    //Match.Move("A4 E4");
   // Match.currBoard().printBoard();
    //Match.Move("A4 D1");
//    //cout << "Turn Count: "<<Match.getTurns()<< endl;
//    Match.currBoard().printBoard();

//    Match.Move("E6 G3");
//    Match.currBoard().printBoard();
//    Match.Move("G3 D1");
//    Match.currBoard().printBoard();
//    Match.Move("D1 G3");
    return 0;
}