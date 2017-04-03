//CMPT 225 assignment 5
//Author: Bei Bei Li
//implementation for hashtable.h

#pragma once

#include <iostream>
#include <cstdlib>
#include <math.h> // needed for Hash function
#include <string>
#include <vector>
#include "linkedlist.h"
#include "hashtable.h"

using namespace std;

// hash function, uses Horner's method
// Assume input string consists only of lower-case a to z

int HashTable::Hash(string input) const //hash correct
{
	int h = 0;
	int i, val;
	int len = input.length();
	//cout << "len is " << len << endl;
	for (i = 0; i < len; i++) {
		 h = (32 * h + (input[i] - 'a' + 1 )) % maxsize;  //set a-z to 1-26
	}
	//cout << "hash is " << h << endl;
	return h;
}

// helper function to find smallest prime number greater than supplied parameter
int HashTable::SmallestPrime(int n) const
{
	int i;
	i = n + 1;
	while (IsPrime(i) != true) {
		i++;
	}
	return i;
}

// helper function to determine whether a number is prime
bool HashTable::IsPrime(int n) const
{
	if (n < 2) {
		return false;
	}
	int i;
	for (i = 2; i < n; i++) {   //prime is divisible by 1 and itself only
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

//LinkedList* table;  // array of separately chained binary search trees
//unsigned int size;    // number of items stored
//unsigned int maxsize; // size of underlying array

// default constructor
// creates an array of size 101
HashTable::HashTable()
{
	maxsize = 101;
	table = new LinkedList[maxsize];
	//for (int i = 0; i<maxsize; i++)
	//{
	//	table[i] = NULL;
	//}
	size = 0;

}

// parameterized constructor
// creates an array of size = smallest prime number > 2n
HashTable::HashTable(int n) //might be wrong
{
	maxsize = SmallestPrime(2 * n); //smallest prime incorrect???
	table = new LinkedList[maxsize];
	//for (int i = 0; i<maxsize; i++)
	//{
	//	table[i] = NULL;
	//}
	size = 0;
}

// copy constructor
// Creates deep copy of sourceht
HashTable::HashTable(const HashTable& sourceht)
{
	if (maxsize) {                               //clear
		delete[] table;
	}
	table = NULL;
	if (sourceht.maxsize && sourceht.table) {
		table = new LinkedList[sourceht.maxsize];
		//for (int i = 0; i<maxsize; i++)
		//{
		//	table[i] = NULL;
		//}
		int i;
		for (i = 0; i < sourceht.maxsize; i++) {
				table[i] = sourceht.table[i];           //copying using operator=
		}
	}
	maxsize = sourceht.maxsize;
	size = sourceht.size;
}

// destructor
HashTable::~HashTable()
{
	if (table != NULL) {
		delete[] table;
		table = NULL;
	}
	maxsize = 0;
	size = 0;
}

// overloaded assignment operator
HashTable& HashTable::operator=(const HashTable& sourceht)  ///incorrect
{
	if (this != &sourceht) {  // if not equal then change
		if (table != NULL) {
			delete[] table;
			table = NULL;
		}

		maxsize = 0;
		size = 0;
		if (sourceht.maxsize && sourceht.table) {      //code from copy constructor
			table = new LinkedList[sourceht.maxsize];  //cannot call HashTable(sourceht) directly....does not work
			int i;
			for (i = 0; i < sourceht.maxsize; i++) {
				table[i] = sourceht.table[i];
			}
		}
		maxsize = sourceht.maxsize;
		size = sourceht.size;

	}
	return *this;
}

// Insertion
// If item does not already exist, inserts and returns true
//   otherwise returns false
bool HashTable::Insert(string value) //problem here....
{
	if (Search(value) == true) {
		return false;
	}
	size++;
	double ld = LoadFactor();
	double compare = (float)2/3;
	while (ld >= compare){      //resize if efficiency lowered
		Resize(maxsize);
	}
	int key = Hash(value);
	//cout << "key is " << key << endl;
	table[key].Insert(value);
	return true;
}

// Removal
// If item exists, removes and returns true
//   otherwise returns false
bool HashTable::Remove(string value)
{
	if (Search(value) == false) {
		return false;
	}
	int key = Hash(value);
	table[key].Remove(value);
	size--;
	return true;
}

// Search
// Returns true if item exists, false otherwise
bool HashTable::Search(string value) const
{
	int key = Hash(value);
	return table[key].Contains(value);

}

// Returns the number of items stored in the hash table
int HashTable::Size() const
{
	return size;
}

// Returns the size of the underlying array
int HashTable::MaxSize() const
{
	return maxsize;
}

// Returns the load factor as size / maxsize.
// Note that due to separate chaining, load factor can be > 1.
double HashTable::LoadFactor() const
{
	double result = size / maxsize;
	return result;
	//for insertion
}

// Resizes the hashtable into a larger array.
// Return false if n is smaller than current array size.
// Else, set array size to the smallest prime number larger than n
//   and re-hash all contents into the new array, delete the old array and return true.
bool HashTable::Resize(unsigned int n)
{
	if (n < maxsize) {
		return false;
	}
	else {
		int max = maxsize;
		maxsize = SmallestPrime(n);
		LinkedList* oldtable = table;
		table = new LinkedList[maxsize];
		int i, j;

		size = 0;
		for (i = 0; i < max; i++){                         //every linked list
			vector<string> oldvalue = oldtable[i].Dump();  //using vector to rehash
			for (j = 0; j < oldvalue.size(); j++){         //linked list contents rehash
				Insert(oldvalue[j]);
			}
		}


		//for (i = 0; i < max; i++) {
		//	table[i] = oldtable[i];
		//}
		delete[] oldtable;
		return true;
	}
}




