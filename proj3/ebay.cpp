#include <iostream>
#include <assert.h>
#include <string>
#include <cmath>
using namespace std;

//is the string valid
bool isValidEbayListingString(string auctionstring);

//did the string sell
bool listingSold(string auctionstring);
int listingPrice(string auctionstring);
int bidSummation(string auctionstring);
int howMuch(string auctionstring);
//how many watchers were there
int watchers(string auctionstring);

int main()
{
	assert(isValidEbayListingString("L100B50B+50B20")==false);
	assert(listingSold("L100B50B+50B20")==false);
	assert(watchers("L100B50B+50B20") ==-1);
	assert(howMuch("L100B50B+50B20") == -1);
}
//checks if string is valid
bool isValidEbayListingString(string auctionstring)
{
	bool all_letters_good = true;
	bool there_is_an_L = false;
	bool there_is_an_B = false;
	bool there_is_an_W = false;
	bool there_is_an_W_and_no_B = false;
	bool there_is_an_U = false;
	bool there_is_an_number = false;
	bool there_is_a_plus_sign = false;
	bool there_is_a_plus_sign_and_no_b = false;
	bool there_are_more_u_than_W = false;
	bool thereBsWithoutPluses = false;
	bool alreadyBeenTripped = false;
	bool alreadyBeenTripped2 = false;
	bool firstBdoesNotHaveANumber = false;
	int afterBIsNumber;
	int numberOfLs = 0;
	int numberOfWs = 0;
	int numberOfUs = 0;
	int numberOfBs = 0;
	int numberofplus = 0;
	int whereBShouldBe;
	int whereplusShouldBe;
	int whereNumberShouldBe;
	int i = 0;
	for (i; i < auctionstring.length(); i++)
	{
		char z = auctionstring[i];
		int is_number = (z - '0');
		switch (z)
		{
		case ('L'):
		case ('l'):
			numberOfLs += 1;
			if (i == 0)
			{
				there_is_an_L = true;
			}
			break;
		case ('W'):
		case ('w'):
			numberOfWs += 1;
			there_is_an_W = true;
			break;
		case ('U'):
		case ('u'):
			numberOfUs += 1;
			if (there_is_an_W == false)
			{
				there_are_more_u_than_W = true;
			}
			else
			{
				there_is_an_U = true;
			}
			break;
		case ('B'):
		case ('b'):
			numberOfBs += 1;
			whereplusShouldBe = (i + 1);
			whereNumberShouldBe = (i + 1);
			afterBIsNumber = (auctionstring[whereNumberShouldBe] - '0');
			if (alreadyBeenTripped == false)
			{
				if (numberOfBs > 1)
				{
					if (auctionstring[whereplusShouldBe] == '+')
					{
						thereBsWithoutPluses = false;
					}
					else
					{
						alreadyBeenTripped = true;
						thereBsWithoutPluses = true;
					}
				}
				else
				{
					for (int q = 0; q <= 9; q++)
					{
						if (alreadyBeenTripped2 == false)
						{
							if (afterBIsNumber == q)
							{
								alreadyBeenTripped2 = true;
								firstBdoesNotHaveANumber = false;
							}
							else
							{
								firstBdoesNotHaveANumber = true;
							}
						}
					}
				}
			}
			there_is_an_B = true;
			break;
		case ('+'):
			numberofplus += 1;
			whereBShouldBe = (i-1);
			if (numberOfBs > 1)
			{
				if (auctionstring[whereBShouldBe] == 'B')
				{
					there_is_a_plus_sign_and_no_b = false;
				}
				else if (auctionstring[whereBShouldBe] == 'b')
				{
					there_is_a_plus_sign_and_no_b = false;
				}
				else
				{
					there_is_a_plus_sign_and_no_b = true;
				}
			}
			else
			{
				there_is_a_plus_sign_and_no_b = true;
			}
			there_is_a_plus_sign = true;
			break;
		default:
			switch (is_number)
			{
			case (0):
			case (1):
			case (2):
			case (3):
			case (4):
			case (5):
			case (6):
			case (7):
			case (8):
			case (9):
				if (there_is_an_L) 
				{
					there_is_an_number = true;
				}
				break;
			default:
				all_letters_good = false;
				break;
			}
		}
	}
	if (all_letters_good)
	{
		cerr << "All letters are appropriate";
		if (there_is_an_L)
		{
			cerr << " starts with L,";
			if (numberOfLs == 1)
			{
				cerr << " only 1 L,";
				if (there_is_an_W_and_no_B==false)
				{
					cerr << "W comes after B,";
					if (there_is_a_plus_sign_and_no_b == false)
					{
						cerr << " plus signs are all with a B,";
						if (numberOfWs >= numberOfUs)
						{
							cerr << " more not more u than w,";
							if (there_are_more_u_than_W == false)
							{
								if (thereBsWithoutPluses == false)
								{
									cerr << " all B's have correct amount of pluses.";
									if (firstBdoesNotHaveANumber == false)
									{
										cerr << "first b does have a number after it"<<endl;
										return true;
									}
									else if (firstBdoesNotHaveANumber)
									{
										
										cerr << "!first b does not have a number after it";
										return false;
									}

								}
								else if (thereBsWithoutPluses == true)
								{
									cerr << "!B's without pluses";
									return false;
								}
							}
							else if (there_are_more_u_than_W == true)
							{
								cerr << "!more u than W";
								return false;
							}
					
						}
						else if (numberOfWs < numberOfUs)
						{
							cerr << "!!more u than w";
							return false;
						}
					}
					else if (there_is_a_plus_sign_and_no_b == true)
					{
						cerr << "!there are plus signs without b";
						return false;
					}
				}
				else if (there_is_an_W_and_no_B == true)
				{
					cerr << "!there is a W and no B";
					return false;
				}
			}
			else if (numberOfLs != 1)
			{
				cerr << "!doesnt starts with L";
				return false;
			}
		}
		else if (there_is_an_L == false)
		{
			cerr << "!no L" << endl;
			return false;
		}
	}
	else if (all_letters_good == false)
	{
		cerr << "!not all letters good" << endl;
		return false;
	}
	return false;
}
//checks if item sold
bool listingSold(string auctionstring)
{
	if (isValidEbayListingString(auctionstring))
	{
		if (listingPrice(auctionstring) < bidSummation(auctionstring))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
//checks the listing price
int listingPrice(string auctionstring)
{
	int stringLength = auctionstring.length();
	int locationOfFirstB = 0;
	int numberToBeFound = 0;
	int iterationNumber = 0;
	bool makeItStop = false;

	for (int i = 1; i < stringLength; i++)
	{
		if (makeItStop == false)
		{
			if (auctionstring[i] == 'b')
			{
				locationOfFirstB = i;
				makeItStop = true;
			}
			else if (auctionstring[i] == 'B')
			{
				locationOfFirstB = i;
				makeItStop = true;
			}
		}
	}
	if (locationOfFirstB == 0)
	{
		int iterationNumber = 0;
		for (int q = (stringLength-1); q >=1; q--)
		{
			int w = (auctionstring[q]-'0');
			switch (w)
			{
			case (0):
			case (1):
			case (2):
			case (3):
			case (4):
			case (5):
			case (6):
			case (7):
			case (8):
			case (9):
				if (iterationNumber >= 1)
				{
					numberToBeFound += ((auctionstring[q] - '0')*(pow(10, iterationNumber)));
				}
				else
				{
					numberToBeFound += (auctionstring[q] - '0');
				}
				iterationNumber += 1;
				break;
			default:
				break;
			}
		}
		return (numberToBeFound);
	}
	else 
	{
		for (int p = (locationOfFirstB - 1); p >= 1; p--)
		{
			if (iterationNumber >= 1)
			{
				numberToBeFound += ((auctionstring[p] - '0')*(pow(10, iterationNumber)));
			}
			else
			{
				numberToBeFound += (auctionstring[p] - '0');
			}
			iterationNumber += 1;
		}
		return (numberToBeFound);
	}
}
//checks
int howMuch(string auctionstring)
{
	if (isValidEbayListingString(auctionstring))
	{
		if (listingSold(auctionstring))
		{
			return (bidSummation(auctionstring));
		}
		else
		{
			return(0);
		}
	}
	else
	{
		return(-1);
	}
}
//checks the summation of the bids
int bidSummation(string auctionstring)
{
	int stringLength = auctionstring.length();
	int locationOfB;
	int numberToBeFound = 0;
	int numberOfB = 0;
	for (int i = 1; i < stringLength; i++)
	{
		int numberOfNumbers = 0;
		int numberOfNumbersAndPlus = 0;
		int iterationNumber = 0;
		if (auctionstring[i] == 'B' || auctionstring[i] == 'b')
		{
			locationOfB = i;
			numberOfB += 1;
			for (int p = (locationOfB + 1); p < stringLength; p++)
			{
				int isNumber = (auctionstring[p] - '0');
				switch (isNumber)
				{
				case (0):
				case (1):
				case (2):
				case (3):
				case (4):
				case (5):
				case (6):
				case (7):
				case (8):
				case (9):
					numberOfNumbers += 1;
					numberOfNumbersAndPlus+=1;
					break;
				case (-5):
					numberOfNumbersAndPlus += 1;
					break;
				default:
					p = stringLength;
					break;
				}
			}
			if (numberOfB > 1)
			{
				for (int d = (locationOfB + numberOfNumbersAndPlus); d > (locationOfB + 1); d--)
				{
					if (iterationNumber >= 1)
					{
						numberToBeFound += ((auctionstring[d] - '0')*(pow(10, iterationNumber)));
					}
					else
					{
						numberToBeFound += (auctionstring[d] - '0');
					}
					iterationNumber += 1;
				}
			}
			else if (numberOfB == 1)
			{
				for (int d = (locationOfB + numberOfNumbers); d > locationOfB; d--)
				{
					if (iterationNumber >= 1)
					{
						numberToBeFound += ((auctionstring[d] - '0')*(pow(10, iterationNumber)));
					}
					else
					{
						numberToBeFound += (auctionstring[d] - '0');
					}
					iterationNumber += 1;
				}
			}

		}

	}
	return (numberToBeFound);
}
//checks how many watchers when item is sold
int watchers(string auctionstring)
{
	int stringLength = auctionstring.length();
	int numberOfWatchers = 0;

	if (isValidEbayListingString(auctionstring))
	{
		if (listingSold(auctionstring))
		{
			for (int i = 1; i < stringLength; i++)
			{
				if (auctionstring[i] == 'w' || auctionstring[i] == 'W')
				{
					numberOfWatchers += 1;
				}
				else if (auctionstring[i] == 'u' || auctionstring[i] == 'U')
				{
					numberOfWatchers -= 1;
				}
			}
			return (numberOfWatchers);
		}
		else
		{
			return (0);
		}
	}
	else
	{
		return (-1);
	}
}