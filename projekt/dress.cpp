#include "dress.h"
#include "extern.h"

vector<dress_> getinfod() {
	vector<dress_> info;
	dress_ tmp;
	ifstream petinfo("dress.txt");
	while (!petinfo.eof()) {
		getline(petinfo, tmp.nazwa);
		petinfo >> tmp.hp;
		petinfo >> tmp.att;
		info.push_back(tmp);
	}
	petinfo.close();
	return info;
}

dress::dress() {};

void dress::set(string mnazwa, int mhp, int matt)
{
	logs << "uruchomiono funkcje DRESS::SETDRESS" << endl;
	nazwa = mnazwa;
	hp = mhp;
	att = matt;
};

string dress::dressName() const {
	return nazwa;
};

int dress::dressHP() const {
	return hp;
};

int dress::dressATT() const {
	return att;
}

ostream& operator<<(ostream& os, const dress& dt)
{
	os << dt.nazwa << " " << dt.hp << " " << dt.att;
	return os;
}