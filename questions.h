#ifndef QUESTIONS_H
#define QUESTIONS_H

//libraries 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

enum colors { BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE, GREY }; //color enumeration for font and back color functions 

//various #define constants to be used throughout the program for ease of debug and quick reference  
#define MAXSIZE 100
#define SIZEOFBINSEARCH 10
#define TARGET 7
#define OPTIMUSPRIME 27
#define SIZEOFALPHABET 26
#define SIZEOFINTEGERARRAYCOLUMNS 5
#define SIZEOFINTEGERARRAYROWS 4

//occurrences struct to hold an int and double for charting character frequency in a string 
typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

//function declarations 
void text_color(int i);
void back_color(int i);
char* my_str_n_cat(char* sourcePtr, char* destPtr, int n);
int binarySearch(int values[], int size, int target);
void bubbleSort(char *ptrArr[], int num_of_strings);
int isPalindrome(char* ptrString, int length);
void removeWhitespaces(char *string);
int sumPrimes(unsigned int n);
void maximumOccurrences(char* string, Occurrences Array[SIZEOFALPHABET], int* lvalue, char* cValue);
void max_consecutive_integers(int[SIZEOFINTEGERARRAYROWS][SIZEOFINTEGERARRAYCOLUMNS], int Rows, int Columns, int**, int**);

#endif
