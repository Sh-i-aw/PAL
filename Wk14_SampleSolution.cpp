#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable: 4996)

#define ERROR -1
#define SUCCESS 0 
#define kNotFound 2

#define kFileErr -2

const int kAddItem = 1; 
const int kCheck = 2; 
const int kDelete = 3; 
const int kExit = 4; 

const char inventoryFile[] = "stock.txt";

const int kName = 10; 
const int kBuf = 30;
const int kText = 50; 

typedef struct Item
{
	int productID = 0; 
	char name[kName] = "";
	double price = 0.0; 
} Item; 

// main methods
int collectItem(Item* item);
int checkPrice(char* product, double* price);
int deleteProduct(char* product);

// helper methods
int parseItem(char* line, Item* item);
int isNameTooBig(char* input);
int getInt(int* input);
double getDouble(void);
void clearNewLine(char* input);

int main(void)
{
	const char usageInfo[] = 
		"Press num key in correlation to the options below: \n\t1. add an item to inventory.\n\t2 .check item price.\n\t3. delete item from iventory.\n\t4. complete inventory modification\n\n"; 
	
	int option = 0; 
	Item temp; 
	while (option != 4)
	{
		printf(usageInfo); 

		int result = getInt(&option); 

		if (result == ERROR)
		{
			printf("Please input an integer between 1 and 4.\n\n");
			continue; 
		}

		char buffer[kBuf] = { 0 };
		char searchProduct[kName] = { 0 }; 
		double queryPrice = 0.0;

		switch (option)
		{
		case kAddItem: 
			collectItem(&temp); 
			printf("The item collected: %d, %s, %.2lf\n\n", temp.productID, temp.name, temp.price);
			break; 
		case kCheck: 
			//prompt user for item name: 
			printf("\nWhich item do you want to check the price for?\n"); 
			fgets(buffer, kBuf, stdin); 
	 
			// if name is too big, don't search, else search whether it's there 
			if (isNameTooBig(buffer) == ERROR)	//inform user name is too big
			{
				printf("\nName Entered is too large, please try again.\n"); 
				continue; 
			}

			strcpy(searchProduct, buffer); 
			result = checkPrice(searchProduct, &queryPrice);

			// if item is there, return price, else notice user it is not found
			if (result == SUCCESS)
			{
				printf("\n%s is found, its price is: $%.2lf.\n\n", searchProduct, queryPrice);
			}
			else
			{
				printf("\nProduct %s is not found.\n\n", buffer);
			}

			break; 
		case kDelete:
			// prompt user for item name (to delete) 
			printf("\nWhich item do you want to delete from stock?\n");
			fgets(buffer, kBuf, stdin);

			// if name is too big, don't search, else search whether it's there 
			if (isNameTooBig(buffer) == ERROR)	//inform user name is too big
			{
				printf("\nName Entered is too large, please try again.\n");
				continue; 
			}
		
			strcpy(searchProduct, buffer);
			result = deleteProduct(searchProduct);	// attempt to delete the item
			

			if (result == SUCCESS)
			{
				printf("\n%s is successfully deleted from stock.\n\n", searchProduct);
			}
			else if (result == kFileErr)
			{
				printf("\nError occurred while interacting with inventory file\n\n"); 
			}
			else if (result == kNotFound)
			{
				printf("\nCannot find the product %s for deletion.\n\n", searchProduct); 
			}
			break; 
		case kExit: 
			printf("Inventory modification complete, exiting..."); 
			break; 
		default: 
			printf("Option unrecognized, please try again.\n\n"); 
			break; 
		}
	}
}


/*
* Check whether newline character from fgets has been overwritten
*/

int isNameTooBig(char* input)
{
	int result = SUCCESS;	//create a return value

	// clear new line and check name length
	clearNewLine(input);

	int length = (int)strlen(input);
	if (length > kName - 1)
	{
		result = ERROR;
	}
	return result;
}



/*
* Collect user input for an item, and write it to the inventory file
* NOTE: VERY MINIMAL ERROR HANDLING 
*/
int collectItem(Item* item)
{
	printf("Please enter the item's productID: ");
	int tempID = 0;
	if (getInt(&tempID) != ERROR)
	{
		item->productID = tempID;
	}

	printf("Please enter the item's name: ");
	fgets(item->name, kName, stdin);
	clearNewLine(item->name);

	printf("Please enter the item's price: ");
	item->price = getDouble();

	printf("The item collected: %d, %s, %.2lf\n\n", item->productID, item->name, item->price);


	FILE* ofp = fopen(inventoryFile, "a");
	if (ofp == NULL)
	{
		return ERROR;
	}

	fprintf(ofp, "%d,%s,%.2lf\n", item->productID, item->name, item->price);

	if (fclose(ofp) != 0)
	{
		return ERROR;
	}
	return 0;
}


