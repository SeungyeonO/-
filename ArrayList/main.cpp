#include <iostream>
#include "ArrayList.h"
#include "NameCard.h"

using namespace std;

int main()
{
//--------------int를 저장하는 List-------------------
/*
	List list;
	int data;

	list.LInsert(11);
	list.LInsert(11);
	list.LInsert(22);
	list.LInsert(22);
	list.LInsert(33);

	cout << "현재 데이터의 수: " << list.LCount() << endl;

	if (list.LFirst(data))
	{
		cout << data << " ";

		while (list.LNext(data))
			cout << data << " ";
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

	cout << "현재 데이터 수: " << list.LCount() << endl;

	if (list.LFirst(data))
	{
		cout << data << " ";

		while (list.LNext(data))
			cout << data << " ";
	}

	cout << endl;
*/

//--------------NameCard를 저장하는 List-----------------------

	NameCard namecard1("John", "111");
	NameCard namecard2("Peter", "222");
	NameCard namecard3("Sera", "333");
	NameCard namecard4("Shawn", "444");
	NameCard namecard5("Alex", "555");

	List list;
	NameCard data;

	list.LInsert(namecard1);
	list.LInsert(namecard2);
	list.LInsert(namecard3);
	list.LInsert(namecard4);
	list.LInsert(namecard5);

	cout << "현재 데이터의 수: " << list.LCount() << endl;

	if (list.LFirst(data))
	{
		data.ShowNameCardInfo();

		while (list.LNext(data))
			data.ShowNameCardInfo();
	}
	cout << endl;

		if (list.LFirst(data))
	{
		if (!data.NameCompare("Sera"))
			list.LRemove();

		while (list.LNext(data))
		{
			if (!data.NameCompare("Sera"))
				list.LRemove();
		}
	}

	cout << "현재 데이터의 수: " << list.LCount() << endl;

	if (list.LFirst(data))
	{
		data.ShowNameCardInfo();

		while (list.LNext(data))
			data.ShowNameCardInfo();
	}
	cout << endl;


	return 0;
}