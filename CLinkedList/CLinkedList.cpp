#include <iostream>
using namespace std;

#include "CLinkedList.h"

CLinkedList::CLinkedList()
{
	tail = NULL;
	numOfData = 0;
}

CLinkedList::~CLinkedList()
{
	MakeEmpty();
}

void CLinkedList::MakeEmpty()
{
	LData data;
	if (LFirst(data))
	{
		LRemove();
		while (LNext(data))
			LRemove();
	}
}

void CLinkedList::LInsert(LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (tail == NULL)
	{
		tail = newNode;
		newNode->next = newNode;
	}

	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}

	numOfData++;
}

void CLinkedList::LInsertFront(LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (tail == NULL)
	{
		tail = newNode;
		newNode->next = newNode;
	}

	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
	}

	numOfData++;
}

bool CLinkedList::LFirst(LData& data)
{
	if (tail == NULL)
		return false;
	
	before = tail;
	cur = tail->next;
	data = cur->data;
	return true;
}

bool CLinkedList::LNext(LData& data)
{
	if (tail == NULL)
		return false;

	before = cur;
	cur = cur->next;
	data = cur->data;
	return true;
}

LData CLinkedList::LRemove()
{
	Node* rpos = cur;
	LData rdata = cur->data;

	if (rpos == tail)
	{
		if (numOfData == 1)
			tail = NULL;
		else
			tail = before;
	}

	before->next = rpos->next;
	cur = before;

	delete rpos;
	numOfData--;
	return rdata;
}

int CLinkedList::LCount()
{
	return numOfData;
}