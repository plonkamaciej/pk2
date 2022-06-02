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
	dress(string mnazwa, int mhp, int matt) {
		nazwa = mnazwa;
		hp = mhp;
		att = matt;
	}

	int dressHP() const;
	int dressATT() const;
	void set(string mnazwa, int mhp, int matt);

	friend ostream& operator<<(ostream& os, const dress& dt);

};

#endif
