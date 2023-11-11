#pragma once
#include <iostream>

using namespace std;

class User
{
public :
	int hp;

public :
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	void MoveDecreaseHP(int dec_hp);
	int GetHP();
};

