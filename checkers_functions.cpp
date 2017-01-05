//Programmer: Anton Sax   Date: 9/24/16
//File checkers.hpp
//Purpose: Create a checkers board.

#include "checkers_functions.hpp"

//Please note that the y and x values seem to be switched.

void Checkerboard::SimpleDisplay(int rows, int columns)
{
  cout << "    1 2 3 4 5 6 7 8 " << endl;
  cout << endl;
  for(int m = 0; m < rows; m++)
  {
    cout << m+1 << "  [";
    for(int n = 0; n < columns; n++)
    {
      cout << array[m][n] << ",";
    }
    cout << "]" << endl;
  }
  cout << endl;
  //cout << "Array Displayed" << endl << endl << endl;
  return;
}

void Checkerboard::FancyDisplay(int rows, int columns)
{
  for(int m = 0; m < rows; m++)
  {
    cout << " |———|———|———|———|———|———|———|———|" << endl;
    for(int n = 0; n < columns; n++)
    {
      cout << " | " << array[m][n];
    }
    cout << " |" << endl;
  }
  cout << " |———|———|———|———|———|———|———|———|" << endl;
  //cout << endl << "Array Displayed" << endl << endl << endl;
  return;
}

void Checkerboard::BigFancyDisplay(int rows, int columns)
{
  for(int m = 0; m < rows; m++)
  {
    cout << "  |—————|—————|—————|—————|—————|—————|—————|—————|" << endl;
    cout << "  |     |     |     |     |     |     |     |     |" << endl;
    for(int n = 0; n < columns; n++)
    {
      cout << "  |  " << array[m][n];
    }
    cout << "  |" << endl;
    cout << "  |     |     |     |     |     |     |     |     |" << endl;
  }
  cout << "  |—————|—————|—————|—————|—————|—————|—————|—————|" << endl;
  //cout << endl << "Array Displayed" << endl << endl << endl;
  return;
}

void Checkerboard::ResetBoard(int rows, int columns)
{
  cout << "Setting up game..." << endl;
  for(int s = 0; s < rows; s++)
  {
    for(int t = 0; t < columns; t++)
    {
      if(((s == 0 || s == 2) && (t % 2 == 1 )) || ((s == 1) && (t % 2 == 0)))
      {
        array[s][t] = BLACK_PIECE;
      }
      if(((s == 5 || s == 7) && (t % 2 == 0)) || ((s == 6) && (t % 2 == 1)))
      {
        array[s][t] = WHITE_PIECE;
      }
    }
  }
  cout << "Game setup." << endl;
  cout << endl;
  return;
}


void Checkerboard::DestroyBoard(int rows)
{
  for(int j = 0; j < rows; j++)
  {
      delete [] array[j];
  }
  delete [] array;
  array = NULL;
  return;
}

bool Checkerboard::WhiteMove(int xOld, int yOld, int xNew, int yNew, int xAverage, int yAverage)
{
  xOld--;
  yOld--;
  xNew--;
  yNew--;
  xAverage--;
  yAverage--;

  if((xOld < 0) || (xOld > 7) || (xNew < 0) || (xNew > 7))
  {
    cout << "----------------------------------------------------" << endl;
    cout << "\tINVALID ORDER: That is out of bounds" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
    return false;
  }

  if(array[xNew][yNew] == EMPTY)
  {
    if(((xNew % 2 == 0) && (yNew % 2 == 1)) || ((xNew % 2 == 1) && (yNew % 2 == 0)))  //Only checks for valid board space
    {
      if((abs(xNew - xOld) != 0) && (abs(yNew - yOld) != 0))  //Makes sure you are moving diagonally
      {
        if((xNew < xOld) && (array[xOld][yOld] == WHITE_PIECE)) //Makes sure that a white piece can't move backwards
        {
          if(((array[xAverage][yAverage] == WHITE_PIECE) || (array[xAverage][yAverage] == WHITE_PIECE_PROMOTED)) && ((abs(xOld - xNew) == 2) && (abs(yOld - yNew) == 2))) //Makes sure you can't jump your own piece
          {
            cout << "-------------------------------------------------------------" << endl;
            cout << "\tINVALID ORDER: You cannot jump your own piece" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
            return false;
          }
          else
          {
            array[xOld][yOld] = EMPTY;
            array[xNew][yNew] = WHITE_PIECE;
            return true;
          }
        }
        else if(xNew < xOld)
        {
          cout << "-------------------------------------------------------------------" << endl;
          cout << "\tINVALID ORDER: You cannot move that piece backwards" << endl;
          cout << "-------------------------------------------------------------------" << endl;
          cout << endl;
          return false;
        }
        else if(array[xOld][yOld] == WHITE_PIECE_PROMOTED) //Allows promoted piece to move forwards or backwards
        {
          array[xOld][yOld] = EMPTY;
          array[xNew][yNew] = WHITE_PIECE_PROMOTED;
          return true;
        }
      }
      else
      {
        cout << "----------------------------------------------------------" << endl;
        cout << "\tINVALID ORDER: You tried to move laterally" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << endl;
        return false;
      }
    }
    else
    {
      cout << "------------------------------------------------" << endl;
      cout << "\tINVALID ORDER: Not a board space" << endl;
      cout << "------------------------------------------------" << endl;
      cout << endl;
      return false;
    }
  }
  cout << "--------------------------------------------------------" << endl;
  cout << "\tINVALID ORDER: Target space is not empty" << endl;
  cout << "--------------------------------------------------------" << endl;
  return false;
}

