//
//  Game.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Game.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>


namespace cs31
{
    
std::string Game::display( std::string message ) const
{
    return( mBoard.stringify() + message );
}

void Game::buildRandomBoard( std::string boardstring )
{
    using namespace std;
    std::string one = "479..182.|....83471|.3.7245..|...362..8|.65..871.|2.8..5...|.1.53....|....1..49|7862.....";
    std::string two = "53..7....|6..195...|.98....6.|8...6...3|4..8.3..1|7...2...6|.6....28.|...419..5|....8..79";
    std::string three = "24...8...|158...436|.6....852|695832...|8.......9|4..9.1.85|..4.8.5..|52...3.48|78.4.5..3";
    std::string four  = ".5..2..3.|2....17.8|4.76.....|.....5...|52.....47|...7.....|.....35.4|3.65....1|.9..7..6.";
    
    std::stringstream ss;
    std::string board = boardstring;
    
    if (boardstring.length() == 0)
    {
        /* initialize random seed: */
        srand ( static_cast<unsigned int>(time(0)) );
    
        /* generate secret number between 1 and 4: */
        int whichboard = rand() % 4 + 1;
        switch( whichboard )
        {
            case 1:
                board = one;
                break;
            case 2:
                board = two;
                break;
            case 3:
                board = three;
                break;
            default:
                board = four;
                break;
        }
    }
    ss << board;

    
    char c;
    int row = 1;
    int column = 1;
    int value = 0;
    
    while (ss.good())
    {
        ss >> c;
        
        value = 0;
        if (c == '|')
            continue;
        if ((c >= '1') && (c <= '9'))
        {
            value = c - '0';
        
        
            mBoard.acceptValue(value, row, column, true);
        }
        
        column = column + 1;
        if (column == 10)
        {
            column = 1;
            row++;
        }
        if (row == 10)
        {
            break;
        }
    }
    
}

bool Game::acceptValue( int value, int row, int column )
{
    // ignore values that are out of range...
    bool result = false;
    if (value >= 0 && value <= 9)
    {
            if (row >= 1 && row <= 9)
            {
                    if (column >=1 && column <=9)
                    {
                        result = mBoard.acceptValue(value, row, column);
                    }
            }
    }
    return( result );
}
    
bool Game::completed() const
{
    return( mBoard.completed() );
}
        
int Game::evaluate() const
{
    return( mBoard.evaluate() );
}
    
void Game::cheat( std::string boardstring )
{
    buildRandomBoard( boardstring );
}

    
}
