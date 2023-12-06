
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // required by Visual Studio for fopen().

/*
* 1.Printing menu in main() until user enter 4
* 2.Checking input
* 3.Storing input into struct.
* 3.collectItem()


*/
//global constants:
#define ERROR -1
const int kAddItem = 1;
const int kCheck = 2;
const int kDeleteItem = 3;
const int kExitProgram = 4;
const int kNameLength = 10;
const char* fileName = "Supply file.txt";

//custom data type;
typedef struct product
{
	int productID = 0; //giving a default val;
	char productName[kNameLength] = "";
	double productPrice = 0.0;

}Product;

 //prototypes:
int getInt(int* input);
double getDouble(void);
int collectItem(Product* product);





int main()
{
	const char usageInfo[] = "Press num key in correlation to the options below: \n\t1. add an item to inventory.\n\t2 .check item price.\n\t3. delete item from iventory.\n\t4. complete inventory modification\n\n";
	int option = 0;
	
	Product collectedProduct = { 0 };
	
	while (option != kExitProgram)
	{
		printf(usageInfo);
		
		if (getInt(&option) == ERROR)
		{
			printf("The input should be an integer!\n");
			continue;
		}
		switch (option)
		{
		case kAddItem:
			collectItem(&collectedProduct);
			break;
		case kCheck:
			break;
		case kDeleteItem:
			break;
		case kExitProgram:
			break;
		default:
			printf("Please enter an integer in range 1-4.\n");
			break;
		}



	}
	

	return 0;
}
/*end main*/




int collectItem(Product* product)
{
	//get an item ID;	
	printf("Input an item ID:\n");
	
	getInt(&(product->productID));

	//get an item name;
	printf("Input an item name:\n");

	fgets((product->productName), kNameLength, stdin);

	//get an item price;
	printf("Input an item price:\n");

	product->productPrice = getDouble();

	printf("Item name is: %s;\n item ID is:%d;\n item price is: %lf;\n", product->productName, product->productID, product->productPrice);
	//write each line to the file;


	return 0;

}





int getInt(int* input)
{
	char record[121] = { 0 }; /* record stores the string */
	int status = 0;

	// use fgets to grab keyboard input 
	fgets(record, 121, stdin);

	// use sscanf to check whether there's any number in the user input, place it in int* input if there is 
	if (sscanf(record, "%d", input) != 1)
	{
		/* if the user did not enter a status recognizable by
		* the system, set status to -1 */
		status = ERROR;
	}
	return status;
}


// required by Visual Studio
double getDouble(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can
	improve this code */

	char record[121] = { 0 }; /* record stores the string */
	double number = 0;

	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */

	fgets(record, 121, stdin);
	/* extract the status from the string; sscanf() returns a status
	* corresponding with the status of items it found in the string */


	if (sscanf(record, "%lf", &number) != 1)
	{
		/* if the user did not enter a status recognizable by
		* the system, set status to -1 */
		number = -1;
	}
	return number;
}