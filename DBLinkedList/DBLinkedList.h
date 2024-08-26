#pragma once

typedef int LData;

struct Node
{
	LData data;
	Node* next;
	Node* prev;
};


//head와 tail에 dummyNode가 있는 연결리스트
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

	void LInsert(LData data);//꼬리에 새 노드 추가
	bool LFirst(LData& data);
	bool LNext(LData& data);
	bool LPrevious(LData& data);
	LData LRemove();
	int LCount();

};

typedef DBLinkedList List;
