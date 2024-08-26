#pragma once

typedef int LData;

struct Node
{
	LData data;
	Node* next;
	Node* prev;
};


//head�� tail�� dummyNode�� �ִ� ���Ḯ��Ʈ
class DBLinkedList
{
private:
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;

public:
	DBLinkedList();
	~DBLinkedList();
	void MakeEmpty();

	void LInsert(LData data);//������ �� ��� �߰�
	bool LFirst(LData& data);
	bool LNext(LData& data);
	bool LPrevious(LData& data);
	LData LRemove();
	int LCount();

};

typedef DBLinkedList List;
