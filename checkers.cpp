//Programmer: Anton Sax   Date: 9/24/16
//File checkers.cpp
//Purpose: Create a checkers board.

#include "checkers_functions.hpp"

//Please note that the y and x values seem to be switched.

int main()
{
  int rows;
  int columns;
  int xOldPosition;
  int yOldPosition;
  int xNewPosition;
  int yNewPosition;
  int xAverage;
  int yAverage;
  bool turnBlack = true;
  bool turnWhite = true;
  bool gameNotEnded = true;
  char answer;


  //Create the array for the board
  cout << "Decide the size of the array." << endl;
  cout << "Rows: ";
  cin >> rows;
  cout << "Columns: ";
  cin >> columns;

  Checkerboard Checkerboard(rows, columns);

  //Display the array simply
  Checkerboard.SimpleDisplay(rows, columns);
  //Show the fancy version
  //Checkerboard.FancyDisplay(rows, columns);
  //Show the bigger fancy version
  //Checkerboard.BigFancyDisplay(rows, columns);

  //Setup the game start
  Checkerboard.ResetBoard(rows, columns);

  //Checkerboard.SimpleDisplay(rows, columns);
  Checkerboard.SimpleDisplay(rows, columns);

  while(gameNotEnded)
  {
    while(turnBlack)
    {
      //Black's Turn
      cout << "It is Black's (Evens) turn." << endl;
      cout << "Location of piece to move: ";
      cin >> xOldPosition >> yOldPosition;
      cout << "Location to move to: ";
      cin >> xNewPosition >> yNewPosition;
      cout << endl;

      xAverage = (xOldPosition + xNewPosition) / 2;
      yAverage = (yOldPosition + yNewPosition) / 2;

      if(Checkerboard.BlackMove(xOldPosition, yOldPosition, xNewPosition, yNewPosition, xAverage, yAverage))
      {
        if(Checkerboard.CheckJump(xOldPosition, yOldPosition, xNewPosition, yNewPosition))
        {
          Checkerboard.Remove(xAverage, yAverage);
          cout << "Make another jump? (Y or N)" << endl;
          cin >> answer;
          if(answer == 'N')
          {
            turnBlack = false;
            turnWhite = true;
          }
        }
        else
        {
          turnBlack = false;
          turnWhite = true;
        }
      }
    }


    Checkerboard.SimpleDisplay(rows, columns);
    cout << endl << endl << endl;


    while(turnWhite)
    {
      //White's Turn
      cout << "It is White's (Odds) turn." << endl;
      cout << "Location of piece to move: ";
      cin >> xOldPosition >> yOldPosition;
      cout << "Location to move to: ";
      cin >> xNewPosition >> yNewPosition;
      cout << endl;

      xAverage = (xOldPosition + xNewPosition) / 2;
      yAverage = (yOldPosition + yNewPosition) / 2;

      if(Checkerboard.WhiteMove(xOldPosition, yOldPosition, xNewPosition, yNewPosition, xAverage, yAverage))
      {
        if(Checkerboard.CheckJump(xOldPosition, yOldPosition, xNewPosition, yNewPosition))
        {
          Checkerboard.Remove(xAverage, yAverage);
          cout << "Make another jump? (Y or N)" << endl;
          cin >> answer;
          if(answer == 'N')
          {
            turnWhite = false;
            turnBlack = true;
          }
        }
        else
        {
          turnWhite = false;
          turnBlack = true;
        }
      }
    }


    Checkerboard.Promote();
    Checkerboard.SimpleDisplay(rows, columns);
    cout << endl << endl << endl;


    if((Checkerboard.DetermineWinner() == 1) || (Checkerboard.DetermineWinner() == 2))
      gameNotEnded = false;
  }

  return 0;
}