//
//  Cell.h
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef CELL_H
#define CELL_H

#include "NumberSet.h"

#include <string>

namespace cs31
{
    // a Cell represents one position on a SudokuBoard
    // Each cell can have a value 1-9
    //      0 means the cell's value is yet to be set
    // Each cell can be stringified which gets called whenever the
    //      Game or Board is printed
    //      0 values stringify as      .
    // A cell may be immutable
    //      An immutable cell cannot be changed as the game is played
    //      A cell with a value provided at the start of the game
    //      will be marked as immutable and will not be allowed to be
    //      changed
    class Cell
    {
    public:
        Cell();
        
        void setValue( int value );    /* change this cell's value */
        std::string stringify() const; /* stringify this cell      */
        int  getValue( ) const;        /* return this cell's value */
    
        
        // called before the Board attempts to change a cell's value
        // when true, the Board will change the cell's value to thisvalue
        bool isOKToSetValue( int thisvalue, NumberSet box, NumberSet row, NumberSet column ) const;
        
        // validates that the number is legal with no conflicts in the
        // passed box, row or column.  Does not check immutability and
        // assumes a thisvalue of 0 will be fine anywhere
        /* TODO: CS31 Students must implement this operation */
        bool isValueOK( int thisvalue, NumberSet box, NumberSet row, NumberSet column ) const;
        //does not consider the immutability of the cell, should be considering the different number sets
		//when you call is value ok, you get 3 number sets, look at those to see if is ok
        /* TODO: CS31 Students must implement this operation */
        bool isImmutable() const;      /* can this cell be changed? */
        /* TODO: CS31 Students must implement this operation */
        void setImmutable( bool i );   /* update this cell's immutability */
    private:
        int mValue;      /* cell's value 1-9 or 0 if not yet set */
        bool mImmutable; /* if true, this cell's value cannot be changed */
    };
}

#endif
