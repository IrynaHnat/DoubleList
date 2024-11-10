
#include <iostream>
#include "DoubleLinked.h"
#include<string>
using namespace std;



int main()
{
	List<int> list;
	for (size_t i = 0; i < 5; i++)
	{
		list.addHead(rand() % 50);
	}
	list.print();
	cout << endl;
	list.printR();
	cout << "\n Remove :: \n";
	list.removeHead();
	list.print();
	list.printR();

	cout << "\nRemove Data:: \n";
	list.removeByData(34);
	list.print();
	list.printR();

	cout << "\nAdding elements at the tail:\n";
	for (size_t i = 0; i < 5; i++) {
		list.addTail(rand() % 50);
	}
	list.print();
	cout <<endl;

	cout << "\nRemove Tail :: \n";
	list.removeTail();
	list.print();
	list.printR();

	cout << "\nInserting 99 at position 2:\n";
	list.insertAt(99, 2);
	list.print();

	cout << "\nRemoving element at position 3:\n";
	list.removeAt(3);
	list.print();

	cout << "\nFinding position of element 99:\n";
	int pos = list.find(99);
	cout << (pos != -1 ? "Found at position " + to_string(pos) : "Not found") << endl;

	cout << "\nReplacing all occurrences of 99 with 100:\n";
	int replacements = list.replace(99, 100);
	cout << (replacements != -1 ? "Replaced " +to_string(replacements) + " occurrences" : "No replacements") << endl;
	list.print();

	cout << "\nReversing the list:\n";
	list.reverse();
	list.print();

	cout << "\nCopy constructing list:\n";
	List<int> copiedList(list);
	copiedList.print();
	cout << endl;

	cout << "\nAssigning list:\n";
	List<int> assignedList;
	assignedList = list;
	assignedList.print();

	cout << "\nClearing original list:\n";
	list.clear();
	list.print();

	cout << "\nCopied and assigned lists remain intact:\n";
	copiedList.print();
	assignedList.print();
}
