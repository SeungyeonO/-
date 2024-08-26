#include "DBLinkedList.h"
#include <iostream>

using namespace std;


DBLinkedList::DBLinkedList()
{
	head = new Node;
	tail = new Node;

	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	tail->next = NULL;

	numOfData = 0;
}

DBLinkedList::~DBLinkedList()
{
	MakeEmpty();
	delete head;
	delete tail;
}

void DBLinkedList::MakeEmpty()
{
	LData data;
	if (LFirst(data))
	{
		LRemove();
		while (LNext(data))
			LRemove();
	}
}

void DBLinkedList::LInsert(LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->prev = tail->prev;
	tail->prev = newNode;
	newNode->prev->next = newNode;
	newNode->next = tail;

	numOfData++;
}

bool DBLinkedList::LFirst(LData& data)
{
	if (numOfData == 0)
		return false;
	
	cur = head->next;
	data = cur->data;
	return true;
}

bool DBLinkedList::LNext(LData& data)
{
	if (cur->next == tail)
		return false;

	cur = cur->next;
	data = cur->data;
	return true;
}

bool DBLinkedList::LPrevious(LData& data)
{
	if (cur->prev == head)
		return false;
	
	cur = cur->prev;
	data = cur->data;
	return true;
}

LData DBLinkedList::LRemove()
{
	Node* rpos = cur;
	LData rdata = rpos->data;

	rpos->prev->next = rpos->next;
	rpos->next->prev = rpos->prev;

	cur = cur->prev;

	delete rpos;
	numOfData--;

	return rdata;
}

int DBLinkedList::LCount()
{
	return numOfData;
}