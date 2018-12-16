//
//  Game.h
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <string>

namespace cs31
{
    // a Game represents a playable Sudoku Game
    // it holds a Sudoku board
    // a Board can be stringified which gets called whenever the
    //      Game is printed
    //      0 values stringify as      .
    // for a particular position on the Board, a NumberSet
    //      representing the row, column or bounding box can be
    //      created
    // for testing purposes, a Board can be cheated to allow
    //      for direct testing of any particular Board configuration
    class Game
    {
    public:
        // for interactive play;
        //     pass no arguments to create a random board
        // when cheating:
        //     pass a particular boardstring to force a certain layout
        void buildRandomBoard( std::string boardstring = "" );
        // for interactive play:
        //     print a desired message
        std::string display( std::string message = "" ) const;
        // for interactive play:
        //     attempt to set this Board's cell to the parameter value
        //     return false if the move is illegal
        //     return true if the move was performed
        bool acceptValue( int value, int row, int column );
        // has this Game been completed?
        bool completed() const;
        // call this Game's board evaluation function
        int evaluate() const;
        // force a particular board configuration
        void cheat( std::string boardstring );  
        
    private:
        Board mBoard;          /* this Game's board */
    };
}

#endif
