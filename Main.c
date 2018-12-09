#include "questions.h"

/*********************************************************************************
** Company: WSU - CPTS 121
** Programmer: Jack Coleman
**
** Create Date: 11/27/2018
** Date Last Modified: 12/5/2018
** Design Name: Programming Assignment 8 - Interview Questions
** Project Name: PA8_INTERVIEW_QUESTONS 
** Description:
** Revision:
** Additional Comments: This solution is a collection of prompts ranging from basic sorting 
**                      algorithms to strings manipulation and recursion.  
**
**********************************************************************************/
int main(void)
{
	system("CLS");

	//PROMPT 1 - STRINGCAT ------------------------------------------------------------------------------------------------------------------------------

	text_color(GREEN); //Font color function call 
	printf("MY STRING CAT\n\n"); 
	text_color(WHITE);

	char *sourcePtr = NULL; //set pointers to NULL
	char *destPtr = NULL; //set pointers to NULL

	char source[MAXSIZE] = "racecar"; //string declaration "racecar"
	char destination[MAXSIZE] = "dog"; //string declaration "dog"

	sourcePtr = &source; //setting pointer to the address of "racecar" string
	destPtr = &destination; //setting pointer to the address of "dog" string

	printf("Source string: %s \n", &source); //print statements for strings before function call
	printf("Destination string: %s \n", &destination);

	//string cat function call
	my_str_n_cat(sourcePtr, destPtr, 7); //racecar is 7 integers long

	printf("\nNew destination string: %s \n", &destination); //print for resulting string

	//PROMPT 2 - BINARY SEARCH ------------------------------------------------------------------------------------------------------------------------------

	text_color(GREEN);
	printf("\nBINARY SEARCH\n");
	text_color(WHITE);

	int binSearch[SIZEOFBINSEARCH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target = TARGET, location = 0;

	location = binarySearch(binSearch, SIZEOFBINSEARCH, target); //Array, size, target

	printf("\nTarget location: %d\n", location);

	//PROMPT 3 - BUBBLE SORT ------------------------------------------------------------------------------------------------------------------------------

	//text_color(GREEN);
	//printf("\nBUBBLE SORT\n");
	//text_color(WHITE);

	char *stringPtr = NULL;
	char *stringTest[6] = { "intelligence", "intelligencea", "amazon", "amazon prime", "firefox", "firefoxa" }; //when finished "amazon", "amazon prime", "firefox", "firefoxa", "intelligence", "intelligencea"

																												//stringPtr = &stringTest; 
	bubbleSort(stringTest, 6);

	//PROMPT 4 - PALINDROME ------------------------------------------------------------------------------------------------------------------------------

	text_color(GREEN);
	printf("\nIS PALINDROME\n");
	text_color(WHITE);

	char *sourcePtr2 = NULL;
	char source2[MAXSIZE] = "race car"; //rotor, 5 //race car, 7 

										//filter whitespaces here
	removeWhitespaces(source2);

	sourcePtr2 = &source2;

	if (isPalindrome(sourcePtr2, 7) == 1) //a pointer to a string and its length
		printf("\n%s is a palindrome.\n", &source2);
	else
		printf("\n%s is not a palindrome.\n", &source2);

	//PROMPT 5 - SUM OF PRIMES ------------------------------------------------------------------------------------------------------------------------------

	text_color(GREEN);
	printf("\nSUM PRIME NUMBERS\n");
	text_color(WHITE);

	unsigned int localprime = OPTIMUSPRIME, sum = 0;

	sum = sumPrimes(localprime);

	printf("Sum of primes in %d is %d.\n", localprime, sum);

	////PROMPT 6 -- MAXIMUM OCCURRENCES ------------------------------------------------------------------------------------------------------------------------------

	text_color(GREEN);
	printf("\nMAXIMUM OCCURRENCES\n");
	text_color(WHITE);

	char *sourcePtr3 = NULL;
	char source3[MAXSIZE] = "dell latitude"; //titties
	char ch = 0; //found character variable
	int value = 0; //number of time found 
	Occurrences myArr[SIZEOFALPHABET];   //= malloc(256 * sizeof(Occurrences)); //using malloc correctly/good use of malloc?
	struct Occurrences *myArrPtr;

	myArrPtr = myArr;
	sourcePtr3 = &source3;

	printf("\nIn the string \"%s\"", sourcePtr3);

	removeWhitespaces(sourcePtr3); //remove any whitespace

	maximumOccurrences(sourcePtr3, myArrPtr, &value, &ch); //function call 

	printf(" the character '%c' occures %d times.\n\n", ch, value);


	//PROMPT 7 -- MAXIMUM CONSECUTIVE INTEGERS ---------------------------------------------------------------------------------------------------------

	text_color(GREEN);
	printf("\nMAXIMUM CONSECUTIVE INTEGERS\n");
	text_color(WHITE);

	signed int intArray[SIZEOFINTEGERARRAYROWS][SIZEOFINTEGERARRAYCOLUMNS] = {
		{ -5, 6, 0, 2, 2 },
		{ 2, 2, 2, 9, 3 },
		{ 3, 3, 2, 1, -8 },
		{ 7, -2, 6, 0, 4 }
	};
	int *maxConsecutiveSequencePtr = &intArray[0][0];
	int *valueOfMaxConsecutiveIntegers = &intArray[0][0];

	max_consecutive_integers(intArray, SIZEOFINTEGERARRAYROWS, SIZEOFINTEGERARRAYCOLUMNS, &maxConsecutiveSequencePtr, &valueOfMaxConsecutiveIntegers);

	printf("\nIn the Two-Dimensional array of integers, the longest consecutive sequence of values is located at: \nAddress: %d\nOf an integer-value of %d\nSequence length is %d numbers long.\n\n"
		, &maxConsecutiveSequencePtr
		, (int)*maxConsecutiveSequencePtr
		, (((int)&maxConsecutiveSequencePtr - (int)&valueOfMaxConsecutiveIntegers - 1) / 2));

	// DONE ---------------------------------------------------------------------------------------------------------------------------------------------
	system("pause");
	return 0;
