#pragma once
#include "przeciwnik.h"
#include "pet.h"

class pet_cs : public przeciwnik
{
	int HP;
	int ATT;

public:
	
	void set(Pet pet);
	int getHP() const;
	int getATT() const;
	int Attacked(int ATT);
	int ATT_ENEMY(int ATT);
};

