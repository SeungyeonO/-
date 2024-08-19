#pragma once
#include "NameCard.h"

#define LIST_LEN 100
typedef NameCard LData;

class ArrayList
{
private:
	LData arr[LIST_LEN];
	int numOfData;
	int CurPosition;

public:
	ArrayList();
	void LInsert(LData data);
	bool LFirst(LData& data);
	bool LNext(LData& data);
	LData LRemove();
	int LCount();
};

typedef ArrayList List;