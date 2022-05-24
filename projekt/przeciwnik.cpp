#include "header.h"
#include "przeciwnik.h"


int przeciwnik::ATT_ENEMY(int ATT) {
	int tmp = 0;
	int range = rand() % 5;
	if (range == 5) {
		cout << "CRIT!!" << endl;
		tmp = ATT * 2;
	}
	else tmp = ATT;
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