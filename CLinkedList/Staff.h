#pragma once
#include <string>
using namespace std;

class Staff
{
private:
	string name;
	int ID;

public:
	Staff(string _name, int _ID);
	string getName();
	int getID();
	void ShowStaffInfo();
};