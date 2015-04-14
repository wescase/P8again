/**
* Author: Westley Case & Morgan Allred
* Assignment: Project 5
* File: Savings.cpp
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

#include "Savings.h"


Savings::Savings()
{
	interest = 0.0;
}

Savings::Savings(Person* _human, int _account, double _bal, double _intr)
	: Account(_human, _account, _bal)
{
	interest = _intr;
}

double Savings::getAccountBalance() const
{
	// Accruing intersest
	double temp = accBalance + (accBalance * interest);
	return temp;
}

void Savings::writeAccData(ofstream& _file) const
{
	// write out a word to look for in the file for which account it is for
	_file << "save" << endl;
	// write out a key for the type of data to write (check)
	_file << interest << endl;
	// have account wirite its data
	Account::writeAccData(_file);
}

void Savings::readAccData(ifstream& _file)
{
	if (_file.fail() && !_file.eof())
	{
		throw FileError(READ_ERROR);
	}
	else if (_file.eof())
	{
		throw FileError(END_OF_FILE);
	}
	// read the string and turn to double set as monthly fee.
	string temp = "";
	getline(_file, temp);
	interest = stod(temp);
	// Have Account read in its data.
	Account::readAccData(_file);
}

Savings::~Savings()
{
}
