#pragma once
#include <iostream>

using namespace std;

class User
{
private :
	string name;
	int hp;
	int x;
	int y;

public :
	void setName(string name);
	void printName();
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	void MoveDecreaseHP(int dec_hp);
	void doAttack();
	void moveUser(int x, int y);
	int GetHP();
	int GetX();
	int GetY();
	User();
	bool CheckUser(User user);
};