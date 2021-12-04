#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList <short> it;
	it.PushBack(111,1);
	it.PushBack(222,1);
	it.PushBack(333,1);

	
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
