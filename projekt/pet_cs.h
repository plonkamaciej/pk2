#pragma once
#include "przeciwnik.h"
class pet_cs : public przeciwnik
{
	int HP;
	int ATT;

public:
	pet_cs();
	int getHP() const;
	int getATT() const;
	int Attacked(int ATT);
	int ATT_ENEMY(int ATT);
};

