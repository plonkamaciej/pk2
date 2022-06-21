#pragma once
class przeciwnik
{
	int HP;
	int ATT;

public:
	przeciwnik();
	virtual int ATT_ENEMY(int ATT);
	virtual int getHP() const;
	virtual int getATT() const;
	virtual int Attacked(int ATT);
};

