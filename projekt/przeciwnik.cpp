#include "header.h"
#include "przeciwnik.h"
#include "extern.h"
	
int przeciwnik::ATT_ENEMY(int ATT) {
	logs << "uruchomiono funkcje pet_cs::ATT_ENEMY" << endl;
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
	logs << "uruchomiono funkcje PRZECIWNIK::GETHP" << endl;
	return HP;
}

int przeciwnik::getATT() const {
	logs << "uruchomiono funkcje PRZECIWNIK::GETATT" << endl;
	return ATT;
}

int przeciwnik::Attacked(int ATT) {
	logs << "uruchomiono funkcje PRZECIWNIK::ATTACKED" << endl;
	return HP -= ATT_ENEMY(ATT);
}