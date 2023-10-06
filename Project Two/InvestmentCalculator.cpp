/* 
* Project: Airgead Bank Interest Calculator
* Demonstate how compounding interest and monthly deposits can affect
* the balance of an account over time
* 
* Author: Danforth Morrigan
* Date: 2023-09-26
*/

#include <iostream>
#include <iomanip>

#include "DisplayMenu.h"
#include "DisplayBalance.h"
#include "CalculateInterest.h"

int main() {
	// Declare variables
	float openingAmount, depositAmount, interestRate;
	float noDeposit = 0.0;
	int year;
	char yn;
	bool cont = true;

	while (cont) {
		// Display menu	and get user input
		DisplayMenu(openingAmount, depositAmount, interestRate, year);

		// Display the balances with no monthly deposits
		std::cout << std::endl;
		std::cout << "       Balance and Interest With No Monthly Deposits       ";
		std::cout << std::endl;
		DisplayBalance(openingAmount, noDeposit, interestRate, year);

		// Display the balances with monthly deposits
		std::cout << std::endl << "     Balance and Interest With $";
		std::cout << depositAmount << " Monthly Deposits" << std::endl;
		DisplayBalance(openingAmount, depositAmount, interestRate, year);

		// Ask user if they want to continue
		std::cout << std::endl;
		std::cout << "Continue? (y/n): ";
		std::cin >> yn;
		if (yn != 'y' && yn != 'Y') {
			cont = false;
		}
		
	}
	return 0;
}
