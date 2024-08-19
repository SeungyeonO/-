#include <iostream>
#include "NameCard.h"

using namespace std;

NameCard::NameCard(char* _name, char* _phone)
{
	strcpy_s(name, _name);
	strcpy_s(phone, _phone);
}

NameCard::NameCard()
{
	strcpy_s(name, " ");
	strcpy_s(phone, " ");
}

void NameCard::ShowNameCardInfo()
{
	cout << "이름: " << name << endl;
	cout << "전화번호: " << phone << endl;
}

int NameCard::NameCompare(char* _name)
{
	return strcmp(name, _name);
}

void NameCard::ChangePhoneNum(char* _phone)
{
	strcpy_s(phone, _phone);
}

char* NameCard::getName()
{
	return name;
}

