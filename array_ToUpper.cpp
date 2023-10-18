#include <stdio.h>
#include <ctype.h>

void capitalize(char myArray[]);

int main(void)
{
	char greeting[] = "Hello";

	capitalize(greeting);

	printf("%s", greeting);
	return 0; 
}

void capitalize(char myArray[])
{
	for (int i = 0; myArray[i] != '\0'; i++)
	{
		// take what's in the ith element of myArray, capitalize it, put the uppercase version back into myArray's ith element 
		myArray[i] = toupper(myArray[i]);
	}
}