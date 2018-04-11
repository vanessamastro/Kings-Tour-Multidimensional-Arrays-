// Lab 4: King's Tour
// Purpose: to practice working with 2-D arrays by writing a program that determines 
// whether the values stored in a m * n "chess board" correspond to the positions 1 to mn
// of a "King's Tour" around the "chess board"
// Vanesssa Mastrosimone
// CSC 2430
// 2/2/18
// Header file for chess board ADT
#include <iostream>

using namespace std;

//Limits maximum board size
const unsigned int MAX_SQUARES_PER_SIDE = 10;

//Stores a value for each square, board can be any size (rectangular 
// or square) up to MAX_SQUARES_PER_SIDE x MAX_SQUARES_PER_SIDE
typedef struct {
    int board[MAX_SQUARES_PER_SIDE][MAX_SQUARES_PER_SIDE];
    unsigned int numberRows;
    unsigned int numberColumns;
} CHESSBOARD;

//Initializes dimensions of board, false if dimensions too large, true if ok
bool InitBoard(unsigned int numberRows, unsigned int numberColumns, CHESSBOARD& chessboard);

//Read values for squares from file, returns false if not enough values
//or some value(s) are not positive numbers, true for success
bool ReadBoard(istream& fin, CHESSBOARD& chessboard);

//Find row and column of a square where value appears. Any square
//is where value appears is ok. Returns true if found, false otherwise
bool FindOnBoard(unsigned int value, int& row, int& col, CHESSBOARD& chessboard);

//Displays values on chessboard using characters -|* to delineate the squares
void PrintBoard(CHESSBOARD& chessboard);