#include "dress.h"
#include "header.h"
#include "extern.h"

#ifndef PET_H
#define PET_H

struct spet
{
	string imie = "";
	int Hunger = 0;
	int Boredom = 0;
	bool is_Sick = 0;
	double Age = 0;
	bool is_alive = 0;
	dress_ sdress_;
	int typ = 0;
};

class Pet
{
protected:

	string Name;
	int Hunger;
	int Boredom;
	bool is_Sick;
	double Age;
	bool is_alive;
	dress dress_;
	int typ;

public:

	Pet();
	
	void PassTime(double time = 1);
	void Set_name(string mName);
	void Set_sickness(bool sick);
	void Set_type(int mtyp);
	bool getSickness() const;
	void Zapis();
	int Get_type() const;
	int GetHunger() const;
	int GetBoredom() const;
	bool Getis_alive() const;
	int GetMood() const;
	double GetAge() const;
	string GetName() const;
	dress GetDress() const;
	virtual void Talk();
	virtual void Eat(int food = 4);
	void Play(int fun = 4);
	void Medicine();
	void HowOld();
	void DisplayStats();
	void ChangeDress();
	void clear();
	void operator -- (int);
	friend ostream& operator<<(ostream& os, const Pet& dt);
	int dressHP() const;
	int dressATT() const;
};

#endif