#include "header.h"
#include "przeciwnik.h"


int przeciwnik::ATT_ENEMY(int ATT) {
	int range = rand() % 2;
	int tmp = ATT + range*ATT;
	if (range) cout << "CRIT!!" << endl;
	return tmp;
}


przeciwnik::przeciwnik() {
	
	HP = rand() % 41 + 50;
	ATT = rand() % 11 + 10;
}

int przeciwnik::getHP() const {
	return HP;
}

int przeciwnik::getATT() const {
	return ATT;
}

int przeciwnik::Attacked(int ATT) {
	return HP -= ATT_ENEMY(ATT);
}