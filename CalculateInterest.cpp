/*
* Airgear Bank Function Library
* Accepts the principal and interest rate and returns the interest earned
* Author: Danforth Morrigan
* Date: 2023-09-26
*/

#include <cmath>

#include "CalculateInterest.h"

float CalculateInterest(float t_principal, float t_interest) {
	float justTheInterest;
	float rate = t_interest / 100;
	// Compounding period is monthly - could be adjusted for other periods
	int compoundingPeriods = 12;
	// Number of compounding periods being evaluated - could be adjusted for other
	//  periods.  For example, if you wanted to see the interest earned after 5
	//  years, but compounded monthly you would set this to 60 
	// (5 years * 12 months)
	int numberOfCompoundingPeriods = 1;
	// Formula for compound interest:
	// A = P(1 + r/n)^nt - P
	justTheInterest = pow((1 + (rate / compoundingPeriods)), numberOfCompoundingPeriods);
	justTheInterest *= t_principal;
	justTheInterest -= t_principal;
	return justTheInterest;
}