#pragma once

#define NAME_LEN 30
#define PHONE_LEN 30

class NameCard
{
private:
	char name[NAME_LEN];
	char phone[PHONE_LEN];

public:
	//const char ���Ŀ���: ������Ʈ �Ӽ� -> ��� -> �ؼ���� -> �ƴϿ�
	//�޼��� ���ǿ��� default ���� ���� �ʴ´�.
	NameCard(char* _name, char* _phone);
	NameCard();
	void ShowNameCardInfo();
	int NameCompare(char* _name);
	void ChangePhoneNum(char* _phone);
};