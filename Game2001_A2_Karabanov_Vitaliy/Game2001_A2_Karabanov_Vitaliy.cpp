#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList <short> it;
	it.PushBack(111);
	it.PushBack(222);
	it.PushBack(333);

	
	LinkedIterator<short> x;

	for (x = it.Begin(); x != it.End(); x++)
	{
		cout << " " << *x << endl;
	}
	it.Pop();
	cout << "Now after pop(front)" << endl;

	for (x = it.Begin(); x != it.End(); x++)
	{
		cout << " " << *x << endl;
	}
	return 0;
}
