/**
* Author: Westley Case & Morgan Allred
* Assignment: Project 5
* File: Driver.h
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
#include<iostream>
#include<string>
// #include<vector>
#include<fstream>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "MyVector.h"


//-------------------Constant Variables-------------------
const int ACC_1 = 1;
const int ACC_2 = 2;
const int ACC_3 = 3;

const double DEPOSIT = 25.00;
const double WITHDRAW = 100.00;

const double INIT_1 = 500.00;
const double INIT_2 = 1000.00;
const double INIT_3 = 1200.00;

const double I_1 = .075;
const double I_2 = .05;
const double F_1 = 2.00;

//-------------------Constant Variables-------------------


// displayAccounts
// Purpose: to display the account info to the user in console
// Parameters: vector, of Accounts
// Returns: none
void displayAccounts(const MyVector<Account*>&);

