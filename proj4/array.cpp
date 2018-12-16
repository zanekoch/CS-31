#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//initialies all the functions
int findMinimum(const string array[], int n);

int countAllPunctuation(const string array[], int n);

int countFloatingPointValues(const string array[], int   n);

int removeDuplicatedValues(string array[], int  n);

int replaceAll(string array1[], int n, char letterToReplace, char letterToFill);

int shiftRight(string array[], int n, int amount, string   placeholder);


int main()
{
	//test for findMinimum
	string people[6] = { "samwell", "jon", "margaery", "daenerys","a", "tyrion" };
	assert(findMinimum(people, 6) == 4);
	//teste for count all punc
	string data[4] = { "howard-", "ucla\"", "howard!", "ucla" };
	assert(countAllPunctuation(data, 4) == 3);
	//test for count floating
	string dada[4] = { "4.4.3.3", "44.0", "33.098", "33.098a" };
	assert(countFloatingPointValues(dada, 4) == 2);
	//tet for remove duplicate
	string d[4] = { "happy", "days", "happy", "days" };
	assert(removeDuplicatedValues(d, 4) == 2);
	string names[4] = { "joe","joe","sam","jane" };
	assert(removeDuplicatedValues(names, 4) == 1);
	//test for replace all
	string word[4] = { "happy", "days", "are here", "again" };
	assert(replaceAll(word, 4, 'a', 'z') == 5);
	//chech shift right
	string nameroos[5]= { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	assert(shiftRight(people, 5, 3, "foo") == 3);


}

int findMinimum(const string array[], int n)
{
	if (n <= 0)
	{
		return (-1);
	}
	//compares each string to first string to see which is bigger
	else
	{
		int z = 0;
		int locationCounter = 0;
		for (int i = 1; i < n; i++)
		{
			string first = array[z];
			string next = array[i];
			if (first < next)
			{
				locationCounter = z;
			}
			else if (next < first)
			{
				locationCounter = i;
				z = i;
			}
			else  if (first == next)
			{
				locationCounter = z;
			}
		}
		cerr << "location: " << locationCounter << endl;
		return locationCounter;
	}
}
int countAllPunctuation(const string array[], int n)
{
	int punctuationCount = 0;
	string punctuation = ".,!;'-/:?\"";
	int punctuationLength = punctuation.length();
	char punctuation2 = '"';

	if (n <= 0)
		return (-1);
	//references the string puncuation to see if any of the characters in it are in the strings in array
	else
	{
		for (int i = 0; i < n; i++)
		{
			string wordInArray = array[i];
			int lengthOfWordInArray = wordInArray.length();
			for (int j = 0; j < lengthOfWordInArray; j++)
			{
				char characterInWordInArray = wordInArray[j];
				for (int z = 0; z < punctuationLength; z++)
				{
					if (characterInWordInArray == punctuation[z])
					{
						punctuationCount += 1;
					}
				}
			}
		}
	}

	return (punctuationCount);
}
int countFloatingPointValues(const string array[], int   n)
{
	int floatCount = 0;
	if (n <= 0)
	{
		return(-1);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			string wordInArray = array[i];
			int lengthOfWordInArray = wordInArray.length();

			bool currentWordGood = true;
			int numberOfPeriods = 0;
			int numberOfNumbers = 0;
			//uses a swtich statement inside a for loop to iterate over all the items in a string and check if they are of the right type
			for (int j = 0; j < lengthOfWordInArray; j++)
			{
				char characterInWordInArray = wordInArray[j];
				switch (characterInWordInArray)
				{
				case ('1'):
				case ('2'):
				case ('3'):
				case ('4'):
				case ('5'):
				case ('6'):
				case ('7'):
				case ('8'):
				case ('9'):
				case ('0'):
					numberOfNumbers += 1;
					break;
				case ('.'):
					numberOfPeriods += 1;
					break;
				default:
					currentWordGood = false;
				}
			}
			//uses a boolean to make sure the string only contains numbers and periods
			if (currentWordGood)
			{
				if (numberOfPeriods <= 1)
				{
					if (numberOfNumbers >= 1)
					{
						floatCount += 1;
					}
				}
			}

		}
		return (floatCount);
	}
}
int removeDuplicatedValues(string array[], int  n)
{
	if (n <= 0)
	{
		return (-1);
	}
	else
	{
		int numberOfDuplicates = 0;
		for (int i = (n - 1); i >= 0; i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (array[i] == array[j])
				{
					array[i] = "";
					numberOfDuplicates += 1;
					break;
				}
			}
		}
		//shifts the removed duplicates to the right if they are not in the back of the string
		for (int z = 0; z <n; z++)
		{
			int x = (z + 1);
			for (x = (z + 1); x<n; x++)
			{
				if (array[z] == ""&& array[x] != "")
				{
					array[z] = array[x];
					array[x] = "";
					break;
				}
				else
				{
					break;
				}
			}
		}
		for (int q = 0; q < n; q++)
		{
			cerr << array[q] << endl;
		}
		return (numberOfDuplicates);
	}
}
int replaceAll(string array1[], int n, char letterToReplace, char letterToFill)
{
	if (n <= 0)
	{
		return (-1);
	}
	else
	{
		int counter = 0;
		for (int i = 0; i < n; i++)
		{
			string word = array1[i];
			int wordLength = word.length();
			for (int j = 0; j < wordLength; j++)
			{
				char letter = word[j];
				if (letter == letterToReplace)
				{
					//makes sure the original array had actually been changed
					letter = letterToFill;
					word[j] = letter;
					array1[i] = word;
					counter += 1;
				}
			}
		}
		for (int q = 0; q < n; q++)
		{
			cerr << array1[q] << endl;
		}
		return counter;
	}
}
int shiftRight(string array[], int n, int amount, string   placeholder)
{
	if (n <= 0)
	{
		return -1;
	}
	else
	{
		int numberUsed = 0;
		//checks the fringe case where the amount wants to be bigger than n
		if (amount >= n)
		{
			for (int i = 0; i < n; i++)
			{
				array[i] = placeholder;
			}
			numberUsed = n;
		}
		//moves the words over and replaces them with a placeholder
		else if (amount > 0 && amount < n)
		{
			for (int j = 0; j < amount; j++)
			{
				for (int w=(n-1);w>0;w--)
				{
					array[w] = array[w-1];
					array[w-1] = placeholder;
				}
				numberUsed += 1;
			}
		}
		for (int q = 0; q < n; q++)
		{
			cerr << array[q] << endl;
		}
		cerr << "number used: " << numberUsed << endl;
		return (numberUsed);
	}
}







