#include <stdio.h>
#include <string.h>
int main(void)
{
	// ----------  question 1 --------------
	int b = 0; 

	// when declaring a pointer, put asterisk * after data type 
	// when retrieving the address of a variable, put & before the data type 
	int* pointerToB = &b;

	printf("b's address is %p, it can also be accessed with %p.\n", pointerToB, &b);

	// To deference (get the value at an address), we put an asterisk in front of a pointer variable 
	printf("the value stored at address pointerToB is: %d\n", *pointerToB);


	// ---------- question 2 & 3 --------------

	char exitMsg[5] = { "Ciao" };

	int msgLength = (int)strlen(exitMsg);
	printf("the length of exitMsg is %d\n", msgLength);

	// ---------- question 4 --------------

	int x = 4;
	double y = 12.44;

	int* pInt = &x;
	double* pDouble = &y; 

	// ALT: alternatively we can say: 
	// printf("address of integer x is %p", &x);
	printf("address of integer x is %p\n", pInt);

	printf("address of double y is %p\n", pDouble);


	// --------- question 5 ---------------
	char dest[5] = "ayo";
	char append[6] = "hoho";

	// hover over the function to see how strcat behaves 
	strcat(dest, append);
	printf("after trying to put append into dest, we get %s", dest);


}