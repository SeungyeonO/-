#include "Staff.h"
#include <iostream>

Staff::Staff(string _name, int _ID)
{
	name = _name;
	ID = _ID;
}

string Staff::getName()
{
	return name;
}

int Staff::getID()
{
	return ID;
}

void Staff::ShowStaffInfo()
{
	cout << "ÀÌ¸§: " << name << endl;
	cout << "ID: " << ID << endl;
}