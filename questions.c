#include "questions.h"

/************************************************************
* Function: text_color(int)
* Date Created: Nov. 10, 2018
* Date Last Modified: Nov. 10, 2018
* Description: Change Text Color
* Input parameters:  Enum Int #
* Returns: -
* Preconditions: -
* Postconditions: -
*************************************************************/
void text_color(i)
{
	printf("%c[%dm", 0x1B, i + 30);
}

/************************************************************
* Function: back_color(int)
* Date Created: Nov. 10, 2018
* Date Last Modified: Nov. 10, 2018
* Description: Change Text Color
* Input parameters:  Enum Int #
* Returns: -
* Preconditions: -
* Postconditions: -
*************************************************************/
void back_color(i)
{
	printf("%c[%dm", 0x1B, i + 40);
}

/************************************************************
* Function: my_str_n_cat(char* sourcePtr, char* destPtr, int n)
* Date Created: Dec. 2, 2018
* Date Last Modified: Dec. 2, 2018
* Description: Adds a source string onto a destination string
* Input parameters:
* Returns: -
* Preconditions: -
* Postconditions: -
*************************************************************/
char* my_str_n_cat(char* sourcePtr, char* destPtr, int n)
{
	int i = 0, count = 0;

	for (int j = 0; destPtr[j] != '\0'; j++)
	{
		count++;
	}

	while (i < n && sourcePtr[i] != '\0')
	{
		destPtr[count + i] = sourcePtr[i];
		i++;
	}
	destPtr[count + i] = '\0'; //insert on a null character when finished (2 nulls?)
	return destPtr;
} //END 1

/************************************************************
* Function: binarySearch(int values[], int size, int target)
* Date Created: Dec. 2, 2018
* Date Last Modified: Dec. 2, 2018
* Description: Searches for a given target value using binary search
* Input parameters:
* Returns: -
* Preconditions: -
* Postconditions: -
*************************************************************/
int binarySearch(int values[], int size, int target)
{
	int mid, left = 1, right = size, target_location = -1, found = 0;

	while (found == 0 && left <= right)
	{
		mid = (left + right) / 2;
		if (target == values[mid])
		{
			found = 1;
			target_location = mid;
		}
		else if (target < values[mid])
			right = (mid - 1);
		else
			left = (mid + 1);
	}
	if (found == 1)
		return target_location;
	else
		return -1;
} //END 2

/************************************************************
* Function: bubbleSort(char *ptrArr[], int num_of_strings)
* Date Created: Dec. 2, 2018
* Date Last Modified: Dec. 2, 2018
* Description: Sorts given strings based on A - Z ordering (utilizes strcmp)
* Input parameters:
* Returns: -
* Preconditions: -
* Postconditions: -
*************************************************************/
void bubbleSort(char *ptrArr[], int num_of_strings)
{
	int unsorted;
	char *temp = NULL;

	unsorted = num_of_strings; //u is the marker for the unsorted section of the list
							   //c = 1; //c is the current marker 
	while (unsorted > 1) //while the unsorted section has more than 1 element 
	{
		int c = 1; //c is the current marker 
		while (c < unsorted) //while c has not passed u
		{
			if (strcmp(ptrArr[c], ptrArr[c - 1]) == 1) //if the item at position c is less than the item to its left exchange these two items - 1 or 0
			{
				temp = ptrArr[c];
				ptrArr[c] = ptrArr[c - 1];
				ptrArr[c - 1] = temp;
			}
			c++; //move c to the right one position
		}
		unsorted--; //move u to the left one position
	} //stop

	  //old code (had issue) -- Z-A ordering
	  //if (strcmp(ptrArr[c - 1], ptrArr[c]) < 0) //if the item at position c is less than the item to its left exchange these two items - 1 or 0
	  //{
	  //	temp = ptrArr[c - 1];
	  //	ptrArr[c - 1] = ptrArr[c];
	  //	ptrArr[c] = temp;
	  //}
	  //c++; //move c to the right one position

} //END 3

/************************************************************
* Function: isPalindrome(char* ptrString, int length)
* Date Created: Dec. 2, 2018
* Date Last Modified: Dec. 2, 2018
* Description: Takes a given string and tests to see if it is a plaindrome (same string front-to-back and back-to-front)
* Input parameters:
* Returns: -
* Preconditions: -
* Postconditions: -
*************************************************************/
int isPalindrome(char* ptrString, int length) //spaces filtered first
{
	if (length <= 1) //(base cases) if the length is 1 or 0 it is a palindrome
		return 1;
	if (ptrString[0] == ptrString[length - 1]) //0 - 9(if 10)
	{
		length = length - 2; //(update) if you meet the first condition, shorten the length and selfreference the function. 
		return isPalindrome(ptrString + 1, length); //self reference 
	}
	else return 0; //return no palindrome
} //END 4

