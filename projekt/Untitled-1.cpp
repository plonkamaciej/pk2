#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct dress_ {
	string nazwa;
	int hp;
	int att;
};

	
class dress
{
	string nazwa;
	int hp;
	int att;

public:
	dress();
};



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

int main(){
    return 0;
    vector<dress_> vec = getinfod();
    cout << vec[1].nazwa;
}