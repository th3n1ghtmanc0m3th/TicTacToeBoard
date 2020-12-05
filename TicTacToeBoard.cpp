#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X) {
    turn = O;
  }
  else {
    turn = X;
  }
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  /* check occupancy */
  Piece thispiece = getPiece(row, column);
  if(thispiece == X) {
    return X;
    toggleTurn();
  }
  else if(thispiece == O) {
    return O;
    toggleTurn();
  }
  else if(thispiece == Blank){
    board[row][column] = turn;
    toggleTurn();
  }
  else {
    return Invalid;
  }
  /* something so unforeseen has happen */
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  /* Checking for negative numbers */
  if(row < 0 || column < 0) {
    return Invalid;
  }
  /* check bounds */
  if(row > 3 || column > 3) {
    return Invalid;
  }
  /* check occupancy */
  if(board[row][column] != Blank) {
      return board[row][column];
  }
  else {
    return Blank;
  }
  /* something so unforeseen has happened */
  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  bool blankFlag = false;
  /* check for horizontal wins */
  for(int i = 0; i < 3; i++) {
    Piece left = getPiece(i, 0);
    Piece middle = getPiece(i, 1);
    Piece right = getPiece(i, 2);

    /* check for actual piece */
    bool leftIsPiece = (left == X || left == 0);
    bool rightIsPiece = (right == X || right == 0);
    bool middleIsPiece = (middle == X || middle == 0);

    /* check for blank spaces */
    if(left == Blank || middle == Blank || right == Blank) {
      blankFlag = true;
    }

    /* if and blank continue */
    if(!leftIsPiece || !middleIsPiece || !rightIsPiece) {
      continue;
    }

    /* all pieces equal, declare winner */
    if(left == middle && middle == right) {
      return left;
    }
  }
	
  /* check for vertical wins */
  for(int i = 0; i < 3; i++) {
    Piece top = getPiece(i, 0);
    Piece middle = getPiece(i, 1);
    Piece bottom = getPiece(i, 2);

    /* check for actual piece */
    bool topIsPiece = (top == X || top == 0);
    bool bottomIsPiece = (bottom == X || bottom == 0);
    bool middleIsPiece = (middle == X || middle == 0);

    /* check for blank spaces */
    if(top == Blank || middle == Blank || bottom == Blank) {
      blankFlag = true;
    }

    /* if and blank continue */
    if(!topIsPiece || !middleIsPiece || !bottomIsPiece) {
      continue;
    }

    /* all pieces equal, declare winner */
    if(top == middle && middle == bottom) {
      return top;
    }
  }	

  /* check for diagonal winners left */
  {
    Piece top = getPiece(0, 0);
    Piece middle = getPiece(1, 1);
    Piece bottom = getPiece(2, 2);

    /* check if its valid piece */
    bool topIsPiece = (top == X || top == 0);
    bool bottomIsPiece = (bottom == X || bottom == 0);
    bool middleIsPiece = (middle == X || middle == 0);

    /* if and blank continue */
    if(!topIsPiece || !middleIsPiece || !bottomIsPiece) {
      continue;
    }

    /* all pieces equal, declare winner */
    if(topIsPiece && middleIsPiece && bottomIsPiece) {
      if(top == middle && middle == bottom) {
        return top;
      }
    }
  }
 
  /* check for diagonal winners right */
  {
    Piece top = getPiece(0, 2);
    Piece middle = getPiece(1, 1);
    Piece bottom = getPiece(2, 0);

    /* check if its valid piece */
    bool topIsPiece = (top == X || top == 0);
    bool bottomIsPiece = (bottom == X || bottom == 0);
    bool middleIsPiece = (middle == X || middle == 0);

    /* if and blank continue */
    if(!topIsPiece || !middleIsPiece || !bottomIsPiece) {
      continue;
    }

    /* all pieces equal, declare winner */
    if(topIsPiece && middleIsPiece && bottomIsPiece) {
      if(top == middle && middle == bottom) {
        return top;
      }
    }
  }  
	
  /* no winner, check blanks */
  if(blankFlag) {
    return Invalid;
  }
  else {
    return Blank;
  }

}
