#include "user.h"

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

int User::GetHP() {
	return hp;
}
User::User() {
	hp = 20;;
}

bool User::CheckUser(User user) {
	if (user.GetHP() <= 0) {
		return false;
	}
	return true;
}