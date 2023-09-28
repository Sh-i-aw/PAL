#include <stdio.h>

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

int main(void)
{
	// declare variables for principal, interest rate, number of years compounding 
	double balance = 100;
	double interestRate = 0.05;
	int numOfYears = 3;

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
