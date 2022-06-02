#include "header.h"
#include "pet.h"
#include "dress.h"
#include "extern.h"
#include "node.h"

void Pet::Set_name(string mName){
	logs << "ustawiono imie peta" << endl;
	Name = mName;
}

void Pet::clear(){
	logs << "resetowanie statystyk peta" << endl;
	Name = "";
	Hunger = 0;
	Boredom = 0;
	is_Sick = 0;
	Age = 0;
	is_alive = 1;
	dress_ = dress("brak",0,0);
	
}

 void Pet::operator --(int)
{
	Hunger = Hunger - 2;
	if (Hunger < 0)
		Hunger = 0;
	Boredom = Boredom - 4;
	if (Boredom < 0)
		Boredom = 0;
	
}

spet getinfo()
{
	logs << "uruchomiono funkcje PET::GETINFO" << endl;
	spet info;
	ifstream petinfo("pet.txt");
	getline(petinfo, info.imie);
	petinfo >> info.Hunger;
	petinfo >> info.Boredom;
	petinfo >> info.is_Sick;
	petinfo >> info.Age;
	petinfo >> info.is_alive;
	petinfo >> info.sdress_.nazwa;
	petinfo >> info.sdress_.hp;
	petinfo >> info.sdress_.att;
	petinfo.close();
	return info;
}

Pet::Pet()
{
	logs << "konstruktor classy Pet" << endl;
	spet info = getinfo();
	Name = info.imie;
	Hunger = info.Hunger;
	Boredom = info.Boredom;
	is_Sick = info.is_Sick;
	Age = info.Age;
	is_alive = info.is_alive;
	dress_.set(info.sdress_.nazwa, info.sdress_.hp, info.sdress_.att);
}

void Pet::PassTime(double time)
{
	logs << "uruchomiono funkcje PET::PASSTIME" << endl;
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
	logs << "uruchomiono funkcje PET::DISPLAYSTATS" << endl;
	cout << "\nPoziom glodu: " << Hunger << endl;
	cout << "Poziom znudzenia: " << Boredom << endl;
	cout << "Chory: " << is_Sick << endl;
	cout << "Wiek: " << GetAge() << endl;
	cout << "Ubranie: " << GetDress() << endl;
}

void Pet::ChangeDress()
{
	logs << "uruchomiono funkcje PET::CHANGEDRESS" << endl;
	system("CLS");
	vector<dress> dresses;
	ifstream dresslist("dress.txt");
	dress tmp;
	string nazwa;
	int hp, att;
	while (!dresslist.eof()) {
		dresslist >> nazwa;
		dresslist >> hp;
		dresslist >> att;
		tmp.set(nazwa, hp, att);
		dresses.push_back(tmp);
	}

	Node* head;
	head -> constructList(dresses);

	cout << "wybierz stroj:";
	for (size_t i = 0; i < dresses.size(); i++)
	{
		cout << dresses[i] << endl;
	}
	
}

int Pet::GetMood() const
{
	logs << "uruchomiono funkcje PET::GETMOOD" << endl;
	return Hunger + Boredom + (int)is_Sick*10;
}

string Pet::GetName() const
{
	logs << "uruchomiono funkcje PET::GETNAME" << endl;
	return Name;
}

dress Pet::GetDress() const
{
	logs << "uruchomiono funkcje PET::GETDRESS" << endl;
	return dress_;
}

double Pet ::GetAge() const
{
	logs << "uruchomiono funkcje PET::GETAGE" << endl;
	return Age;
}

bool Pet::getSickness() const 
{
	logs << "uruchomiono funkcje PET::GETSICKNESS" << endl;
	return is_Sick;
}

void Pet::HowOld()
{
	logs << "uruchomiono funkcje PET::HOWOLD" << endl;
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
	logs << "uruchomiono funkcje PET::TALK" << endl;
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
	logs << "uruchomiono funkcje PET::EAT" << endl;
	cout << "Brruppp!\n";
	Hunger -= food;
	if (Hunger < 0)
		Hunger = 0;
	PassTime();
}

void Pet::Play(int fun)
{
	logs << "uruchomiono funkcje PAT::PLAY" << endl;
	cout << "Wheee!\n";
	Boredom -= fun;
	if (Boredom < 0)
		Boredom = 0;
	PassTime();
}

void Pet::Medicine(int medicine)
{
	logs << "uruchomiono funkcje PET::MEDICINE" << endl;
	cout << "Thanks!\n";
	is_Sick = false;
	PassTime();
}

int Pet::dressHP() const { 
	return dress_.dressHP();
};
int Pet::dressATT() const { 
	return dress_.dressATT();
};

void Pet::Zapis()
{
	ofstream petinfo("pet.txt");
	petinfo << Name << endl;
	petinfo << Hunger << endl;
	petinfo << Boredom << endl;
	petinfo << is_Sick << endl;
	petinfo << Age << endl;
	petinfo << is_alive << endl;
	petinfo << GetDress() << endl;
	logs << "uruchomiono funkcje PET::ZAPIS" << endl;
	logs << "----------- ZAMKNIECIE GRY" << endl;
	petinfo.close();
}