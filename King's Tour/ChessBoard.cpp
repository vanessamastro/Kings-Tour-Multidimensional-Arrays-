// Lab 4: King's Tour
// Purpose: to practice working with 2-D arrays by writing a program that determines 
// whether the values stored in a m * n "chess board" correspond to the positions 1 to mn
// of a "King's Tour" around the "chess board"
// Vanesssa Mastrosimone
// CSC 2430
// 2/2/18
// Implementation of chess board ADT

#include <iostream>
#include <fstream>
#include <string>
#include "ChessBoard.h"
using namespace std;

//Initializes dimensions of board, false if dimensions too large, true if ok
bool InitBoard(unsigned int numberRows, unsigned int numberColumns, CHESSBOARD& chessboard)
{
    if (numberRows > MAX_SQUARES_PER_SIDE || numberColumns > MAX_SQUARES_PER_SIDE)
        return false;
    chessboard.numberRows = numberRows;
    chessboard.numberColumns = numberColumns;
    return true;
}

//Read values for squares from file, returns false if not enough values or some value(s) are not positive numbers, true for success
bool ReadBoard(istream& fin, CHESSBOARD& chessboard)
{
    string position = "";
    int numPositions = 0;
    for (int r = 0; r < chessboard.numberRows; r++)
    {
        for (int c = 0; c < chessboard.numberColumns; c++)
        {
            //fin >> position;                    //Read in position
            
			if (fin >> position)
			{
				if (!isdigit(position[0]) || position.empty())
					return false;
				else
				{
					int positionAsInt = stoi(position);
					if (positionAsInt < 1)              //Check that position is a positive number
						return false;
					numPositions++;                     //Increment the number of positions
					chessboard.board[r][c] = positionAsInt;  //Store position in the board array    
				}
			}
        } 
       
    }
    if (numPositions != chessboard.numberRows * chessboard.numberColumns)
    {
        return false;
    }
    return true;
}

//Find row and column of a square where value appears. Any square
//is where value appears is ok. Returns true if found, false otherwise
bool FindOnBoard(unsigned int value, int& row, int& col, CHESSBOARD& chessboard){
    for (row = 0; row < chessboard.numberRows; row++)
    {
        for (col = 0; col < chessboard.numberColumns; col++)
        {
            if (value == chessboard.board[row][col])
            {
				row++;
				col++;
                return true;
            }
        }
    }
    return false;
}

//Displays values on chessboard using characters -|* to delineate the squares
void PrintBoard(CHESSBOARD& chessboard)
{
    for (int r = 0; r < chessboard.numberRows; r++)
    {
        //Loop to print the "+--+" pattern
        for (int i = 0; i < chessboard.numberColumns; i++)
        {
            cout << "+--";
        }
        cout << "+" << endl;

        //Loop to print positions
        for (int c = 0; c < chessboard.numberColumns; c++)
        {
            if (chessboard.board[r][c] < 10)
                cout << "| " << chessboard.board[r][c]; //With space
            else
                cout << "|" << chessboard.board[r][c];  //Without space
        }
        cout << "|" << endl;
    }
    //Loop to print "+--+" pattern at the bottom of the board
    for (int i = 0; i < chessboard.numberColumns; i++)
    {
        cout << "+--";
    }
    cout << "+" << endl;
}

