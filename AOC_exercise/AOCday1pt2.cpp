#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

#define kRank 3

#define kBuf 10
#define kErrOpen -1; 

void bubble(int list[]);

int main(void)
{
	FILE* fp = fopen("calorie.txt", "r");
	if (fp == NULL)
	{
		printf("can't open calorie.txt\n");
		return kErrOpen;
	}

	//variable for tracking top calorie sums, and calories on each elf
	int top[kRank] = { 0, 0, 0 };
	int currentCal = 0;


	while (!feof(fp))
	{
		//buffer for each item's calorie 
		char cal[kBuf] = { 0 };

		//get one caloric number
		if (fgets(cal, kBuf, fp) != NULL)
		{
			int len = (int)strlen(cal);
			//if line is empty, set currentCal to zero, go to next line
			if (len == 1)
			{
				//if currentCal is bigger than the 3rd value, assign as such, send to bubble sort function
				if (currentCal > top[kRank - 1])
				{
					top[kRank - 1] = currentCal;
					bubble(top);
				}

				// reset the running total variable 
				currentCal = 0;
				continue;
			}
			else
			{
				currentCal += atoi(cal);
			}
		}

	}

	printf("most amount of calorie on one elf is: %d, %d, %d", top[0], top[1], top[2]);

	if (fclose(fp) != 0)
	{
		printf("Can't close calorie.txt\n");
		return -1;
	}

	return 0;
}




void bubble(int list[])
{
	// loop from the highest index ( lowest rank ) upwards.
	// compare each element with the one higher than it 
		// e.g. 3rd with 2nd, if 3rd is bigger, swap 
	for (int i = kRank - 1; i > 0; i--)
	{
		if (list[i] > list[i - 1])
		{
			// create a temporary variable to hold the value to be swapped 
			int temp = list[i];
			list[i] = list[i - 1];
			list[i - 1] = temp;
		}
	}
}