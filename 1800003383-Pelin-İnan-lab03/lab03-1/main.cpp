
#include<iostream>
#include"lab04doublyLinkedList template.h"

using namespace std;

int main() {

	int item;
	int order;
	int max;
	doublyLinkedList<int> list1, list2, insert;

	cout << "please enter the first element you want to add to the beginning of the list" << endl;
	cin >> item;

	while (!cin.eof()) {
		list1.insertFirst(item);
		cin >> item;
	}
	cin.clear();

	cout << "please enter the first element you want to add to the end of the list" << endl;
	cin >> item;

	while (!cin.eof()) {
		list2.insertFirst(item);
		cin >> item;
	}

	list1.print();
	list2.print();

	cout << "enter the number you want to add" << endl;
	cin >> item;
	cout << "enter the order you want to add" << endl;
	cin >> order;

	insert.insertAt(item, order);

	cout << "Please enter the node element you want to delete" << endl;
	cin >> item;

	insert.deleteItem(item);


	cout << "what should be the maximum value of the new list?" << endl;
	cin >> max;

	insert.extractMax(max);

	return 0;
}

