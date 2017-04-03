 // File:        a5simpledriver.cpp
// Author:      Geoffrey Tien
//              (your names here)
// Date:        2015-07-27
// Description: Partial test driver for CMPT 225 assignment #5.
//
//              ****************************************************************
//              ****************************************************************
//              ****                                                        ****
//              ****   IT IS STRONGLY RECOMMENDED FOR YOU TO ADD YOUR OWN   ****
//              ****   TESTING CODE TO THIS DRIVER.                         ****
//              ****                                                        ****
//              ****   PLEASE ADD YOUR OWN CODE TO THOROUGHLY TEST ALL      ****
//              ****   LINKED LIST AND HASH TABLE FUNCTIONS.                ****
//              ****                                                        ****
//              ****   PLEASE TEST *ALL* LINKED LIST AND                    ****
//              ****   HASH TABLE FUNCTIONS!                                ****
//              ****                                                        ****
//              ****************************************************************
//              ****************************************************************

#include <iostream>
#include "linkedlist.h"
#include "hashtable.h"

using namespace std;

// forward declarations
void PrintLinkedListContents(const LinkedList& ll);

void MyLinkedListTest();
void MyHashTableTest();
void HashTableSimpleTest();

int main()
{
  cout << "CMPT 225 Assignment #5 simple driver\n\n"
       << "PLEASE BE CERTAIN TO ADD YOUR OWN CODE TO THOROUGHLY TEST \n"
       << "ALL LINKEDLIST AND HASHTABLE FUNCTIONS!\n" << endl;
  MyLinkedListTest();
  MyHashTableTest();
  HashTableSimpleTest();

  system("pause");
  return 0;
}

void MyLinkedListTest()
{
	//constructor
	LinkedList test;
	test.Insert("helloworld");
	test.Insert("hellomama");
	test.Insert("lol");
	cout << "LINKED LIST contents INSERT" << endl;
	PrintLinkedListContents(test);
	//size
	cout << "test size should be 3 " << test.Size() << endl;
	//operator
	LinkedList copy;
	copy.Insert("operatorfunctionincorrect");
	copy = test;
	cout << "LINKED LIST Operator = copy contents" << endl;
	PrintLinkedListContents(copy);
	cout << "test size should be 3 " << copy.Size() << endl;
	//contains
	if (test.Contains("lol") == true) {
		cout << "contains lol, pass" << endl;
	}
	else {
		cout << "lol undetected, fail" << endl;
	}
	//remove & contains
	cout << "LINKED LIST contents, REMOVE" << endl;
	test.Remove("lol");
	cout << "test size should be 2 " << test.Size() << endl;
	if (test.Remove("not") == false) {
		cout << "remove pass non-contain value" << endl;
	}
	else {
		cout << "remove = true, for non-contain" << endl;
	}
	PrintLinkedListContents(test);
	test.Remove("helloworld");
	cout << "test size should be 1 " << test.Size() << endl;
	PrintLinkedListContents(test);
	test.Remove("hellomama");
	cout << "test size should be 0 " << test.Size() << endl;
	if (test.Contains("lol") == true) {
		cout << "contains, fail" << endl;
	}
	else {
		cout << "lol undetected, pass" << endl;
	}
	PrintLinkedListContents(test);
	//removeall
	copy.RemoveAll();
	cout << "LINKED LIST contents, removeALL" << endl;
	PrintLinkedListContents(copy);
	cout << "test size should be 0 " << copy.Size() << endl;
	cout <<"LINKed LIST test end" << endl;


}

void MyHashTableTest()
{
	cout << endl << "My test for hash table starts" << endl;
	HashTable test;
	bool result;
	//Insert 
	test.Insert("a");
	result = test.Insert("cf");
			cout << "the maxsize should be 23 " << test.MaxSize() << endl;
			cout << "the size should be 1 " << test.Size() << endl;
			cout << "hello inserted and searched passed" << endl;
			PrintLinkedListContents(*(test.ListAt(1)));

			test.Resize(102);
			cout << "the maxsize should be 103 " << test.MaxSize() << endl;
			PrintLinkedListContents(*(test.ListAt(102)));
			PrintLinkedListContents(*(test.ListAt(1)));


	HashTable copy;
	cout << "the maxsize should be 101 " << copy.MaxSize() << endl;
	copy = test;

	cout << "the size should be 1 " << copy.Size() << endl;
	PrintLinkedListContents(*(copy.ListAt(1)));
	HashTable para(20); //23 smallest prime //issue right here.....
	cout << "the maxsize should be 41 " << para.MaxSize() << endl;
	para = test;
	
	cout << "the size should be 1 " << para.Size() << endl;
	PrintLinkedListContents(*(para.ListAt(1)));
	PrintLinkedListContents(*(para.ListAt(102)));


}

void HashTableSimpleTest()
{
	cout << endl << "Entering HashTableSimpleTest...\n" << endl;

  // create a hash table with default constructor
  HashTable htdefault;

  // check that table size is expected (101)
  cout << "htdefault maxsize: " << htdefault.MaxSize() << endl;

  // insert an item (should hash to index 1)
  bool insertresult = htdefault.Insert("a");
  if (insertresult) cout << "string \"a\" successfully inserted." << endl;
  else cout << "string \"a\" not inserted." << endl;

  // check the contents of table at index 1
  cout << "Table contents at index 1: ";
  PrintLinkedListContents(*(htdefault.ListAt(1)));

  // insert another item (should hash to index 1)
  insertresult = htdefault.Insert("cf");
  if (insertresult) cout << "string \"cf\" successfully inserted." << endl;
  else cout << "string \"cf\" not inserted." << endl;

  // check the contents of table at index 1
  cout << "Table contents at index 1: ";
  PrintLinkedListContents(*(htdefault.ListAt(1)));

  // remove an item
  bool removeresult = htdefault.Remove("a");
  if (removeresult) cout << "string \"a\" successfully removed." << endl;
  else cout << "string \"a\" not removed." << endl;

  // check the contents of table at index 1
  cout << "Table contents at index 1: ";
  PrintLinkedListContents(*(htdefault.ListAt(1)));

  // search for existing and nonexistent strings
  string searchterm = "cf";
  if (htdefault.Search(searchterm)) cout << "htdefault contains " << searchterm << endl;
  else cout << "htdefault does not contain " << searchterm << endl;
  searchterm = "pleasetestallfunctions";
  if (htdefault.Search(searchterm)) cout << "htdefault contains " << searchterm << endl;
  else cout << "htdefault does not contain " << searchterm << endl;

  cout << "\nExiting HashTableSimpleTest...\n" << endl;
}

void PrintLinkedListContents(const LinkedList& ll)
{
  vector<string> v = ll.Dump();
  for (unsigned int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if (i < v.size() - 1) cout << ", ";
  }
  cout << endl;
}

