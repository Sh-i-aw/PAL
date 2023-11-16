/*
* Write a function, that, when given a string, it will replace a certain character with another character 
* 
* name the function replace, give it 3 parameters: 
* 1. char array that you will perform this action on 
* 2. the char that you wish to replace 
* 3. the char that you want to inject / replace the original with 
* 
* e.g. if I have a sample string containing: 
* char sample[] = "get grocery"
* and I call: replace(sample, 'e', 'E'); 
* sample will become:  "gEt grocEry"
* 
* 
* Write a second function, give it two char arrays, one original, one hold the reversed version. 
* 
* When I call this function, the function should put the reversed version of original, into the second char array. 
* 
* name stringReverse, give 2 parameters 
* 1. original: represents the original sentence 
* 2. reversed: holds the reversed sentence 
*/

#include <stdio.h>
#include <string.h>

void replace(char input[], char replace, char inject);
void stringReverse(char input[], char reversed[]);

int main(void)
{
	char sample[] = "get grocery";
	int length = (int)strlen(sample);

	char reversed[12] = { 0 };

	replace(sample, 'e', '3'); 
	stringReverse(sample, reversed);

	printf("string after calling replace: %s\n\n", sample);
	printf("string after calling reverse: %s\n\n", reversed);
}



void stringReverse(char input[], char reversed[])
{
	// traverse through each element of input, and put it in the reversed array 
	// index 0 - (length - 1) 
	// input 0 - reverse 9 
	// input 1 - reverse 8 
	// input 2 - reverse 7 

	int length = (int)strlen(input);
	for (int i = 0; input[i] != '\0'; ++i)
	{
		// placing it in the reversed array, at the opposite location 
		reversed[length - i - 1] = input[i];
	}
	// put null terminator at the end of the sentence 
	reversed[length] = '\0';

}


void replace(char input[], char replace, char inject)
{

	// traverse through each element of this char array 
	for (int i = 0; input[i] != '\0'; ++i)
	{
		// check whether the replace char exist 
		if (input[i] == replace)
		{
			// if it exists, replace it with the inject char 
			input[i] = inject;
		}
	}
}
