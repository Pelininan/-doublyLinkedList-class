#include<iostream>
#include"LİnkedList.h"

using namespace std;

int main() {

	int item;
	int pos;
	
	SinglyLinkedList<int> list1, list2, insert;

	cout << "please enter the first element you want to add to the beginning of the list" << endl;
	cin >> item;

	while (!cin.eof()) {
		list1.insertItemFirst(item);
		cin >> item;
	}
	cin.clear();

	cout << "please enter the first element you want to add to the end of the list" << endl;
	cin >> item;

	while (!cin.eof()) {
		list2.insertItemLast(item);
		cin >> item;
	}

	list1.print();
	list2.print();

	cout << "enter the number you want to add" << endl;
	cin >> item;
	cout << "enter the order you want to add" << endl;
	cin >> pos;

	insert.insertItem(item, pos);

	cout << "Please enter the node element you want to delete" << endl;
	cin >> item;

	insert.deleteItem(item);


	return 0;
}

