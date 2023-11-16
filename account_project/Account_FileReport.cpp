#include <stdio.h>
#pragma warning(disable: 4996)
/*
* Problem to solve:
*	Create a program that can calculates the current balance of a savings account that compounds
*	interest yearly. Given the principal amount, compound interest rate, and the status of years.
*	Calculate the account balance and print it out each year.
*	User can either:
*		request to know their balance at the next maturity date
*		request a projection to see how much their money grow given the status of years.
*
*	Create the program modularly:
*		create a function that returns the balance at the next cycle:
*		create a function that shows the income projection after total years of maturity.
*
*
*	The program will output a text file that has an account projection report
*
*	Given the principal of $100:
*		Total balance after year 1: $105
*		Total balance after year 2: $ 110.25
*		Total balance after year 3: $115.76
*
*	Total interest: $15.76.
*
*/

// required library 

// constants  

// function prototypes 

#include <stdio.h>

double interestCalculation(double balance, double interestRate);
int GenerateReport(double balance, double interestRate, int numOfYears, const char* reportName);
double getDouble(void);
int getInt(int* input);

// show the possible declaration methods 
// practiced avoiding MAGIC NUMBERS
#define kRateOne 0.03
const double kRateTwo = 0.05;

#define ERROR -1 
#define SUCCESS 0 

enum interestLevel
{
	LOW = 1,
	MED,
	HIGH
};


int main(void)
{
	// collecting balance from user 
	printf("Please enter balance: ");
	double balance = getDouble();

	// Collecting user choice for interest rate. 

	// The bank will offer 2 available interest rate for the user to choose from. 
	// Option 1: 3% interest rate 
	// Option 2: 5% interest rate

	printf("Please choose from the 2 available interest rate options: \n\t 1. 3%% \n\t 2. 5%%\n\n");
	int userChoice = 0;
	getInt(&userChoice);

	// repeat prompting the user, until they give the right input 
	while (userChoice != 1 && userChoice != 2) //if user does not choose 1 of 2 
	{
		printf("Please enter a valid option: \n\t 1. 3%% \n\t 2. 5%%\n\n");
		getInt(&userChoice);
	}

	double interestRate = 0.0;

	//We used to have an if-else here, updated it to a switch case. The enum declaration can be seen before main. 

	switch (userChoice)
	{
	case LOW:
		interestRate = kRateOne;
		break;
	case MED:
		interestRate = kRateTwo;
		break;
	default:
		printf("choice was neither 1 or 2");

	}

	printf("\nThe interest rate you have chosen is %.2lf%%.\n", interestRate * 100);


	// collecting user input for status of years of the save term. 

	printf("\n Please indicate the number of years for your savings' term:");

	int numOfYears = 0;
	if (getInt(&numOfYears) == ERROR)
	{
		printf("No valid number of years detected, default to 3 years.\n");
		numOfYears = 3;
	}

	// call interest calculation function 
	// ALT: double firstYearBalance = interestCalculation(balance, interestRate);

	printf("Total balance after first compounding term: $%.2lf\n\n", interestCalculation(balance, interestRate));

	if (GenerateReport(balance, interestRate, numOfYears, "AccountReport.txt") == 0)
	{
		printf("Sucessfully generated report.\n");
	}
	

	return 0;
}






// interest calculation function 
double interestCalculation(double balance, double interestRate)
{
	// calculate the value given interst and principal 
	// ALT: balance =  balance + balance * interestRate;

	// return result 
	return balance + balance * interestRate;
}




// income projection function 
int GenerateReport(double balance, double interestRate, int numOfYears, const char* reportName)
{
	FILE* fpReport = fopen(reportName, "w");

	if (fpReport == NULL)
	{
		printf("Error: cannot open file for writing\n");
		return ERROR;
	}
	// declare necessary variables to hold the intermediate values 
	double interimBalance = balance;

	fprintf(fpReport, "Given the principal of $%.2lf : \n", balance);
	// LOOP for each year in the compounding period 
	for (int currentYear = 1; currentYear <= numOfYears; ++currentYear)
	{
		// calculate the value given interst and principal 
		interimBalance = interestCalculation(interimBalance, interestRate);

		// print out the balance after compounding 
		fprintf(fpReport, "\tTotal balance after year %d : $%.2lf\n", currentYear, interimBalance);

	}

	// print out the total interest collected 
	fprintf(fpReport, "Total interest : $%.2lf  ", interimBalance - balance);

	if (fclose(fpReport) != 0)
	{
		printf("Error: cannot close file, file not created\n");
		return ERROR;
	}

	return 0;
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

	// use sscanf to check whether there's any number in the user input, place it in int* input if there is 
	if (sscanf(record, "%d", input) != 1)
	{
		/* if the user did not enter a status recognizable by
		* the system, set status to -1 */
		status = ERROR;
	}
	return status;
}