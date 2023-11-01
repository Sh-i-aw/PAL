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
	// for demonstration purposes, note array here is always just a pointer variable, 4 if on 32-bit system, 8 if on 64-bit system 
	printf("size of array here is %d, note this is only the size of the pointer variable, cause array is out of scope\n", (int)sizeof(array)); 

	// guard statement against an empty pointer being passed in
	if (array == NULL)
	{
		printf("address of array invalid\n"); 
		return; 
	}

	// declare the temporary pointer variables to be used 
	int* pInt = NULL; 
	double* pDouble = NULL; 

	// switch case statement to determine what type of casting to do 
	switch (elementSize)
	{
	case kChar: 
		// do nothing as the pointer is already a char pointer type 
		break;

	case kInt: 
		// cast the pointer to the appropriate type & print each element 
		pInt = (int*)array;
		break;

	case kDouble: 
		// cast the pointer to the appropriate type & print each element 
		pDouble = (double*)array; 
		break;

	default: 
		printf("The given data type was not a char, int or double, can't process\n");
		return;
	}



	for (int i = 0; i < size; i++)
	{
		// if pDouble isn't NULL, print values out as double 
		if (pDouble != NULL)
		{
			printf("%lf\n", *(pDouble + i)); 
		}
		// if pInt isn't NULL, print value out as int 
		else if (pInt != NULL)
		{
			printf("%d\n", *(pInt + i)); 
		}
		// else print it out as char 
		else
		{
			printf("%c", *(array + i));
		}
	}

	// print a new line for clarity 
	printf("\n");
}

