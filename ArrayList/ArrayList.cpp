#include "ArrayList.h"

ArrayList::ArrayList()
{
	numOfData = 0;
	CurPosition = -1;
}

void ArrayList::LInsert(LData data)
{
	arr[numOfData] = data;
	numOfData++;
}

bool ArrayList::LFirst(LData& data)
{
	if (numOfData == 0)
		return false;

	CurPosition = 0;
	data = arr[CurPosition];
	return true;
}

bool ArrayList::LNext(LData& data)
{
	if (CurPosition >= (numOfData - 1))
		return false;

	CurPosition++;
	data = arr[CurPosition];
	return true;
}

LData ArrayList::LRemove()
{
	int rpos = CurPosition;
	LData rdata = arr[rpos];

	for (int i = rpos; i < numOfData; i++)
		arr[i] = arr[i + 1];

	numOfData--;
	CurPosition--;
	return rdata;
}

int ArrayList::LCount()
{
	return numOfData;
}