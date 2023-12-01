#include "user.h"

void User::setName(string name) {
	this->name = name;
}

void User::printName() {
	cout << name;
}

void User::DecreaseHP(int dec_hp) {
	dec_hp -= 2;
	hp = dec_hp;
}

void User::IncreaseHP(int inc_hp) {
	inc_hp += 2;
	hp = inc_hp;
}
void User::MoveDecreaseHP(int dec_hp) {
	dec_hp--;
	hp = dec_hp;
}

void User::doAttack() {
	cout << "공격합니다" << endl;
}

void User::moveUser(int x, int y) {
	this->x += x;
	this->y += y;
}

int User::GetHP() {
	return hp;
}

int User::GetX() {
	return x;
}

int User::GetY() {
	return y;
}

User::User() {
	hp = 20;
	x = 0;
	y = 0;
}