// Lab 4: King's Tour
// Purpose: to practice working with 2-D arrays by writing a program that determines 
// whether the values stored in a m * n "chess board" correspond to the positions 1 to mn
// of a "King's Tour" around the "chess board"
// Vanesssa Mastrosimone
// CSC 2430
// 2/2/18

#include <iostream>
#include <fstream>
#include <string>
#include "ChessBoard.h"

using namespace std;

int main() 
{
    ifstream fin;
    string fileName;
    cout << "File name: ";
    cin >> fileName;
    fin.open(fileName);

    //Error message
    if (fin.fail())
    {
        cerr << "Can't open '" << fileName << "'" << endl;
        exit(1);
    }

    CHESSBOARD chessboard;

    //Read the board dimensions
    string rows, columns;
    fin >> rows >> columns;
    //Convert from string to int
    unsigned int numRows = stoi(rows);
    unsigned int numCols = stoi(columns);
    int row = 0;
    int col = 0;

    //Call the ADT to initialize the board
    InitBoard(numRows, numCols, chessboard);

    //Call ADT to read in the positions from the file and store them in the ADT
    if (ReadBoard(fin, chessboard) == false)
        cout << "Invalid board positions";

    //Call ADT to display the board it has read
    cout << "Positions on Chess Board" << endl;
    PrintBoard(chessboard);

    //Make queries on the ADT to find the location of each position from 1 to mn 
    //and verify that moving from position "p" to "p+1" can be done using a legal move for a king chess board piece
    cout << "\nMoving the king from square to square..." << endl;

    int previousRow;
    int previousColumn;
    for (int i = 1; i <= numRows*numCols; i++)
    {
        if (FindOnBoard(i, row, col, chessboard)) //If true
        { 
            if (i == 1)
            {
                cout << "Position " << i << ": start at (" << row << ", " << col << ")" << endl;
                previousRow = row;
                previousColumn = col;
            }    
            if (abs(previousRow-row) > 1 || abs(previousColumn-col) > 1)
            {
                cout << "Position " << i << ": can't jump to (" << row << ", " << col << ")" << endl;
                cout << "Does not represent a king's tour" << endl;
                return 0;
            }  
            if (i > 1)
            {
                cout << "Position " << i << ": jump to row (" << row << ", " << col << ")" << endl;
                previousRow = row;
                previousColumn = col;
            } 
             

        }
        else
            cerr << "Can't find on board" << endl;
             
    }
    cout << "Represents a king's tour" << endl;

    return 0;
}