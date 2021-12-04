#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	PriorQ<string> myQ(10);

	cout << "         Check that pop() delete the first element first of all :" << endl << endl;

	myQ.Push("First data entered (means doesn't work)", 1);
	myQ.Push("2nd data entered (means works)", 1);
	myQ.Pop();
	cout << "***********************************************************" << endl;
	cout << "|   " << myQ.Front()->getData() << endl << endl;
	cout << "***********************************************************" << endl << endl << endl;
	myQ.Pop();

	cout << "         Priority Q in words: \n \n";
	myQ.Push("This ", 1);
	myQ.Push("Work ", 3);
	myQ.Push("Queue ", 2);
	myQ.Push("Should ", 2);
	myQ.Push("Priority ", 1);

	cout << "*************************************************************************************" << endl;
	while (myQ.getSize() > 0)
	{
		cout << "|   " << myQ.Front()->getData() << "( " << myQ.Front()->getPriority() << " ) ";
		myQ.Pop();
	}
	cout << "  |\n*************************************************************************************" << endl;

	return 0;
}
