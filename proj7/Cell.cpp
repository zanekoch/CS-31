//
//  Cell.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Cell.h"

#include <iostream>

namespace cs31
{
    // default Cell constructor
    // since it has no arguments, we can declare an array of Cell's
    Cell::Cell()
    {
        mValue = 0;
        mImmutable = false;
    }

    // mutator method for the member mValue
    void Cell::setValue( int value )
    {
        mValue = value;
    }
    
    // stringify this Cell, turning 0's into    .
    std::string Cell::stringify() const
    {
        std::string s;
        if (mValue == 0)
        {
            s = ".";
        }
        else
        {
            s = s + std::to_string( mValue );
        }
        return( s );
    }
    
    // validates that the number is legal with no conflicts in the
    // passed box, row or column which means thisvalue should not be
    // found in the passed box, row or column
    // immutability should not be taken into consideration here
    // when thisvalue is zero, always return true
    /* TODO: CS31 Students must implement this operation */
    bool Cell::isValueOK( int thisvalue, NumberSet box, NumberSet row, NumberSet column ) const
    {
        // for now...
        //bool result = false;
        //return( result );
		//*zane kode*
		bool valueOK = true;
		if (thisvalue == 0)
		{
			valueOK = true;
		}
		else if (box.notFound(thisvalue))
		{
			if (row.notFound(thisvalue))
			{
				if (column.notFound(thisvalue))
				{
					valueOK = true;
				}
				else
				{
					valueOK = false;
				}
			}
			else
			{
				valueOK = false;
			}

		}
		else
		{
			valueOK = false;
		}
		return (valueOK);
    }

    // called before the Board attempts to change a cell's value
    // when true, the Board will change the cell's value to thisvalue
    bool Cell::isOKToSetValue( int thisvalue, NumberSet box, NumberSet row, NumberSet column ) const
    {
        // thisvalue cannot be found any of the NumberSets passed here
        bool result = isValueOK(thisvalue, box, row, column);
        // in addition, this cell must not be immutable
        if (mImmutable)
        {
            result = false;
        }
        return( result );
    }
    
    // accessor method for member mValue
    int Cell::getValue() const
    {
        return( mValue );
    }
    
    // accessor method for member mImmutable
    /* TODO: CS31 Students must implement this operation */
    bool Cell::isImmutable() const 
    {
        // for now...
        //*zane kode*
		return (mImmutable);
    }
    
    // mutator method for member mImmutable
    /* TODO: CS31 Students must implement this operation */
    void Cell::setImmutable( bool i )
    {
		if (i == true)
		{
			mImmutable = true;
		}
		else if (i == false)
		{
			mImmutable = false;
		}
    }

}
