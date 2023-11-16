#include <stdio.h>
#include <ctype.h>
#include <string.h>

#pragma warning(disable: 4996)

#define kLen 20 
#define FALSE 0 
#define TRUE 1

int main(void)
{
	char testStr1[] = "Ka, yak";
	char testStr2[] = "Hello World";

	// FIRST, it's easier to determine whether it's a palindrome, when we get rid of spaces and punctuation. 
	// create a copy that does not have spaces or punctuations 


	char copy[kLen] = {};	// create a copy string
	char test[kLen] = {};	// holding the test string

	// comment out either line to test string1 or string2 
	strcpy(test, testStr1);
	//strcpy(test, testStr2);

	int copyLen = 0; // declare an int variable to keep track of the length of the new copy 


	// in a for loop, go through the test string, copy every valid character into the copy string 
	// you would want to make sure they are all lower case, or upper case.



	// add a null terminator at the end of the copy string 
	copy[copyLen] = '\0';

	// a print message to help yourself check whether the copy is good 
	// e.g. "Ka, yak" right now should be "kayak"; 
	printf("copy right now is %s\n", copy);

	int isPalindrome = TRUE; 
	// check each pair of the characters, e.g. 1st with last, 2nd with 2nd last. 
	// if they are not the same, change isPalindrome to FALSE; 

	// print out the final RESULT 
	printf("%s is a palindrome: %s\n", test, isPalindrome == TRUE ? "true" : "false");

	return 0;
}