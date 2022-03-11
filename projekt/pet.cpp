#include "header.h"
#include "pet.h"

void Pet::Set_name(string mName){
	Name = mName;
}

void Pet::clear(){
	Name = "";
	Hunger = 0;
	Boredom = 0;
	is_Sick = 0;
	Age = 0;
	is_alive = 1;
}

spet getinfo()
{
	spet info;
	ifstream petinfo("pet.txt");
	getline(petinfo, info.imie);
	petinfo >> info.Hunger;
	petinfo >> info.Boredom;
	petinfo >> info.is_Sick;
	petinfo >> info.Age;
	petinfo >> info.is_alive;
	petinfo.close();
	return info;
}

Pet::Pet()
{
	spet info = getinfo();
	Name = info.imie;
	Hunger = info.Hunger;
	Boredom = info.Boredom;
	is_Sick = info.is_Sick;
	Age = info.Age;
	is_alive = info.is_alive;
}

void Pet::PassTime(double time)
{
	int sick = rand() % 10;
	Hunger += time;
	Boredom += time;
	if (sick == 0)
	{
		is_Sick = true;
	}
	Age += time / 10;
}

void Pet::DisplayStats()
{
	cout << "\nPoziom glodu: " << Hunger << endl;
	cout << "Poziom znudzenia: " << Boredom << endl;
	cout << "Chory: " << is_Sick << endl;
	cout << "Wiek: " << GetAge() << endl;
}

int Pet::GetMood() const
{
	return Hunger + Boredom;
}

string Pet::GetName() const
{
	return Name;
}

double Pet ::GetAge() const
{
	return Age;
}

bool Pet::getSickness() const 
{
	return is_Sick;
}

void Pet::HowOld()
{
	double age = GetAge();

	if (age > 5.0)
	{
		cout << Name << " jest juz dorosly." << endl;
	}
	else if (age > 1.0)
	{
		cout << Name << " ostatnio urosl." << endl;
	}
	else if (age < 1.0)
	{
		cout << Name << " jest jeszcze mały" << endl;
	}
}
void Pet::Talk()
{
	cout << Name << ": braaah" << endl;
	cout << R"(
    |\__/,|   (`\
  _.|o o  |_   ) )
-(((---(((--------

	)" << endl;

	PassTime();
}

void Pet::Eat(int food)
{
	cout << "Brruppp!\n";
	Hunger -= food;
	if (Hunger < 0)
		Hunger = 0;
	PassTime();
}

void Pet::Play(int fun)
{
	cout << "Wheee!\n";
	Boredom -= fun;
	if (Boredom < 0)
		Boredom = 0;
	PassTime();
}

void Pet::Medicine(int medicine)
{
	cout << "Thanks!\n";
	is_Sick = false;
	PassTime();
}



void Pet::Zapis()
{
	ofstream petinfo("pet.txt");
	petinfo << Name << endl;
	petinfo << Hunger << endl;
	petinfo << Boredom << endl;
	petinfo << is_Sick << endl;
	petinfo << Age << endl;
	petinfo << is_alive << endl;
	petinfo.close();
}