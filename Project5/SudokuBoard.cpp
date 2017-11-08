// Author:
// Uniqname:
// Date:
// GSI:
// Description

#include "ioutil.h"
#include "SudokuBoard.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/********
 * Code *
 ********/


void SudokuBoard::printBoard()
{
    // print the numbers at the top of the board
    cout << ' ';
    for(int y = 0; y < BOARD_SIZE; y ++)
    {
        if (y < 9)
            cout << "| " << SetColor(INDEX_COLOR) << y + 1 << ' ';
        else
            cout << "| " << SetColor(INDEX_COLOR) << y + 1 ;
    }
    cout << '|' << endl;
    
    for(int x = 0; x < BOARD_SIZE; x ++)
    {
        cout << '-';
        
        // print a line above the cell
        for(int y = 0; y < BOARD_SIZE; y ++)
        {
            if(x % BOARD_N == 0)
            {
                cout << SetColor(WHITE, BACK) << "+---";
            }
            else
            {
                if(y % BOARD_N == 0)
                {
                    cout << SetColor(WHITE, BACK) << '+';
                }
                else
                {
                    cout << '+';
                }
                
                cout << "---";
            }
        }
        
        cout << SetColor(WHITE, BACK) << '+' << '-' << endl;
        cout << SetColor(INDEX_COLOR) << char(x + 'A');
        
        // print the contents of the cell
        for(int y = 0; y < BOARD_SIZE; y ++)
        {
            if(y % BOARD_N == 0)
            {
                cout << SetColor(WHITE, BACK) << '|';
            }
            else
            {
                cout << '|';
            }
            if(board[x][y].permanent)
            {
                cout << ' ' << SetColor(PERMANENT_NUMBER_COLOR) << board[x][y].number;
            }
            else
            {
                cout << ' ';
                if (board[x][y].number == 0) {
                    cout << ' ';
                } else {
                    cout << board[x][y].number;
                }
            }
            if (board[x][y].number < 10) {
                cout << ' ';
            }
        }
        cout << SetColor(WHITE, BACK) << '|' << SetColor(INDEX_COLOR) << char(x + 'A') << endl;
    }
    
    cout << '-';
    
    // print the final line
    for(int y = 0; y < BOARD_SIZE; y ++)
    {
        cout << SetColor(WHITE, BACK) << "+---";
    }
    cout << SetColor(WHITE, BACK) << '+' << '-' << endl;
    
    // print the numbers at the bottom of the board
    cout << ' ';
    for(int y = 0; y < BOARD_SIZE; y ++)
    {
        if (y < 9)
            cout << "| " << SetColor(INDEX_COLOR) << y + 1 << ' ';
        else
            cout << "| " << SetColor(INDEX_COLOR) << y + 1 ;
    }
    cout << '|' << endl << endl;
}
