/**
* Author: Westley Case & Morgan Allred
* Assignment: Project 5
* File: Account.cpp
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

#include "Account.h"

// --------------- Account Class Methods -------------------
Account::Account()
{
	human = new Person;
	accBalance = 0.00;
	accNumber = 0;
}

Account::Account(Person* _human, double _accBalance, int _accNumber)
{
	human = _human;
	accBalance = _accBalance;
	accNumber = _accNumber;
}

Account::~Account()
{
}

int Account::getAccountNumber() const
{
	return accNumber;
}

double Account::getAccountBalance() const
{
	return accBalance;
}

Person Account::getPerson() const
{
	return *human;
}

void Account::writeAccData(ofstream& _file) const
{
	_file << accBalance << endl;
	_file << accNumber << endl;
	human->writePerData(_file);
}

void Account::readAccData(ifstream& _file)
{
	string accNum;
	string accBal;

	getline(_file, accNum);
	getline(_file, accBal);
	// if error in read thorw exc
	if (_file.fail() && !_file.eof())
	{
		throw FileError(READ_ERROR);
	}
	else if (_file.eof())
	{
		throw FileError(END_OF_FILE);
	}
	// Have the person class read its own data
	human->readPerData(_file);

	accNumber = stoi(accNum);
	accBalance = stod(accBal);
}

void Account::makeDeposit(double _deposit)
{
	accBalance += _deposit;
}

void Account::makeWithdrawl(double _withdrawl)
{
	accBalance -= _withdrawl;
}

// ----------------- Person Class Methods ----------------------
Person::Person()
{
	name = "";
	address = "";
}

Person::Person(const string& _name, const string& _address)
{
	name = _name;
	address = _address;
}

Person::~Person()
{
}

string Person::getName() const
{
	return name;
}

string Person::getAddress() const
{
	return address;
}

void Person::writePerData(ofstream& _file) const
{
	_file << name << endl;
	_file << address << endl;
}

void Person::readPerData(ifstream& _file)
{
	getline(_file, name);
	getline(_file, address);

	// if error in read throw error
	if (_file.fail() && !_file.eof())
	{
		throw FileError(READ_ERROR);
	}
	else if (_file.eof())
	{
		throw FileError(END_OF_FILE);
	}
}