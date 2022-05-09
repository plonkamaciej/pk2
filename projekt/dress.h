#pragma once
#include"header.h"
#ifndef DRESS
#define DRESS

struct dress_ {
	string nazwa;
	int hp;
	int att;
};

	
class dress
{
	string nazwa;
	int hp;
	int att;

public:
	dress();
	ostream& operator<<(ostream& stm_wy) {
		stm_wy << nazwa << " " << hp << " " << att;
		return stm_wy;
	}

	istream& operator>>(istream& stm_we) {
		stm_we >> nazwa;
		stm_we >> hp;
		stm_we >> att;
		return stm_we;
}
};

#endif
