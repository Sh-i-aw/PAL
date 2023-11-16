#include <stdio.h>
#pragma warning (disable:4996)

#define kBlockSize 1000 
#define ERROR -1 

int main(int argc, char* argv[])
{ 
	FILE* ifp = NULL;
	FILE* ofp = NULL;
	char memBlock[kBlockSize] = { 0 };

	if (argc != 3)
	{
		printf("incorrect amount of arguments.\n"); 
		printf("please input: programName File_Source Copy_File_Destination"); 
		return ERROR; 
	}

	//open input file 
	ifp = fopen(argv[1], "rb");
	if (ifp == NULL)
	{
		printf("Can't open input file\n");
		return -1;
	}

	//open output file 
	ofp = fopen(argv[2], "wb");
	if (ofp == NULL)
	{
		printf("can't open output file\n");
		if (fclose(ifp) != 0)
		{
			printf("Error: can't close input file\n");
		}
		return -1;
	}


	//loop to copy content 
	while (!feof(ifp))
	{
		int howManyRead = 0;
		//as long as there's one char read, keep going
		if ((howManyRead = fread(memBlock, 1, kBlockSize, ifp)) != 0)
		{
			//write to the output file 
			if (fwrite(memBlock, sizeof(char), howManyRead, ofp) == 0)
			{
				printf("Error writing to output file\n");
				break;
			}
		}
	}

	printf("File copied.\n");

	if (fclose(ifp) != 0)
	{
		printf("error closing input file\n");
	}
	if (fclose(ofp) != 0)
	{
		printf("error closing output file\n");
	}

	return 0;

}