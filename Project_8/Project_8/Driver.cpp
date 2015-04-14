/**
* Author: Westley Case & Morgan Allred
* Assignment: Project 5
* File: Driver.cpp
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

#include "Driver.h"

int main()
{
	// Create vector for accounts
	MyVector<Account*> accVector;

	// Push these Account objects into the vector.
	accVector.push_back(new Savings(new Person("Bilbo Baggins", "43 Baggins"), ACC_1, INIT_1, I_1));
	accVector.push_back(new Checking(new Person("Wizard Gandolf", "Crystal Palace"), ACC_2, INIT_2, F_1));
	accVector.push_back(new Savings(new Person("Elf Elrond", "Rivendell"), ACC_3, INIT_3, I_2));

	// New: Create an ofstream object and open a file.
	// Hard code the file name in your program.
	// Pass the file name as the parameter to the open function of your ofstream object 
	// so that your program assumes the file to be in the same folder as your executable file.
	ofstream dataOut;

	dataOut.open("dataFile.txt");

	// New : Using a loop, send messages to each of the three Account objects to write themselves out to the file.
	if (dataOut.good())
	{
		for (unsigned int i = 0; i < accVector.size(); i++)
		{
			Account accVector[i]->writeAccData(dataOut);
		}
	}

	// New : Close the file.
	dataOut.close();

	// Before clearing the pointers, you must delete the Objects or they will be held in memory and mess up program.
	int size = accVector.size();
	for (unsigned i = 0; i < size; i++)
	{
		delete accVector[i];
	}

	// New : Clear the vector.
	accVector.clear();

	// create ifstream object to read file
	ifstream in;

	// New : Open the file that you just saved.
	in.open("dataFile.txt");

	// Check if the file in failed
	if (in.fail())
	{
		cout << "There was an error opening the file" << endl;
		cout << "Application Ending" << endl;
		system("pause");
		return 1;
	}

	// New : Using a loop, tell each object to read itself in from the file.
	while (in)
	{
		Account* ptr = nullptr;

		string type;
		getline(in, type);
		// test sentinal in file for which Obj type to create
		if (type == "check")
			ptr = new Checking;
		else if (type == "save")
			ptr = new Savings;
		// if no Obj created/ no address
		if (ptr != nullptr)
		{
			try // to read data and push back in
			{
				ptr->readAccData(in);
				accVector.push_back(ptr);
			}
			catch (FileError e)
			{
				if (e.getErrorCode() == READ_ERROR)
				{
					cout << "There was an error reading the file" << endl;
					cout << "Program Terminating..." << endl;
					in.close();
					system("pause");
					return 1;
				}
			}
			catch (invalid_argument e)
			{
				cout << "There was an error reading the file, invalid argument" << endl;
				cout << "Program Terminating..." << endl;
				in.close();
				system("pause");
				return 1;
			}
		}
	} // End While Loop

	// Using a for loop, add $25.00 to each account.
	for (unsigned i = 0; i < accVector.size(); i++)
	{
		accVector[i]->makeDeposit(DEPOSIT);
	}
	// Using a second for loop, withdraw $100.00 from each account.
	for (unsigned i = 0; i < accVector.size(); i++)
	{
		accVector[i]->makeWithdrawl(WITHDRAW);
	}

	// Finally, pass the vector to your displayAccounts function to display the account information for each Account object in the vector.
	displayAccounts(accVector);

	// Before clearing the pointers, you must delete the Objects or they will be held in memory and mess up program.
	int size2 = accVector.size();
	for (unsigned i = 0; i < size2; i++)
	{
		delete accVector[i];
	}

	cout << endl;
	system("Pause");
	return 0;
} // End Main()

void displayAccounts(const MyVector<Account*>& _aVector)
{
	// Console out text
	cout << "National Bank\n" << endl;
	cout << "Account\tAccount" << endl;
	cout << "Number\tName\t\t\tAddress\t\t\tBalance\n" << endl;
	// Loop through the vector to get account info to display
	for (unsigned i = 0; i < _aVector.size(); i++)
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << _aVector[i]->getAccountNumber() << "\t" << _aVector[i]->getPerson().getName() << "\t\t" << _aVector[i]->getPerson().getAddress() << "\t\t$" << _aVector[i]->getAccountBalance() << endl;
	}
}