bool Checkerboard::BlackMove(int xOld, int yOld, int xNew, int yNew, int xAverage, int yAverage)
{
  xOld--;
  yOld--;
  xNew--;
  yNew--;
  xAverage--;
  yAverage--;

  if((xOld < 0) || (xOld > 7) || (xNew < 0) || (xNew > 7))
  {
    cout << "----------------------------------------------------" << endl;
    cout << "\tINVALID ORDER: That is out of bounds" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
    return false;
  }

  if(array[xNew][yNew] == EMPTY)
  {
    if(((xNew % 2 == 0) && (yNew % 2 == 1)) || ((xNew % 2 == 1) && (yNew % 2 == 0)))  //Only checks for valid board space
    {
      if((abs(xNew - xOld) != 0) && (abs(yNew - yOld) != 0))  //Makes sure you are moving diagonally
      {
        if((xNew > xOld) && (array[xOld][yOld] == BLACK_PIECE)) //Makes sure that a black piece can't move backwards
        {
          if(((array[xAverage][yAverage] == BLACK_PIECE) || (array[xAverage][yAverage] == BLACK_PIECE_PROMOTED)) && ((abs(xOld - xNew) == 2) && (abs(yOld - yNew) == 2)))//Makes sure you can't jump your own piece
          {
            cout << "-------------------------------------------------------------" << endl;
            cout << "\tINVALID ORDER: You cannot jump your own piece" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
            return false;
          }
          else
          {
            array[xOld][yOld] = EMPTY;
            array[xNew][yNew] = BLACK_PIECE;
            return true;
          } 
        }
        else if((xNew < xOld) && (array[xOld][yOld] == BLACK_PIECE))   //If a black piece tried to move backwards
        {
          cout << "-------------------------------------------------------------------" << endl;
          cout << "\tINVALID ORDER: You cannot move that piece backwards" << endl;
          cout << "-------------------------------------------------------------------" << endl;
          cout << endl;
          return false;
        }
        else if(array[xOld][yOld] == BLACK_PIECE_PROMOTED) //Allows promoted piece to move forwards or backwards
        {
          array[xOld][yOld] = EMPTY;
          array[xNew][yNew] = BLACK_PIECE_PROMOTED;
          return true;
        }
      }
      else
      {
        cout << "----------------------------------------------------------" << endl;
        cout << "\tINVALID ORDER: You tried to move laterally" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << endl;
        return false;
      }
    }
    else
    {
      cout << "-------------------------------------" << endl;
      cout << "\tINVALID ORDER: Not a board space" << endl;
      cout << "-------------------------------------" << endl;
      cout << endl;
      return false;
    }
  }
  cout << "--------------------------------------------------------" << endl;
  cout << "\tINVALID ORDER: Target space is not empty" << endl;
  cout << "--------------------------------------------------------" << endl;
  return false;
}

bool Checkerboard::CheckJump(int xOld, int yOld, int xNew, int yNew)
{
  if((abs(xOld - xNew) == 2) && (abs(yOld - yNew) == 2))
  {
    cout << "------------------------------------" << endl;
    cout << "\tA jump was performed" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    return true;
  }
  return false;
}

void Checkerboard::Remove(int x, int y)
{
  x--;
  y--;
  array[x][y] = EMPTY;
  cout << "-------------------------------------" << endl;
  cout << "\tA checker was removed" << endl;
  cout << "-------------------------------------" << endl;
  cout << endl;

  return;
}

void Checkerboard::Promote()
{
  for(int i = 0; i <= 7; i++)
  {
    if(array[7][i] == BLACK_PIECE)
    {
      array[7][i] = BLACK_PIECE_PROMOTED;
    }

    if(array[0][i] == WHITE_PIECE)
    {
      array[0][i] = WHITE_PIECE_PROMOTED;
    }
  }

  return;
}

void Checkerboard::AvgLocation(int xOld, int yOld, int xNew, int yNew)
{
  int xAverage = (xOld + xNew) / 2;
  int yAverage = (yOld + yNew) / 2;

  cout << "Average X: " << xAverage << endl;
  cout << "Average Y: " << yAverage << endl;

  return;
}


int Checkerboard::DetermineWinner()
{
  bool blackWinner = true;
  bool whiteWinner = true;

  for(int x = 0; x < 8; x++)
  {
    for(int y = 0; y < 8; y++)
    {
      if((array[x][y] == BLACK_PIECE) || (array[x][y] == BLACK_PIECE_PROMOTED)) //check to see if a black piece exists
      {
        blackWinner = false;
      }
      if((array[x][y] == WHITE_PIECE) || (array[x][y] == WHITE_PIECE_PROMOTED)) //check to see if a white piece exists
      {
        whiteWinner = false;
      }
    }
  }

  if(blackWinner)
  {
    cout << "------------------------------------------" << endl;
    cout << "\t\tBLACK WINS" << endl;
    cout << "------------------------------------------" << endl;
    return 2;
  }
  else if(whiteWinner)
  {
    cout << "------------------------------------------" << endl;
    cout << "\t\tWHITE WINS" << endl;
    cout << "------------------------------------------" << endl;
    return 1;
  }

  //no winner
  return 0;
}