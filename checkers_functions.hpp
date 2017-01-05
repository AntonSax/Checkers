//Programmer: Anton Sax   Date: 9/24/16
//File checkers.h
//Purpose: Create a checkers board.

#ifndef CHECKERS_FUNCTIONS_H
#define CHECKERS_FUNCTIONS_H
#include <iostream>
#include <cmath>
using namespace std;

class Checkerboard
{
public:
  int **array;
  int r;
  int c;
  enum Piece {EMPTY, WHITE_PIECE, BLACK_PIECE, WHITE_PIECE_PROMOTED, BLACK_PIECE_PROMOTED};


  Checkerboard(int rowsize, int columnsize) : r(rowsize), c(columnsize)
  {
    array = new int *[r];
    for(int i = 0; i < r; i++)
    {
      array[i] = new int[c];
    }

    cout << "Array Created" << endl;
  }

  //Description:
  //Pre:
  //Post:
  void SimpleDisplay(int rows, int columns);

  //Description:
  //Pre:
  //Post:
  void FancyDisplay(int rows, int columns);

  //Description:
  //Pre:
  //Post:
  void BigFancyDisplay(int rows, int columns);

  //Description::
  //Pre:
  //Post:
  void ResetBoard(int rows, int columns);

  //Description:
  //Pre:
  //Post:
  void DestroyBoard(int rows);

  //Description:
  //Pre:
  //Post:
  bool WhiteMove(int xOld, int yOld, int xNew, int yNew, int xAverage, int yAverage);

  //Description:
  //Pre:
  //Post:
  bool BlackMove(int xOld, int yOld, int xNew, int yNew, int xAverage, int yAverage);

  //Description:
  //Pre:
  //Post:
  bool CheckJump(int xOld, int yOld, int xNew, int yNew);

  //Description: Currently only used to remove a checker off the board
  //Pre:
  //Post:
  void Remove(int x, int y);

  //Description:
  //Pre:
  //Post:
  void Promote();

  //Description:
  //Pre:
  //Post:
  void AvgLocation(int xOld, int yOld, int xNew, int yNew);

  //Description:
  //Pre:
  //Post:
  int DetermineWinner();
};


#endif