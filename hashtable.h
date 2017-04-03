// File:        hashtable.h
// Author:      Geoffrey Tien
// Date:        2015-07-27
// Description: Declaration of a hash table class for CMPT 225 assignment #5
//              Uses separate chaining with a singly-linked list

#pragma once

#include <cstdlib>
#include <math.h> // needed for Hash function
#include <string>
#include <vector>
#include "linkedlist.h"

using namespace std;

class HashTable
{
  private:
    LinkedList* table;  // array of separately chained binary search trees
    unsigned int size;    // number of items stored
    unsigned int maxsize; // size of underlying array

    // hash function, uses Horner's method
    // Assume input string consists only of lower-case a to z
    int Hash(string input) const;

    // helper function to find smallest prime number greater than supplied parameter
    int SmallestPrime(int n) const;

    // helper function to determine whether a number is prime
    bool IsPrime(int n) const;

  public:
    // default constructor
    // creates an array of size 101
    HashTable();

    // parameterized constructor
    // creates an array of size = smallest prime number > 2n
    HashTable(int n);

    // copy constructor
    // Creates deep copy of sourceht
    HashTable(const HashTable& sourceht);

    // destructor
    ~HashTable();

    // overloaded assignment operator
    HashTable& operator=(const HashTable& sourceht);

    // Insertion
    // If item does not already exist, inserts and returns true
    //   otherwise returns false
    bool Insert(string value);

    // Removal
    // If item exists, removes and returns true
    //   otherwise returns false
    bool Remove(string value);

    // Search
    // Returns true if item exists, false otherwise
    bool Search(string value) const;

    // Returns the number of items stored in the hash table
    int Size() const;

    // Returns the size of the underlying array
    int MaxSize() const;

    // Returns the load factor as size / maxsize.
    // Note that due to separate chaining, load factor can be > 1.
    double LoadFactor() const;

    // Resizes the hashtable into a larger array.
    // Return false if n is smaller than current array size.
    // Else, set array size to the smallest prime number larger than n
    //   and re-hash all contents into the new array, delete the old array and return true.
    bool Resize(unsigned int n);

    // Returns a pointer to the linked list at index i
    // This will be used for grading.
    // Typically hash tables will not provide access to individual chains.
    LinkedList* ListAt(unsigned int i)
    {
      if (i >= maxsize) return NULL;
      else return &table[i];
    }
};