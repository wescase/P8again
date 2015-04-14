/**
* Author: Westley Case & Morgan Allred
* Assignment: Project 5
* File: Checking.h
* Instructor: Dr. DeBry
* Class: CS1410-001
* Date Written: March 6th 2015
* Description: Write the account information to file and read back to the user when requested. using an inheritance architecture
*
* I declare the the following source code was written by Wes and Morgan,
* I understand the copying of any source code in whole or in part constitutes cheating,
* and I will recieve a 0 on this assignment if I violate this policy
*
*/

#pragma once
#include "Account.h"

class Checking : public Account
{
public:
	// Default Checking Constructor
	Checking();

	// Checking Parameterized Constructor
	// Purpose: Initialize the variables in the Checking Object
	// Parameters: Person*, int account number, double account balance, double monthly fee
	// Returns: none
	Checking(Person*, int, double, double);

	// getAccountBalance
	// Purpose: retrieve balance of the Checking Object
	// Parameters: none
	// Returns: double
	double getAccountBalance() const;

	// writeAccData()
	// Purpose: write the checking account data to a file
	// Parameters: ofstream obj
	// Returns: none
	void writeAccData(ofstream& _file) const;

	// readAccData()
	// Purpose: read the checking accoutn data
	// Parameters: ifstream obj
	// returns: none
	void readAccData(ifstream& _file);

	// ~Checking()
	// Purpose: Destroy objects out of scope
	// Parameters: none
	// returns: none
	~Checking();
private:
	double monthlyFee;
};

