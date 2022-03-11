#pragma once
#include "header.h"
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
};

class Pet
{
private:

	string Name;
	int Hunger;
	int Boredom;
	bool is_Sick;
	double Age;
	bool is_alive;
	void PassTime(double time = 1);

public:

	Pet();
	void Set_name(string mName);
	bool getSickness() const;
	void Zapis();
	int GetMood() const;
	double GetAge() const;
	string GetName() const;
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	void Medicine(int medicine = 2);
	void HowOld();
	void DisplayStats();
	void clear();
};

#endif