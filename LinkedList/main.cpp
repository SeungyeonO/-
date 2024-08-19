#include <iostream>
#include "LinkedList.h"
#include "NameCard.h"

using namespace std;


//이름 기준 오름차순으로 정렬하기 위한 정렬 기준 결정 함수
int WhoIsPrecede(NameCard d1, NameCard d2)
{
	char* name1 = d1.getName();
	char* name2 = d2.getName();

	if (strcmp(name1, name2) <= 0)
		return 0;
	else
		return 1;
}


int main()
{
	NameCard namecard1("John", "111");
	NameCard namecard2("Peter", "222");
	NameCard namecard3("Sera", "333");
	NameCard namecard4("Shawn", "444");
	NameCard namecard5("Alex", "555");

	List list;
	list.SetSortRule(&WhoIsPrecede);
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