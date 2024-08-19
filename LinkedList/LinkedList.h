#pragma once
#include "NameCard.h"

typedef NameCard LData;

struct Node
{
	LData data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
	Node* cur;
	Node* before; //삭제를 돕는 멤버 변수
	int numOfData;
	int (*comp)(LData d1, LData d2);

public:
	LinkedList();
	~LinkedList();
	void MakeEmpty();

	void LInsert(LData data);
	bool LFirst(LData& data);
	bool LNext(LData& data);
	LData LRemove();
	int LCount();

	void SetSortRule(int (*comp)(LData d1, LData d2));
	// 인자: d1이 우선이면 0을, d2가 우선이면 1을 반환하는 비교함수의 주소값
};

typedef LinkedList List;