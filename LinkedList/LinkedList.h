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
	Node* before; //������ ���� ��� ����
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
	// ����: d1�� �켱�̸� 0��, d2�� �켱�̸� 1�� ��ȯ�ϴ� ���Լ��� �ּҰ�
};

typedef LinkedList List;