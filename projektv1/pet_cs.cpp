#include "pet_cs.h"
#include "extern.h"
#include "dress.h"


int pet_cs::getHP() const {
	logs << "uruchomiono funkcje pet_cs::GETHP" << endl;
	return HP;
}

int pet_cs::getATT() const {
	logs << "uruchomiono funkcje pet_cs::GETATT" << endl;
	return ATT;
}


int pet_cs::Attacked(int ATT) {
	logs << "uruchomiono funkcje pet_cs::ATTACKED" << endl;
	return HP -= ATT_ENEMY(ATT);
}

int pet_cs::ATT_ENEMY(int ATT) {
	logs << "uruchomiono funkcje pet_cs::ATT_ENEMY" << endl;
	int tmp = 0;
	int range = rand() % 4;
	if (range == 4) {
		cout << "CRIT!!" << endl;
		tmp = ATT * 2;
	}
	else tmp = ATT;
	return tmp;
}

void pet_cs::set(Pet pet)
{
	dress stats = pet.GetDress();
	this ->HP = 100 - pet.GetMood() + pet.dressHP();
	this ->ATT = 25 - pet.GetMood() + pet.dressATT();

}
