#include "pies.h"
#include "extern.h"
#include "list.h"

pies::pies(Pet& other)
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



void pies::Talk()
{
	logs << "uruchomiono funkcje pies::TALK" << endl;
	cout << Name << ": woof woof!" << endl;
	cout << R"(
    |\__/,|   (`\
  _.|o o  |_   ) )
-(((---(((--------

	)" << endl;

	PassTime();
}

void pies::Eat(int food)
{
	logs << "uruchomiono funkcje PIES::EAT" << endl;
	ifstream tmp("eatpies.txt");
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

void pies::operator--(int)
{
	Hunger = Hunger - 2;
	if (Hunger < 0)
		Hunger = 0;
	Boredom = Boredom - 4;
	if (Boredom < 0)
		Boredom = 0;
}
