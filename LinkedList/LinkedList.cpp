#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	Node* dummyNode = new Node;
	dummyNode->next = NULL;

	head = dummyNode;
	before = NULL;
	cur = NULL;
	numOfData = 0;
	comp = NULL;

}

LinkedList::~LinkedList()
{
	MakeEmpty();
	delete head; // 더미노드 메모리 해제
}


//LData가 주소값을 저장하고 있다면(동적할당) 어떻게 처리해야 하는가?
//자료구조 내부에서가 아니라 main함수에서 직접 LRemove를 하며 그때그때 저장값도 해제해줘야 하는 것 같다.
//저장하는 값에 대한 해제는 자료구조의 책임이 아니기 때문이다.
//위와 같은 경우는 ~LinkedList()에 의존하지 않고 프로그램 종료 전에 직접 삭제해줘야 할 것이다.

void LinkedList::MakeEmpty()
{
	LData data;
	if (LFirst(data))
	{
		LRemove();

		while (LNext(data))
			LRemove();
	}
}

void LinkedList::LInsert(LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (comp == NULL)
	{
		newNode->next = head->next;
		head->next = newNode;
	}

	else
	{
		Node* pred = head;
		
		if (pred->next != NULL && comp(data, pred->next->data) != 0)
		{
			pred = pred->next;
		}

		newNode->next = pred->next;
		pred->next = newNode;
	}

	numOfData++;
}

bool LinkedList::LFirst(LData& data)
{
	if (numOfData == 0)
		return false;

	before = head;
	cur = head->next;
	data = cur->data;
	return true;
}

bool LinkedList::LNext(LData& data)
{
	if (cur->next == NULL)
		return false;

	before = cur;
	cur = cur->next;
	data = cur->data;
	return true;
}

LData LinkedList::LRemove()
{
	Node* rNode = cur;
	LData rData = rNode->data;

	before->next = cur->next;
	cur = before;

	delete rNode;
	numOfData--;
	
	return rData;
}

int LinkedList::LCount()
{
	return numOfData;
}

void LinkedList::SetSortRule(int (*_comp)(LData d1, LData d2))
{
	comp = _comp;
}