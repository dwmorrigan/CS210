/*
* Airgear Bank Function Library
* Display's the balance and interest earned for each year
* Author: Danforth Morrigan
* Date: 2023-09-26
*/

#include <iostream>
#include <iomanip>
#include "DisplayBalance.h"
#include "CalculateInterest.h"

void DisplayBalance(
					float t_opening, 
					float t_deposit, 
					float t_rate, 
					int t_year) {

	// DIsplay a pretty table
	std::cout << std::setfill('-') << std::setw(60) << "-" << std::endl;
	std::cout << std::setfill(' ') << std::fixed << std::setprecision(2);
	std::cout << std::right << std::setw(8) << "Year" << std::setw(22);
	std::cout << "Year End Balance" << std::setw(30);
	std::cout << "Year End Earned Interest";
	std::cout << std::endl;

	float startingBalance = t_opening + t_deposit;
	float earnedInterest;
	float yearlyInterest = 0;

	// Calculate the interest earned each month for the user specified # of years
	for (int i = 0; i < t_year*12; i++) {
		earnedInterest = CalculateInterest(startingBalance, t_rate);
		yearlyInterest += earnedInterest;
		// Display the results for each year end
		if ((i + 1) % 12 == 0) {
			std::cout << std::right;
			std::cout << std::setw(8) << (i + 1) / 12 << " ";
			std::cout << std::setw(21) << (startingBalance + earnedInterest) << " ";
			std::cout << std::setw(29) << (yearlyInterest) << std::endl;
			yearlyInterest = 0;
		}
		startingBalance += earnedInterest + t_deposit;
	}
}