// File:        linkedlist.h
// Author:      Geoffrey Tien
// Date:        2015-07-27
// Description: Declaration of a singly-linked list class for CMPT 225 assignment #5
//              Non-templated, stores strings.

#pragma once

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Node
{
  public:
    string data;
    Node* next;

    Node(string s, Node* nd)
    {
      data = s;
      next = nd;
    }
};

class LinkedList
{
  private:
    Node* head;
    unsigned int size;

    // helper method for deep copy
    void CopyList(const LinkedList& ll);

  public:
    // default constructor
    LinkedList();

    // copy constructor
    // deep copies source list
    LinkedList(const LinkedList& ll);

    // destructor
    ~LinkedList();

    // overloaded assignment operator
    // deep copies source list after deallocating existing memory (if necessary)
    LinkedList& operator=(const LinkedList& ll);

    // Inserts an item at the front of the list
    void Insert(string s);

    // Removes an item from the list.
    // Returns true if item successfully removed
    // False if item is not found
    bool Remove(string s);

    // Removes all items from the list, calls helper function
    void RemoveAll();

    // Checks if an item exists in the list
    bool Contains(string s) const;

    // Return the number of items in the list
    unsigned int Size() const;

    // Returns a vector containing the list contents using push_back
    vector<string> Dump() const;
};