/*
* Clear the inline new line character if there is one 
*/
void clearNewLine(char* input)
{
	char* newLine = strrchr(input, '\n');
	if (newLine != NULL)
	{
		*newLine = '\0';
	}
}



/*
* See whether an item exist, if so returns its price. 
*/
int checkPrice(char* product, double* price)
{	
	int result = kNotFound;
	// opening the stock file 
	FILE* fp = fopen(inventoryFile, "r"); 

	if (NULL == fp)  
	{
		return kFileErr; 
	}

	// checking each line for product name 
	char buffer[kText] = { 0 }; 
	while (!feof(fp))
	{
		if (fgets(buffer, kText, fp) != NULL) // reading in one line
		{
			// parse a line, store it in the temporary item, if line is malformed, skip
			Item item; 
			if (parseItem(buffer, &item) == ERROR)
			{
				continue; 
			}

			// compare sub-string with user input. 
			if (strcmp(item.name, product) == 0)
			{
				result = SUCCESS;
				*price = item.price; 
				break;
			}
		}
	}

	if (fclose(fp) != 0)
	{
		return kFileErr; 
	}

	// return result based on whether product is found
	return result; 
}



/*
* Parse a stocked item out of a line of text, and insert those fields in an Item struct
*/
int parseItem(char* line, Item* item)
{
	// find first & second comma within line retrieved. 
	char* firstComma = strchr(line, ',');
	char* secondComma = strrchr(line, ',');

	// return error for a Malformed line
	if (firstComma == NULL || secondComma == NULL || firstComma == secondComma)
	{
		return ERROR; 
	}

	// create substring of productID, convert it to an int, store in item
	char productID[kBuf] = { 0 };	// arbitrarily used kBuf as array size
	int len = firstComma - line;
	strncpy(productID, line, len); 
	*(productID + len) = '\0';  // add NULL terminator

	item->productID = atoi(productID); 

	// create a substring for product name
	char retrievedName[kName] = { 0 };
	len = secondComma - firstComma - 1;		//retrieve name length from section 
	strncpy(retrievedName, firstComma + 1, len);
	*(retrievedName + len) = '\0';

	strcpy(item->name, retrievedName); 

	// create substring for price, convert it to double, store in item 
	char price[kBuf] = { 0 };
	strcpy(price, secondComma + 1); 
	
	item->price = atof(price); 

	return SUCCESS; 
}




/*
* See whether an item exist, if so returns its price.
* C doesn't have an easy way of removing one line. 
* 
* So what we are doing here is to copy every line that does not match the queried product 
* and copy over every line that does not match. 
*/
int deleteProduct (char* product)
{
	int result = kNotFound;
	// opening the stock file 
	FILE* stock = fopen(inventoryFile, "r");
	if (NULL == stock)
	{
		return kFileErr;
	}

	// open the temporary copy file 
	FILE* temp = fopen("temp.txt", "w"); 
	if (NULL == temp)
	{
		fclose(stock); 
		return kFileErr; 
	}

	// checking each line for product to delete
	char buffer[kText] = { 0 };
	while (!feof(stock))
	{
		if (fgets(buffer, kText, stock) != NULL) // reading in one line
		{
			// parse a line, store it in the temporary item, if line is malformed, skip
			Item item;
			parseItem(buffer, &item);

			// compare sub-string with user input, if match, do not write this line 
			if (strcmp(item.name, product) == 0)
			{
				result = SUCCESS;
				continue; 
			}
			fprintf(temp, buffer); 
		}
	}

	if (fclose(stock) != 0)	//if stock can't close, set return value 
	{
		result = kFileErr;	// not returning as we still have to close the other file
	}

	if (fclose(temp) != 0)
	{
		return kFileErr;
	}

	// both file closed, remove original file, rename the newly created one the inventory
	remove(inventoryFile); 
	rename("temp.txt", inventoryFile); 

	// return result based on whether product is found
	return result;
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


// alter the function, take in an integer by address (via pointer) 
// return a status flag indicating whether user has input a status or not 

int getInt(int* input)
{
	char record[121] = { 0 }; /* record stores the string */
	int status = 0;

	// use fgets to grab keyboard input 
	fgets(record, 121, stdin);

	// use sscanf to kCheck whether there's any number in the user input, place it in int* input if there is 
	if (sscanf(record, "%d", input) != 1)
	{
		/* if the user did not enter a status recognizable by
		* the system, set status to -1 */
		status = ERROR;
	}
	return status;
}