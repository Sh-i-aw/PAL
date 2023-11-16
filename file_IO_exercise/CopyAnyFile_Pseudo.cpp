#include <stdio.h>
#pragma warning (disable:4996)

// declare a block size 

int main(void)
{
	// declare a file pointer to read from 
	FILE* ifp = NULL;

	// declare a file to write to 
	FILE* ofp = NULL;

	// declare a buffer, this will be used to hold contents that we have read. 
		//? which data type would be the easiest?

	//open input file for binary reading, do proper error checking 


	//open output file for binary writing, do proper error checking



	//loop till end of file. 
	while (!feof(ifp))
	{
		// create a file to check how many bytes did we read. 
		int howManyRead = 0;

		//as long as there's one char read, keep reading

		// put the fread call in an if statement, check against 0 
		
		
			//write to the output file if we have read something in 
				// if we read 0 bytes, return an error 
		
	}

	// file copying should be done at this point 

	// print a line to console declaring it's successful 
	printf("File copied.\n");


	// close both input and output files. error check


	return 0;

}