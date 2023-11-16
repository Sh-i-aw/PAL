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


	char copy[kLen] = {};	// create a copy string
	char test[kLen] = {};	// holding the test string
	
	// comment out either line to test string1 or string2
	// strcpy(test, testStr1); 
	strcpy(test, testStr2);

	int copyLen = 0; // declare an int variable to 
	for (int i = 0; test[i] != '\0'; i++)
	{
		if (isspace(test[i]) || ispunct(test[i]))
		{
			continue;
		}
		copy[copyLen] = tolower(test[i]);
		copyLen++; 
	}
	copy[copyLen] = '\0';

	printf("copy right now is %s\n", copy);

	int start = 0; 
	int end = copyLen - 1; 
	int isPalindrome = TRUE;
	while (start <= end)
	{
		if (copy[start] != copy[end])
		{
			isPalindrome = FALSE; 
		}
		start++; 
		end--; 
	}

	printf("%s is a palindrome: %s\n", test, isPalindrome == TRUE ? "true" : "false"); 
	
	return 0;
}

//char testStr1[] = "Ka, yak";
//char testStr2[] = "Hello World";
//char testStr3[] = "ra  dar";
//char testStr4[] = "de,ified";
//
//
//char copy[kLen] = {};	// create a copy string
//char test[kLen] = {};	// holding the test string
//strcpy(test, testStr1);
//
//int copyLen = 0;
//for (int i = 0; test[i] != '\0'; i++)
//{
//	if (isspace(test[i]) || ispunct(test[i]))
//	{
//		continue;
//	}
//	copy[copyLen] = tolower(test[i]);
//	copyLen++;
//}
//copy[copyLen] = '\0';
//
//printf("copy right now is %s\n", copy);
//
//int start = 0;
//int end = copyLen - 1;
//int isPalindrome = TRUE;
//while (start <= end)
//{
//	if (copy[start] != copy[end])
//	{
//		isPalindrome = FALSE;
//	}
//	start++;
//	end--;
//}
//
//printf("%s is a palindrome: %s\n", test, isPalindrome == TRUE ? "true" : "false");
//
//return 0;