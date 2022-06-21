#pragma once
#include "przeciwnik.h"
#include "pet_cs.h"
#include "pet.h"

class RPS
{
private:
	przeciwnik enemy;
	pet_cs hero;
	int choice;

public:
	void set_hero(Pet pet);
	void Fmenu();
	bool winner();
};

