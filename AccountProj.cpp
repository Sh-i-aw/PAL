#include <stdio.h>
#pragma warning(disable: 4996)
/*
* Problem to solve:
*	Create a program that can calculates the current balance of a savings account that compounds
*	interest yearly. Given the principal amount, compound interest rate, and the number of years.
*	Calculate the account balance and print it out each year.
*	User can either:
*		request to know their balance at the next maturity date
*		request a projection to see how much their money grow given the number of years.
*
*	Create the program modularly:
*		create a function that returns the balance at the next cycle:
*		create a function that shows the income projection after total years of maturity.
*
*
*	The income projection function should output something like this:
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
void incomeProjection(double balance, double interestRate, int numOfYears);
double getDouble(void);
int getInt(void);

// show the possible declaration methods 
// practiced avoiding MAGIC NUMBERS
#define kRateOne 0.03
const double kRateTwo = 0.05;

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
	int userChoice = getInt();

	// repeat prompting the user, until they give the right input 
	while (userChoice != 1 && userChoice != 2) //if user does not choose 1 of 2 
	{
		printf("Please enter a valid option: \n\t 1. 3%% \n\t 2. 5%%\n\n");
		userChoice = getInt();
	}

	double interestRate = 0.0;

	// Alternatively: userChoice == 1 ? interestRate = kRateOne : interestRate = kRateTwo;
	if (userChoice == 1)
	{
		interestRate = kRateOne;
	}
	else if (userChoice == 2)
	{
		interestRate = kRateTwo;
	}

	printf("\nThe interest rate you have chosen is %.2lf%%.\n", interestRate * 100);


	// collecting user input for number of years of the save term. 

	printf("\n Please indicate the number of years for your savings' term:");

	int numOfYears = getInt();

	// call interest calculation function 
	// ALT: double firstYearBalance = interestCalculation(balance, interestRate);

	printf("Total balance after first compounding term: $%.2lf\n\n", interestCalculation(balance, interestRate));

	incomeProjection(balance, interestRate, numOfYears);

	// print out the value after compounding 

	// call the projection function 
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
void incomeProjection(double balance, double interestRate, int numOfYears)
{
	// declare necessary variables to hold the intermediate values 
	int currentYear = 1;
	double interimBalance = balance;

	printf("Given the principal of $%.2lf : \n", balance);
	// LOOP for each year in the compounding period 
	while (currentYear <= numOfYears)
	{
		// calculate the value given interst and principal 
		interimBalance = interestCalculation(interimBalance, interestRate);

		// print out the balance after compounding 
		printf("\tTotal balance after year %d : $%.2lf\n", currentYear, interimBalance);
		currentYear++;
		// OPTIONALLY 
	}

	// ALT: double totalInterest = interimBalance - balance; 

	// print out the total interest collected 
	printf("Total interest : $%.2lf  ", interimBalance - balance);

	return;
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



int getInt(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can
	improve this code */

	char record[121] = { 0 }; /* record stores the string */
	int number = 0;

	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */

	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */


	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}















