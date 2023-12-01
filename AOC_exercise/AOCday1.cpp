#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

#define kInputText "calorie.txt" 
#define kBuf 10 

#define kOpenErr -1 


int main(void)
{
	FILE* ifp = fopen(kInputText, "r");

	if (ifp == NULL)
	{
		printf("error opening input file\n");
		return kOpenErr;
	}

	char buffer[kBuf] = { 0 };

	int maxTotal = 0;
	int runningTotal = 0;

	while (!feof(ifp)) // as long as we are not at the end. 
	{
		if (fgets(buffer, kBuf, ifp) != NULL)
		{
			// if we have reached a new line 
			if (strcmp(buffer, "\n") == 0)
			{
				// check if the current sum has exceeded the highest sum, reassign max sum if so 
				if (runningTotal > maxTotal)
				{
					maxTotal = runningTotal;
				}
				// reset running total for next section
				runningTotal = 0;
			}
			else
			{
				runningTotal += atoi(buffer);
			}
		}
	}

	printf("the highest sum out of all sections is: %d\n", maxTotal);

	if (fclose(ifp) != 0)
	{
		printf("Error: cannot close file %s.\n", kInputText);
	}

	return 0;
}