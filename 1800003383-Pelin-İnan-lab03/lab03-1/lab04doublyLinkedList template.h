#pragma once
#include <iostream>

using namespace std;

//Definition of the node
template <class T>
struct nodeType
{
	T data;
	nodeType<T>* next;
	nodeType<T>* back;
};

template <class T>
class doublyLinkedList {
	nodeType<T>* head, * tail;
	int count;
public:
	doublyLinkedList();
	void insertFirst(T);           //defined 
	void insertLast(T);           // defined 
	void insertAt(T, int);        //defined 
	void print() const;
	void deleteItem(T);           // defined 
	doublyLinkedList<T>& extractMax(T); // defined
	~doublyLinkedList();
};

template <class T>
doublyLinkedList<T>::doublyLinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class T>
void doublyLinkedList<T>::insertFirst(T item)
{
	nodeType<T>* newNode;   //pointer to create the new node
	newNode = new nodeType;   //create new node
	newNode->back = NULL;     //the back of the node must be NULL
	newNode->data = item;     //store the new item in the node
	newNode->next = head;      //insert newNode before head
	head = newNode;             //make head of the list
	count++;                    //increment count

	if (tail == NULL) {        //if the list was empty, newNode is also  
		tail = newNode;          //the last node in the list

	}


}

template <class T>
void doublyLinkedList<T>::insertLast(T item)
{
	nodeType<T>* newNode;   //pointer to create the new node
	newNode = new nodeType;   //create new node
	newNode->data = item;     //store the new item in the node
	newNode->next = NULL;     //the next of the node must be NULL
	newNode->back = tail;

	if (tail == NULL) {          //if the list is epty, newnode is
		tail = newNode;          //both the first and last node
		head = newNode;
		count++;                //increment count
	}
	else {
		
		tail->next = newNode;            //insert newNode after last
		tail = newNode;              //make the new node as last node
		count++;                    //increment count

	}
	
}

template <class T>
void doublyLinkedList<T>::insertAt(T item, int order)
{

	nodeType<T>* current;            //pointer to traverse the list
	nodeType<T>* trailCurrent;        //pointer just before current
	nodeType<T>* newNode;            //pointer to create a node
	

	newNode = new nodeType<T>;  //create the new node
	newNode->info = item;   //store the new item in the node
	newNode->next = NULL;   //next i should be empty we will add it later
	newNode->back = order;        //take a order number

	if (head == NULL) {       //if list is empty
		head = newNode;        //newNode is the first node in the list
		tail = newNode;        //and the last node in the list
		count++;              //increment count 
	}
	else {
		current = head;            //if the list is not empty

		while (current != order) {   //and if not the order in which the node will be added
			trailCurrent = current;    //trailCurrent must follow current      
            current = current->next;  //so current must move and keeping search
		}

		newNode->back = NULL;        //first back is null
		newNode->next = current->next;  //then we add it to the queue
		current->back = newNode;
	}

	

}

template <class T>
void doublyLinkedList<T>::print() const
{
	nodeType<T>* cur;
	for (cur = head; cur != tail; cur = cur->next)
		cout << cur->data << " ";
	cout << cur->data << endl;
}

template <class T>
void doublyLinkedList<T>::deleteItem(T item)
{
	nodeType<T>* current;
	nodeType<T>* trailCurrent;

	if (head == NULL) {                                      //CASE1: Ýf the list is empty 
		cout << "Cannot delete from an empty list." << endl;   //"cannot delete from an empty list"

	}
	else if (head->data == item) {       //CASE2: if the item to be deleted is first node in list
		current = head;
		head = head->next;

		if (head != NULL) {         //if list is not empty
			head->back = NULL;       //head's back must be null
		}
		else
			tail = NULL;             

		count--;                  //Count must be decrase bacause we delete the node
		delete current;          //so the value current points to is deleted
	}

	else {
		current = head;

		while (current != NULL) {                      //CASE3:seacrh the list
			while (current->data != item) {	          // Ýf item is not in the head
				current = current->next;                  //current should move

				if (current->data == item) {              //if we found the item in the list
					trailCurrent = current;               //When we find the item in the list, TrailCurrent should point to the same node as current
					trailCurrent->next = current->next;   //cureent should be skipped
					if (current->next != NULL) {          //if the current is not last
						current->next->back = trailCurrent;    //current will be delete
					}if (current == last) {                  //if the current is last
						last = trailCurrent;                 //trailCurrent should also at the end
					}
					count--;                  //Count must be decrase bacause we delete the node
					delete current;          //so the value current points to is deleted
				}
			}
		}
	}
}
template <class T>
doublyLinkedList<T>& doublyLinkedList<T>::extractMax(T max)
{
	nodeType<T>* current;
	nodeType<T>* trailCurrent;
	nodeType<T>* newList;

	current = head;
	trailCurrent = head;

	while (current->data >= max && current->next!=NULL) {         //search the list if current data larger than max
		//and current next is not null because list is not single element

		trailCurrent = current;      //trailCurrent must follow current      
		current = current->next;     //so current must move and keeping search

		if (current ->data < max) {   //if we find value less than max

			trailCurrent = current->back;        //trailCurrent must follow current 
			trailCurrent->next = current->next;   //removing current from the list
			current->next->back = trailCurrent->next;  //traincurrent->next=current->next
			newList = current;                      //newlist poit current for make a new list
			if (newList = current) {              
				newList->next = newList;

		  }
			                                                  //if the element to be removed from the list  
			else if (current->data <= max && current->next = NULL) {   //is at the end of the list
				trailCurrent->next = NULL;                          //we add the element newlist
				newList->next = current;
			}
		}
	}
}

template <class T>
doublyLinkedList<T>::~doublyLinkedList()
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
