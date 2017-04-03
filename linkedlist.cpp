//CMPT 225 assignment 5
//Author: Bei Bei Li
//implementation for linkedlist.h

#pragma once
#include <cstdlib>
#include <string>
#include <vector>
#include "linkedlist.h"
using namespace std;

// helper method for deep copy
void LinkedList::CopyList(const LinkedList& ll)
{
	if (size){                         //if exsit, clear
		RemoveAll();
	}
	if (ll.size && ll.head){          //if ll exist
		Node* L = ll.head;
		head = new Node(L->data, L->next);   //creating deep copy
		L = L->next;
		Node* current = head;
		while (L != NULL){
			current->next = new Node(L->data, L->next);
			L = L->next;                               //move L to copy
			current = current->next;                   //move current
		}
	}
	size = ll.size;
}

// default constructor
LinkedList::LinkedList()
{
	head = NULL;
	size = 0;
}

// copy constructor
// deep copies source list
LinkedList::LinkedList(const LinkedList& ll)
{
	head = NULL;
	size = 0;
	CopyList(ll);
}

// destructor
LinkedList::~LinkedList()
{
	RemoveAll();
}

// overloaded assignment operator
// deep copies source list after deallocating existing memory (if necessary)
LinkedList& LinkedList::operator=(const LinkedList& ll)
{
	if (this != &ll) {  // if not equal then change
		//RemoveAll();
		CopyList(ll);
	}
	return *this;
}

// Inserts an item at the front of the list
void LinkedList::Insert(string s)
{
	//Node* oldhead = head;
	Node* ins = new Node(s, head);     //create, oldhead becomes ptr next
	if (ins != NULL){
		head = ins;             //set head
		size++;
	}
}

// Removes an item from the list.
// Returns true if item successfully removed
// False if item is not found
bool LinkedList::Remove(string s)
{
	if (head == NULL){
		return false;
	}
	if (head->data == s){               //if head is to be removed, ptr next becomes head
		Node* oldhead = head;
		head = head->next;
		delete oldhead;
		size--;
		return true;
	}
	Node* current = head->next;         //if in the linked list, set prev node's next ptr to current's next
	Node* prev = head;
	while (current != NULL){
		if (current->data == s){
			prev->next = current->next;
			delete current;
			size--;
			return true;
		}
		current = current->next;
		prev = prev->next;
	}
	return false;
}

// Removes all items from the list, calls helper function
void LinkedList::RemoveAll()
{
	Node* current = head;
	while (current != NULL){                //traverse to remove
		head = head->next;
		delete current;
		current = head;
	}
	head = NULL;
	size = 0;
}

// Checks if an item exists in the list
bool LinkedList::Contains(string s) const
{
	if (head != NULL){
		Node* current = head;
		while (current != NULL){
			if (current->data == s){
				return true;
			}
			current = current->next;
		}
	}
	return false;
}

// Return the number of items in the list
unsigned int LinkedList::Size() const
{
	return size;
}

// Returns a vector containing the list contents using push_back
vector<string> LinkedList::Dump() const
{
	vector<string> result;
	Node* current = head;
	while (current != NULL){
		result.push_back(current->data);          //using vector method to push_back
		current = current->next;                  //traverse to push_back next
	}
	return result;
}
