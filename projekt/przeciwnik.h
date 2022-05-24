#pragma once
class przeciwnik
{
	int HP;
	int ATT;

public:
	przeciwnik();
	int ATT_ENEMY(int ATT);
	virtual int getHP() const;
	virtual int getATT() const;
	int Attacked(int ATT);
};

