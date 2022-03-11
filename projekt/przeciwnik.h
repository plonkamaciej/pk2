#pragma once
class przeciwnik
{
	int HP;
	int ATT;

public:
	przeciwnik();
	int ATT_ENEMY(int ATT);
	int getHP() const;
	int getATT() const;
	int Attacked(int ATT);
};

