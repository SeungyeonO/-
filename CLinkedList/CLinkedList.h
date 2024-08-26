#pragma once
#include "Staff.h"

typedef Staff* LData;

struct Node
{
	LData data;
	Node* next;
};

class CLinkedList
{
private:
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;

public:
	CLinkedList();
	~CLinkedList();
	void MakeEmpty();

	void LInsert(LData data);
	void LInsertFront(LData data);

	bool LFirst(LData& data);
	bool LNext(LData& data);

	LData LRemove();
	int LCount();
};

typedef CLinkedList List;