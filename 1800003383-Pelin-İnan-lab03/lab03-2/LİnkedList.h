#pragma once
#include <iostream>
using namespace std;

template <class T>
class SinglyLinkedList {
	nodeType<T>* head, * tail;
	int count;
public:
	SinglyLinkedList();  
	void insertItemFirst(T item);
	void insertItemLast(T item);
	void insertItem(T item, int pos);
	void deleteItem(T item);
	void print();
	~SinglyLinkedList();
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}
template <class T>
void SinglyLinkedList<T>:: insertItemFirst(T item){

	nodeType<T>* temp;                //create new temp pointer
	nodeType<T>* newNode = new nodeType<T>;       //create new pointer
	newNode->data = item;               //will keep item in its data
	newNode->next = NULL;                //null for now then it will show elsewhere
	if (head == NULL) {             //check the list is empty or not
		head = newNode;
		newNode->next = head;
		count++;
	}
	else {
		 temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = newNode;
		newNode->next = head;
		head = newNode;
		count++;
	}
}
template <class T>
void SinglyLinkedList<T>::insertItemLast(T item) {

	nodeType<T>* temp;
	nodeType<T>* newNode = new nodeType<T>;
	newNode->data = item;
	newNode->next = NULL;
	if (head == NULL) {
		head = newNode;
		newNode->next = head;
		count++;
	}

	else {
		tail = head;
		while (tail->next != head && tail->next = NULL) {
			tail = tail->next;
			tail->next = newNode;
			newNode->next = head;
			count++;
		}
	}

}


template <class T>
void SinglyLinkedList<T>::insertItem(T item, int pos)
{
	if (pos == 0)
		insertFirst(item);
	else if (pos >= count - 1)
		insertLast(item);
	else {
		nodeType<T>* newNode = new nodeType<T>;
		newNode->data = item;
		nodeType<T>* cur = head;
		for (int i = 0; i < pos - 1; i++, cur = cur->next);
		newNode->next = cur->next;
		cur->next = newNode;
	}
	count++;
}

template <class T>
void SinglyLinkedList<T>::deleteItem(T item) {

	nodeType<T>* newNode;
	nodeType<T>* temp;

	if (tail == NULL) {           //if tail isequal to NULL then simply 
		return tail;              //return tail
	}
	else {
		temp = tail->next;            //temp is equal to tail next
	}

	if (tail->next == tail) {           // just one node in the list and just free that node
		delete tail;
	}

	while (newNode->data >= item) {   // if the value in data is larger than the value to be deleted
		newNode = newNode->next;      //keeping seacrh
		item--;                      //decrease item

	}
	temp = temp->next;                   //if  it gets out of the loop
	newNode->next = temp->next;          //temp point to temp->next
	                                     //and newNode->next point temp->next
	 
	delete temp;                          //delete temp

}

template <class T>
void SinglyLinkedList<T>::print()
{
	LinkedListIterator<T> cur, end;
	for (; cur != end; ++cur)  //cur point head
		cout << *cur << " "; //end point the tail
	cout << *cur << endl;    //search list and print
}


template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	nodeType<T>* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
	count = 0;
}