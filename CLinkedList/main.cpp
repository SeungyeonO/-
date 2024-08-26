#include <iostream>
#include <string>
#include "Staff.h"
#include "CLinkedList.h"

using namespace std;

Staff* WhoIsNightDuty(List& list, string name, int day);

int main()
{
	Staff* staff;
	List list;

	staff = new Staff("John", 1);
	list.LInsert(staff);

	staff = new Staff("Alex", 2);
	list.LInsert(staff);

	staff = new Staff("Paul", 3);
	list.LInsert(staff);

	staff = new Staff("Mike", 4);
	list.LInsert(staff);


	list.LFirst(staff);
	staff->ShowStaffInfo();
	for (int i = 0; i < 3; i++)
	{
		list.LNext(staff);
		staff->ShowStaffInfo();
	}
	cout << endl;

	WhoIsNightDuty(list, "Alex", 5);

	
	list.LFirst(staff);
	staff = list.LRemove();
	delete staff;

	while (list.LNext(staff))
	{
		staff = list.LRemove();
		delete staff;
	}

	return 0;
}


Staff* WhoIsNightDuty(List& list, string name, int day)
{
	int num = list.LCount();
	int i;
	Staff* ret;

	if (num == 0)
		return NULL;


	list.LFirst(ret);

	if (ret->getName() != name)
	{
		for (i = 0; i < num - 1; i++)
		{
			list.LNext(ret);
			if (ret->getName() == name)
				break;
		}

		if (i >= num - 1)
			return NULL;
	}


	for (int i = 0; i < day; i++)
	{
		list.LNext(ret);
	}

	ret->ShowStaffInfo();
	return ret;
}