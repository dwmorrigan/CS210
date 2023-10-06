/*
* Airgear Bank Function Library
* Display's the menu and gets the user input
* Author: Danforth Morrigan
* Date: 2023-09-26
*/

#include <iostream>
#include <limits>
#include "DisplayMenu.h"

void DisplayMenu(
				float& t_openingAmount, 
				float& t_depositAmount, 
				float& t_interestRate, 
				int& t_year) {

	bool invalidInput = true;

	std::cout << "*********************** Data Input ************************";
	std::cout << std::endl;

	// Get opening amount. Validate that it is a float and greater than 0
	while (invalidInput) {
		std::cout << "Initial Investment: $";
		std::cin >> t_openingAmount;
		if (std::cin.fail() || t_openingAmount < 0.01) { // If the input is not a float or is less than 0.01
			std::cin.clear(); // Clear the error flag
			std::cout << "Please enter a valid dollar amount." << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
		}
		else {
			invalidInput = false;
		}
	}

	invalidInput = true; // Reset the invalidInput flag
	// Get monthly deposit. Validate that it is a float and greater than 0
	while (invalidInput) {
		std::cout << "Monthly Deposit: $";
		std::cin >> t_depositAmount;
		if (std::cin.fail() || t_depositAmount < 0.01) { // If the input is not a float or is less than 0.01
			std::cin.clear(); // Clear the error flag
			std::cout << "Please enter a valid dollar amount." << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
		}
		else {
			invalidInput = false;
		}
	}

	invalidInput = true; // Reset the invalidInput flag
	// Get interest rate. Validate that it is a float and greater than 0
	while (invalidInput) {
		std::cout << "Interest Rate: %";
		std::cin >> t_interestRate;
		if (std::cin.fail() || t_interestRate < 0.01) { // If the input is not a float or is less than 0.01
			std::cin.clear(); // Clear the error flag
			std::cout << "Please enter a valid interest amount" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
		}
		else {
			invalidInput = false;
		}
	}

	invalidInput = true; // Reset the invalidInput flag
	// Get number of years. Validate that it is an int and greater than 0
	while (invalidInput) {
		std::cout << "Number of years: ";
		std::cin >> t_year;
		if (std::cin.fail() || t_year < 1) { // If the input is not an integer or is less than 1
			std::cin.clear(); // Clear the error flag
			std::cout << "Please enter a valid number of years" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
		}
		else {
			invalidInput = false;
		}
	}

	// Clear the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// std::system("pause") uses "Press any key to continue . . ." on Windows. 
	// std::system("read"); uses "Press any key to continue . . ." on Linux or Mac.
	std::system("pause");

	return;
}
