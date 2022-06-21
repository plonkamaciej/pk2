#include "dinozaur.h"
#include "extern.h"
#include "list.h"

void dinozaur::Talk()
{
	logs << "uruchomiono funkcje dinozaur::TALK" << endl;
	cout << Name << ": ARGHHHH!!" << endl;
	cout << R"(
    |\__/,|   (`\
  _.|o o  |_   ) )
-(((---(((--------

	)" << endl;

	PassTime();
}

void dinozaur::Eat()
{
	logs << "uruchomiono funkcje DINOZAUR::EAT" << endl;
	ifstream tmp("eatdino.txt");
	list<string> nazwa;
	list<int> value;
	string snazwa;
	int svalue;
	while (!tmp.eof()) {
		tmp >> snazwa;
		nazwa.push(snazwa);
		tmp >> svalue;
		value.push(svalue);
	}

	int i = rand() % value.size();
	cout << "Zjedzono " << nazwa[i] << ", odnowiono " << value[i] << " glodu" << endl;
	Hunger -= value[i];
	if (Hunger < 0)
		Hunger = 0;
	PassTime();
}

void dinozaur::operator--(int)
{
	Hunger = Hunger - 2;
	if (Hunger < 0)
		Hunger = 0;
	Boredom = Boredom - 4;
	if (Boredom < 0)
		Boredom = 0;
}


dinozaur::dinozaur(Pet &other)
{
		Name = other.GetName();
		Hunger = other.GetHunger();
		Boredom = other.GetBoredom();
		is_Sick = other.getSickness();
		Age = other.GetAge();
		is_alive = other.Getis_alive();
		dress_ = other.GetDress();
		typ = other.Get_type();
}

