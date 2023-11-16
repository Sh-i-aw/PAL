#include <stdio.h>
#include <string.h>
/*
* Write a function that takes in a char* holding the address of an array, a size of an element, and the # of element in an array
* The array can either contain chars, ints, or doubles
*
* Using a switch case statement to determine the type of the data inside of that array.
* Once determined, preform the correct casting
* Print each element of the array
*/



// constants used for later switch cases 
#define kChar 1
#define kInt 4
#define kDouble 8

void printInventory(char* prices, int elementSize, int size);

int main(void)
{
	// this is our test arrays 
	char testPhrase[] = "The fox is faster";
	int steps[] = { 12, 30, 35, 39 };
	double prices[] = { 12.2, 56, 38.7, 46.6, 90, 89, 12, 34.4 };

	// how many floats can prices contain 
	//printf("the size of prices array in total is %d\n", sizeof(prices)); // calling sizeof on an array within scope 
	//printf("the size of an individual float is %d\n", sizeof(float));

	// test call for char 
	printInventory(testPhrase, sizeof(char), strlen(testPhrase) + 1);

	// test call for int 
	int intSize = sizeof(steps) / sizeof(int);
	printInventory((char*)steps, sizeof(int), intSize);

	// test call for double 
	int doubleSize = sizeof(prices) / sizeof(double);
	printInventory((char*)prices, sizeof(double), doubleSize);

}




void printInventory(char* array, int elementSize, int size)
{
	// print a message and return if the array address is null


	// declare the temporary pointer variables to be used 


	// switch case statement to determine what type of casting to do, based on element size 


	// print out the information based on the data type using a for loop 


	// print a new line for clarity 

}

