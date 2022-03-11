#pragma once
#include "przeciwnik.h"
#include "pet_cs.h"

class RPS
{
	przeciwnik enemy;
	pet_cs hero;
	int choice;

public:
	
	void Fmenu();
	bool winner();
};

