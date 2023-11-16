// Writing a program that has an double array. 
// The array has 7 elements, each representing a temperature value, presuming it's for each day of the week 
// Prompt the user 7 times to enter these values & store them in an array. 

// print the collected temperatures out, one on each line. 

#include <stdio.h>
#pragma warning (disable: 4996)

#define kWeekDays 7 

double getDouble(void);
void printTemp(double temperatures[], int size);
void collectTemp(double temperatures[], int size);

int main(void)
{
	// declare an array 
	double temperatures[kWeekDays] = { 0 };


	// we added the sizeof calculation to ensure the functions works with array containing any number of elements.
	int doubleSize = sizeof(double);
	int arraySize = sizeof(temperatures);
	int tempSize = sizeof(temperatures) / sizeof(double);

	printf("The array takes up %d bytes, a double takes up %d bytes, therefore, there are %d elements in the array.\n", arraySize, doubleSize, tempSize);

	collectTemp(temperatures, tempSize);
	printTemp(temperatures, tempSize);

}


void collectTemp(double temperatures[], int size)
{
	double temp = 0.0;
	for (int i = 0; i < size; i++)
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
}

void printTemp(double temperatures[], int size)
{
	for (int i = 0; i < size; i++)
	{
		// if array element was never updated, printout a message indicating user did not put valid value. 
		if (temperatures[i] == 0)
		{
			printf("User did not put a valid temperature input for day %d\n", i + 1);
			continue;
		}

		// other wise print out the recorded temperature for that day 
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
