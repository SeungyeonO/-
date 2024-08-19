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
	delete head; // ���̳�� �޸� ����
}


//LData�� �ּҰ��� �����ϰ� �ִٸ�(�����Ҵ�) ��� ó���ؾ� �ϴ°�?
//�ڷᱸ�� ���ο����� �ƴ϶� main�Լ����� ���� LRemove�� �ϸ� �׶��׶� ���尪�� ��������� �ϴ� �� ����.
//�����ϴ� ���� ���� ������ �ڷᱸ���� å���� �ƴϱ� �����̴�.
//���� ���� ���� ~LinkedList()�� �������� �ʰ� ���α׷� ���� ���� ���� ��������� �� ���̴�.

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