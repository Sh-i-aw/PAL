#include <stdio.h>

#pragma warning (disable:4996)

// const for product name length
#define kNameLen 20

//const to define whether a product is on sale 
const int kOnSale = 1;
const int kNotOnSale = 0;

// declare a struct here called "Product", it should have three fields: 
/*
* A string : productName, max length is kNameLen 
* A double : price
* An int : IsOnSale, indicates whether the product is on sale, 1 for yes, 0 for no. 
*/


/*
* Function declarations here: 
* 1. A function called <updatePrice>, it takes 2 parameters and returns nothing
*	- a pointer to the struct Product 
*   - a double representing the new price. 
* 2. A function called <printAProduct>, it takes 1 parameter: a pointer to the struct: Product, and returns nothing 
*/


int main(void)
{
	// declare a product, give it all three fields. 

	// print the product, call printAProduct()

	// update the product price, call updatePrice()
}


// this function will update a product's current price to the new price. 
// It should output a message: 
//		"Oatmilk's old price was $4.99, its updated price is $3.99\n"
void updatePrice(Product* product, double newPrice)
{
}


 //this function will take a product and print out it's information 
 //it should output: 
	//	"Product name: Oatmilk 
	//	 Price: $4.99 
	//	 Currently on sale: yes  (hint: can make use of tenary here) 
void printAProduct(Product* product)
{
}

