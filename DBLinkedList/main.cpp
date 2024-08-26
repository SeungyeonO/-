#include "DBLinkedList.h"
#include <iostream>

using namespace std;


int main()
{
	List list;
	int data;

	list.LInsert(11);
	list.LInsert(11);
	list.LInsert(22);
	list.LInsert(22);
	list.LInsert(33);

	if (list.LFirst(data))
	{
		cout << data << endl;

		while (list.LNext(data))
			cout << data << endl;
	}
	cout << endl;

	if (list.LFirst(data))
	{
		if (data == 22)
			list.LRemove();

		while (list.LNext(data))
		{
			if (data == 22)
				list.LRemove();
		}
	}

	if (list.LFirst(data))
	{
		cout << data << endl;

		while (list.LNext(data))
			cout << data << endl;
	}
	cout << endl;

}