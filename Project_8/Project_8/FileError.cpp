
/**
* Author: Westley Case & Morgan Allred
* Assignment: Project 5
* File: FileError.cpp
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

#include "FileError.h"

FileError::FileError(int _a)
{
	errorCode = _a;
}

int FileError::getErrorCode() const
{
	return errorCode;
}

