#pragma once
#include <iostream>

using namespace std;

class User
{
private:
	int hp;

public:
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	void MoveDecreaseHP(int dec_hp);
	int GetHP();
	User();
	bool CheckUser(User user);
};