#include "dress.h"

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

dress::dress()
{
	
}
