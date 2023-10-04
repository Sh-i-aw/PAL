#include <stdio.h>

// write a do-while loop, that prints out "taking one step\n" as long as variable 'wantToWalk' is true 
// every 10 steps taken, the program will ask, do you want to continue? 
// print out the total step number when program ends. 

// **current code has no user input validation 

#pragma warning (disable:4996)

int getInt(void);

int main(void)
{
	int wantToWalk = 1; // assume we want to walk, set it to 1 cause there's no boolean in C 
	int stepCounter = 0; // have another variable to keep count of the steps 

	do
	{
		printf("Taking one step\n");	// Note, even though wantToWalk is 0, program still outputs one step, try out what happens by changing value in line 15
		stepCounter++; 
	
		// every 50 steps, prompt the user "Do you really want to keep walking?!"
		if (stepCounter % 50 == 0 && stepCounter > 0)
		{
			printf("Do you really want to keep walking?\n 1 to continue, 0 to quit\n");
			wantToWalk = getInt();
			if (wantToWalk == 0)
			{
				break;	//  This jumps right out of the loop body, use debugger to check which line is executed next 
			}
		}
		 
		// every 10 steps taken, prompt user if they want to keep walking 
		if (stepCounter % 10 == 0)
		{
			printf("Do you want to keep walking?\n 1 to continue, 0 to quit\n");
			wantToWalk = getInt();
		}
	} while (wantToWalk == 1);

	return 0; 
}



int getInt(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can
	improve this code */

	char record[121] = { 0 }; /* record stores the string */
	int number = 0;

	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */

	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */


	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}