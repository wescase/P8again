/*
* Author: Westley Case & Morgan Allred
* Assignment: Project 7
* File: MyVector.h
* Instructor: Dr. DeBry
* Class: CS1410-001
* Date Written: March 26, 2015
* Description: Manage the memory correctly, overload operators to handle copying objects
*
* I declare the the following source code was written by Wes and Morgan,
* I understand the copying of any source code in whole or in part constitutes cheating,
* and I will recieve a 0 on this assignment if I violate this policy
*/

#include <string>
#include <iostream>
using namespace std;

// Constants
const int MIN_VALUE = 0;
const char NULL_CHAR = '\0';
const int INI_ARR = 1;
const int DOUBLE = 2;

template <class T>
class MyVector
{
public:

	// Purpose: Creates and initiallizes an empty vector object.
	// Parameters: None
	// Returns: None
	MyVector();

	// Purpose: Deletes the vector object
	// Parameters: None	
	// Returns: None
	~MyVector();

	// Purpose: Creates and initiallizes a vector of a given size.
	// Parameters: Int - capacity of vector
	// Returns: None
	MyVector(T _cap);

	// Purpose: Copy constructor
	// Parameters: Object to copy from
	// Returns: none
	MyVector(const MyVector&);

	// Purpose: Gives the number of elements in the vector
	// Parameters: none
	// Returns: size - # of elements
	int size() const;

	// Purpose: Gives the number of spaces in the vector
	// Parameters: none
	// Returns: capacity - # of 
	int capacity() const;

	// Purpose: Deletes the array and sets the pointer to null	
	// Parameters: none
	// Returns: none	
	void clear();

	// Purpose: Pushes values into the vector
	// Parameters: int - takes an integer to store
	// Returns: none
	void push_back(T _newEle);

	// Purpose: Get the data at a given location in the array
	// Parameters: int - location of the pointer
	// Returns: int value and given location
	int at(T _pos);

	// Purpose: to retrieve a value at given index
	// Parameters: int - index #
	// Returns: Value at given index
	int operator[](int i) const;

	// Purpose: to store a value in given index
	// Parameters: int - index #
	// Returns: reference to the index storage location
	int& operator[](int i);

	// Purpose: Overload the = operator to handle copying one object to another
	// Parameters: vector to copy from 
	// Returns: MyVector
	MyVector& operator=(const MyVector&);

private:

	// Variables
	int mass;
	int volume;
	T* vPointer;
};

// -------------------- cpp methods --------------------

template <typename T>
MyVector<T>::MyVector()
{
	mass = 0;
	volume = 0;
	vPointer = nullptr;
}


template <typename T>
MyVector<T>::~MyVector()
{
	delete[] vPointer;
	vPointer = nullptr;
}


template <typename T>
MyVector<T>::MyVector(T _cap)
{
	mass = 0;
	volume = _cap;
	vPointer = new T[_cap];
}


template <typename T>
MyVector<T>::MyVector(const MyVector& ob1)
{
	mass = ob1.mass;
	volume = ob1.volume;
	vPointer = new int[volume];

	for (unsigned i = 0; i < mass; i++)
	{
		vPointer[i] = ob1.vPointer[i];
	}
}


template <typename T>
int MyVector<T>::size() const
{
	return mass;
}


template <typename T>
int  MyVector<T>::capacity() const
{
	return volume;
}


template <typename T>
void MyVector<T>::clear()
{
	delete[] vPointer;
	vPointer = nullptr;
	mass = 0;
	volume = 0;
}


template <typename T>
int MyVector<T>::operator[](int i) const
{
	if (i < volume)
	{
		return vPointer[i];
	}
	return 0;
}


template <typename T>
T& MyVector<T>::operator[](int i)
{
	if (i < volume)
	{
		return vPointer[i];
	}
	return i;
}

// The operator should be white not red....
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& obj)
{
	if (vPointer != nullptr)
	{
		delete[] vPointer;
	}
	mass = obj.mass;
	volume = obj.volume;
	vPointer = new int[volume];
	for (unsigned i = 0; i < mass; i++)
	{
		vPointer[i] = obj.vPointer[i];
	}
	return *this;
}













template <typename T>
void MyVector<T>::push_back(T _newEle)
{
	if (vPointer == nullptr)
	{
		vPointer = new T[DOUBLE];
		volume = DOUBLE;
	}

	// Vector grows if size equals capacity
	else if (mass == volume)
	{
		volume *= DOUBLE;
		T* temp = new T[volume];

		for (int i = 0; i < mass; i++)
		{
			// Copy contents of old array into the new array
			temp[i] = vPointer[i];
		}

		delete[] vPointer;
		vPointer = temp;
	}

	vPointer[mass] = _newEle;
	mass++;
}


template <typename T>
T MyVector<T>::at(T _pos)
{
	if (_pos >= mass)
	{
		// Throw exception with the bad index as value
		throw _pos;
	}
	return vPointer[_pos];
}

// -------------------- helper functions --------------------
// Purpose: Overload how to cout an object
// Paramenters: ostream by ref, MyVector by ref
// Returns: the ostream to cout
template <typename T>
ostream& operator<<(ostream& out, const MyVector<T>& value)
{
	for (unsigned i = 0; i < value.size(); i++)
	{
		out << value[i];
	}
	return out;
}