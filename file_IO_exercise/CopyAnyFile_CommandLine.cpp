#include <stdio.h>
#pragma warning (disable:4996)

#define kBlockSize 1000 
#define ERROR -1 



int main(int argc, char* argv[])
{
	// error check if user has input correct amount of argument 
	if (argc != 3)
	{
		printf("Incorrect amount of arguments.\n"); 
		printf("Correct usage: command copy_source copy_destination");
		return ERROR; 
	}
	
	// declare a file pointer to read from 
	FILE* ifp = NULL;

	// declare a file to write to 
	FILE* ofp = NULL;

	// declare a buffer, this will be used to hold contents that we have read. 
		//? which data type would be the easiest?
	char buffer[100] = { 0 };
	//open input file for binary reading, do proper error checking 
	ifp = fopen(argv[1], "rb");

	if (ifp == NULL)
	{
		printf("Opening ERROR");
		return -1;
	}


	//open output file for binary writing, do proper error checking
	ofp = fopen(argv[2], "wb");

	if (ofp == NULL)
	{
		printf("Opening ERROR");
		return -1;
	}

	//loop till end of file. 
	while (!feof(ifp))  //?
	{
		// create a file to check how many bytes did we read. 
		int howManyRead = 0;

		//as long as there's one char read, keep reading

		// put the fread call in an if statement, check against 0 !
		if ((howManyRead = fread(buffer, sizeof(char), 100, ifp)) != 0)
		{
			//write to the output file if we have read something in 
			// if we read 0 bytes, return an error 
			if (fwrite(buffer, sizeof(char), howManyRead, ofp) == 0)
			{
				printf("Write ERROR");
				break;
			}

		}

	}

	// print a line to console declaring it's successful 
	printf("File copied.\n");


	// close both input and output files. error check
	if (fclose(ifp) != 0)
	{
		printf("ERROR, could not close file ifp");

	}


	if (fclose(ofp) != 0)
	{
		printf("ERROR, could not close file ofp");

	}

	return 0;

}
//int main(int argc, char* argv[])
//{ 
//	FILE* ifp = NULL;
//	FILE* ofp = NULL;
//	char memBlock[kBlockSize] = { 0 };
//
//	if (argc != 3)
//	{
//		printf("incorrect amount of arguments.\n"); 
//		printf("please input: programName File_Source Copy_File_Destination"); 
//		return ERROR; 
//	}
//
//	//open input file 
//	ifp = fopen(argv[1], "rb");
//	if (ifp == NULL)
//	{
//		printf("Can't open input file\n");
//		return -1;
//	}
//
//	//open output file 
//	ofp = fopen(argv[2], "wb");
//	if (ofp == NULL)
//	{
//		printf("can't open output file\n");
//		if (fclose(ifp) != 0)
//		{
//			printf("Error: can't close input file\n");
//		}
//		return -1;
//	}
//
//
//	//loop to copy content 
//	while (!feof(ifp))
//	{
//		int howManyRead = 0;
//		//as long as there's one char read, keep going
//		if ((howManyRead = fread(memBlock, 1, kBlockSize, ifp)) != 0)
//		{
//			//write to the output file 
//			if (fwrite(memBlock, sizeof(char), howManyRead, ofp) == 0)
//			{
//				printf("Error writing to output file\n");
//				break;
//			}
//		}
//	}
//
//	printf("File copied.\n");
//
//	if (fclose(ifp) != 0)
//	{
//		printf("error closing input file\n");
//	}
//	if (fclose(ofp) != 0)
//	{
//		printf("error closing output file\n");
//	}
//
//	return 0;
//
//}