/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(TicTacToeBoardTest, isToggleWorking)
{
  TicTacToeBoard board;
  Piece valuePiece = board.toggleTurn();
  ASSERT_EQ(valuePiece, O);
}

TEST(TicTacToeBoardTest, placePieceWorking) 
{
  /* check placement for every space */
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      TicTacToeBoard board;
      ASSERT_TRUE(board.placePiece(i,j) == X);
    }
  }
}

TEST(TicTacToeBoardTest, placePieceWorkingNegNum)
{
  /* check negative insert row */
  ASSERT_TRUE(board.placePiece(-1,0) == Invalid);
  /* check negative insert column */
  ASSERT_TRUE(board.placePiece(0,-1) == Invalid);
  /* check negative insert row and column */
  ASSERT_TRUE(board.placePiece(-1,-1) == Invalid);
}

TEST(TicTacToeBoardTest, placePieceTooBig) {
  TicTacToeBoard board;
  /* check too big insert row */
  ASSERT_TRUE(board.placePiece(3,0) == Invalid);
  /* check too big insert column */
  ASSERT_TRUE(board.placePiece(0,3) == Invalid);
  /* check too big insert row and column */
  ASSERT_TRUE(board.placePiece(3,3) == Invalid);
}

TEST(TicTacToeBoard, getWinnerInvalid) {
  TicTacToeBoard board;
  /* check board is blank */
  ASSERT_TRUE(board.getWinner() == Invalid);

  /* place pieces */
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(0,2);

  /* check if no winner and board not full */
  ASSERT_TRUE(board.getWinner() == Invalid);
}



/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
