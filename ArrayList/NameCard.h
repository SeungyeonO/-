#pragma once

#define NAME_LEN 30
#define PHONE_LEN 30

class NameCard
{
private:
	char name[NAME_LEN];
	char phone[PHONE_LEN];

public:
	//const char 형식오류: 프로젝트 속성 -> 언어 -> 준수모드 -> 아니요
	//메서드 정의에는 default 값을 쓰지 않는다.
	NameCard(char* _name, char* _phone);
	NameCard();
	void ShowNameCardInfo();
	int NameCompare(char* _name);
	void ChangePhoneNum(char* _phone);
};