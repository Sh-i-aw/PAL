// Writing a program that has an double array. 
// The array has 7 elements, each representing a temperature value, presuming it's for each day of the week 
// Prompt the user 7 times to enter these values & store them in an array. 

// print the collected temperatures out, one on each line. 

#include <stdio.h>
#pragma warning (disable: 4996)

#define kWeekDays 7 

double getDouble(void);

int main(void)
{
	// declare an array 
	double temperatures[kWeekDays] = { 0 };
	double temp = 0; 

	// prompt user 7 times, collect a double value from them, and place it in the array. 
	for (int i = 0; i < kWeekDays; ++i)
	{
		//prompt user 
		printf("Please input the temperature for day %d: ", i + 1);
		temp = getDouble();

		// getDouble returns -1 if there is no number found 
		// in this case, I left the array element unchanged. 
		if (temp != -1)
		{
			temperatures[i] = temp;
		}
	}

	// print out the collected temperature values to 1 decimal accuracy 
	printf("The temperature of the week is as follows: \n");
	for (int i = 0; i < kWeekDays; ++i)
	{

		// if array element was never updated, printout a message indicating user did not put valid value. 
		if (temperatures[i] == 0)
		{
			printf("User did not put a valid temperature input for day %d\n", i + 1);
			continue;
		}
		printf("\tDay %d: %.1f C\n", i + 1, temperatures[i]);
	}

}



double getDouble(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can
	improve this code */

	char record[121] = { 0 }; /* record stores the string */
	double number = 0;

	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */

	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */


	if (sscanf(record, "%lf", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}
