//
//  main.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Cell.h"
#include "Board.h"
#include "NumberSet.h"
#include "Game.h"
using namespace cs31;
using namespace std;
#include <assert.h>

void clearScreen( );
void beep();

int main()
{
    using namespace cs31;
    using namespace std;
    
	//asserts
	cerr << "we doin shit" << endl;
	//tests for numberSet
	NumberSet objject(1, 2, 3, 4, 5, 6, 7, 7);
	NumberSet a(1, 2, 3, 4, 5, 6, 7, 7);
	NumberSet b(1, 2, 3, 4, 5, 6, 7, 7);
	assert(objject.stringify() == "SET-12345677"); //checks that stringiy works
	assert(objject.notFound(8) == true); //checks that not found works when number is not found
	assert(objject.notFound(1) == false); //chekcs that notfound works when number IS found
	assert(objject.notFound(2) == false); //ditto^
	//tests for cell
	Cell q;
	NumberSet d( 1, 1, 1, 1, 1, 1, 1, 1);
	NumberSet e(1, 1, 1, 1, 1, 1, 1, 1);
		//isValueOk tests
	assert(q.isValueOK(0, objject, a, b) == true); //checks if isvalueOk knows that always true when 0
	assert(q.isValueOK(1, objject, a, b) == false); //checks if isvlaueok properly looks if a value is contained in the numbersets passed in
	assert(q.isValueOK(2, objject, d, e) == false); 
		//isImmutable tests

		//setImmutable tets

	//tests for board
		//tests for comleted
	/*Game test;
	test.cheat("479..182.|....83471|.3.7245..|...362..8|.65..871.|2.8..5...|.1.53....|....1..49|7862....."); //makes a board with numbers 1-8 in each row and column?
	//assert(test.completed() == false);
	Game testt;
	testt.cheat("123456789|123456789|123456789|123456789|123456789|123456789|123456789|123456789|123456789");
	//assert(testt.completed() == true);
		//tests for evaluate
	Game test2;
	test2.cheat(".........|123456789|123456789|123456789|123456789|123456789|123456789|123456789|123456789");
	assert(test2.evaluate() == 100);
	Board test3;
	test3.cheat();
	assert(test3.evaluate() == 1);
	cerr << "we done doin shit" << endl;
	//return(0);
	//end asserts*/



	// test code
	NumberSet ns(1, 2, 3, 4, 5, 6, 7, 8);

	assert(ns.notFound(0));
	assert(!ns.notFound(1));
	assert(!ns.notFound(2));
	assert(!ns.notFound(3));
	assert(!ns.notFound(4));
	assert(!ns.notFound(5));
	assert(!ns.notFound(6));
	assert(!ns.notFound(7));
	assert(!ns.notFound(8));
	assert(ns.notFound(9));


	Cell c;

	c.setValue(1);
	assert(c.getValue() == 1);
	assert(!c.isImmutable());
	c.setValue(2);
	c.setImmutable(true);
	assert(c.getValue() == 2);
	assert(c.isImmutable());

	// isValueOK does not check immutability
	assert(c.isValueOK(0, ns, ns, ns));
	assert(!c.isValueOK(1, ns, ns, ns));
	assert(!c.isValueOK(2, ns, ns, ns));
	assert(!c.isValueOK(3, ns, ns, ns));
	assert(!c.isValueOK(4, ns, ns, ns));
	assert(!c.isValueOK(5, ns, ns, ns));
	assert(!c.isValueOK(6, ns, ns, ns));
	assert(!c.isValueOK(7, ns, ns, ns));
	assert(!c.isValueOK(8, ns, ns, ns));
	assert(c.isValueOK(9, ns, ns, ns));

	// isOKToSetValue does check immutability
	assert(!c.isOKToSetValue(0, ns, ns, ns));
	assert(!c.isOKToSetValue(1, ns, ns, ns));
	assert(!c.isOKToSetValue(2, ns, ns, ns));
	assert(!c.isOKToSetValue(3, ns, ns, ns));
	assert(!c.isOKToSetValue(4, ns, ns, ns));
	assert(!c.isOKToSetValue(5, ns, ns, ns));
	assert(!c.isOKToSetValue(6, ns, ns, ns));
	assert(!c.isOKToSetValue(7, ns, ns, ns));
	assert(!c.isOKToSetValue(8, ns, ns, ns));
	assert(!c.isOKToSetValue(9, ns, ns, ns));

	Game g;
	g.cheat("123456789|.........|987321456|456987123|.........|312645978|.........|.........|.........");

	assert(g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
	assert(g.evaluate() == 36);
	assert(!g.completed());
	// all the cheated values are immutable
	assert(!g.acceptValue(0, 1, 1));
	assert(!g.acceptValue(7, 1, 1));
	assert(g.display() == "123|456|789\n...|...|...\n987|321|456\n-----------\n456|987|123\n...|...|...\n312|645|978\n-----------\n...|...|...\n...|...|...\n...|...|...\n");
	assert(g.evaluate() == 36);
	assert(!g.completed());

	cerr << "all tests passed!" << endl;
	return 0;


    clearScreen();
    
    Game game;
    game.buildRandomBoard();

    int row, column, value;
    bool result = true;
    std::string action, message = "(s)et (e)valuate (q)uit: ";
    cerr << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                beep( );  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'S':
            case 's':
                cerr << "row:";
                cin >> row;
                cerr << "column:";
                cin >> column;
                cerr << "value:";
                cin >> value;
                cerr << endl;
                
                result = game.acceptValue( value, row, column );
                if (!result)
                    beep();  // beep
                cerr << game.display( message ) << endl;
                break;
            case 'E':
            case 'e':
                cerr << "evaluate:" << game.evaluate() << endl;
                cerr << game.display( message ) << endl;
                break;
        }
        
    } while( !game.completed()  );
	return (0);
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen and beep implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

/*void clearScreen()
{
	cerr << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}*/
void beep()
{
    cerr << '\a' << endl;
}

#endif

#ifdef __APPLE__

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cerr << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cerr << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

void beep()
{
    // system( "/usr/bin/osascript -e  \"beep 1\"" );
    // printf("%c", 7);
    // system( "echo $'\\a'" );
    // NSBeep();
}

#endif

#if __unix__ // not Microsoft Visual C++, not Mac, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cerr << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cerr << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

void beep()
{
    cerr << '\a' << endl;
}

#endif