/************************************************************
* Function: removeWhitespaces(char *string)
* Date Created: Dec. 5, 2018
* Date Last Modified: Dec. 5, 2018
* Description: Removes white spaces in a string through pointers
* Input parameters:  char* string
* Returns: String free of whitespaces
* Preconditions: -
* Postconditions: -
* Additional: This code was stringly influenced by code found at https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
*************************************************************/
void removeWhitespaces(char* string) // Function to remove all spaces from a given string 
{
	int count = 0; //count variable to keep track of the whitespaces in the string

	for (int i = 0; string[i]; i++) //walk through the given string
	{
		if (string[i] != ' ') //if the value in the specific cell is not whitespace place it at the 'count++' index
		{
			string[count++] = string[i];
		}
	}
	string[count] = '\0';
} //END SPACE REMOVAL 

/************************************************************
* Function: sumPrimes(unsigned int n)
* Date Created: Dec. 2, 2018
* Date Last Modified: Dec. 2, 2018
* Description: Takes and integer value and sums all the prime numbers compsed in that value from 2 - n(number)
* Input parameters:
* Returns: -
* Preconditions: -
* Postconditions: -
*************************************************************/
int sumPrimes(unsigned int n)
{
	int i = 2; //2 is start 

	if (n <= 1) //(base cases) 0 and 1 are not prime numbers
		return 0;
	else
	{
		while (i < n) //for 2 to n
		{
			if (n % i == 0) //if number is evenly divisible it is not prime and no sum can be added 
				return sumPrimes(n - 1);
			i++;
			//return n + sumPrimes(n - 1); 
		}
		return n + sumPrimes(n - 1); //summing recursive call


									 //for (int i = 2; i <= n; i++) //for 2 to n
									 //{
									 //	if (n % i == 0) //if number is evenly devisable it is not prime and no sum can be added 
									 //		return sumPrimes(n - 1);
									 //}
									 //return n + sumPrimes(n - 1);
	}
} //END 5

/************************************************************
* Function: maximumOccurrences(char** string, Occurrences* Array, int* lvalue, char* cValue)
* Date Created: Dec. 2, 2018
* Date Last Modified: Dec. 2, 2018
* Description:
* Input parameters:
* Returns: -
* Preconditions: -
* Postconditions: -
* Additional: This code was stringly influenced by code found at https://stackoverflow.com/questions/32390379/array-of-structs-incompatible-parameter-types
*************************************************************/
void maximumOccurrences(char* string, Occurrences Array[SIZEOFALPHABET], int* lvalue, char* cValue)
{
	int i = 0, mNum = -1, mIndex = -1, numOfDiffCharacters = 0, calcIndex = 0;

	for (i = 0; i < SIZEOFALPHABET; i++) //initialize array 
	{
		Array[i].num_occurrences = 0;
		Array[i].frequency = 0;
	}
	for (i = 0; i < strlen(string); i++) //find occurrances
	{
		calcIndex = (int)toupper(string[i]) - 65;
		Array[calcIndex].num_occurrences++; //when seen increment the occurence count 
	}
	for (i = 0; i < SIZEOFALPHABET; i++) //find Number of Different Characters
	{
		if (Array[i].num_occurrences > 0)
			numOfDiffCharacters++;
	}
	for (i = 0; i < SIZEOFALPHABET; i++) //for the size check if any specific character is the maximum; set the frequency
	{
		if (mNum < Array[i].num_occurrences) //if max is less than a found occurence set the max to that occurence 
		{
			mNum = Array[i].num_occurrences; 
			mIndex = i; //set the index to that char(int) 
		}
		Array[i].frequency = (double)Array[i].num_occurrences / (double)numOfDiffCharacters; 
	}
	*lvalue = mNum;
	*cValue = (char)mIndex + 65; //cast back to char and return. 
	return;
}

//built in a hurry - not fully tested 
void max_consecutive_integers(int l_intArray[SIZEOFINTEGERARRAYROWS][SIZEOFINTEGERARRAYCOLUMNS], int Rows, int Columns, int** l_maxConsecutiveSequencePtr, int** l_valueOfMaxConsecutiveIntegers)
{
	int masterIndex = 0, countingIndex = 0, maxCount = 0, leaveFlag = 0, countRow = 0, countColumn = 0;

	for (int rowIndex = 0; rowIndex < Rows; rowIndex++)
	{
		for (int colIndex = 0; colIndex < Columns; colIndex++)
		{
			countingIndex = 0;
			countRow = 0;
			countColumn = 0;
			leaveFlag = 0;
			while ((countingIndex < Rows*Columns - (rowIndex*Rows + colIndex)) && (leaveFlag == 0))
			{
				countRow = rowIndex + (countingIndex / Columns);
				countColumn = colIndex + (countingIndex % Columns);
				if (l_intArray[rowIndex][colIndex] == l_intArray[countRow][countColumn])
					countingIndex++;
				else
					leaveFlag = 1;
			}
			if ((countingIndex - masterIndex) > maxCount)
			{
				maxCount = (countingIndex - masterIndex);  //calculate the length of the consecutive sequence
				*l_maxConsecutiveSequencePtr = (int*)&l_intArray[rowIndex][colIndex];  //address to indexed cell
				*l_valueOfMaxConsecutiveIntegers = (int*)&l_intArray[countRow][countColumn];  //value
			}
		}
	}
	return;
}
