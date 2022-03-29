#include <iostream>
using namespace std;

class Radio {
public:
    bool stan;
    int kanal;
};

class Silnik {
public:
    bool stan;
    int szybkosc;
    int identyfikator;

private:
    Silnik& operator=(const Silnik& n) {

        stan = n.stan;
        szybkosc = n.szybkosc;
        identyfikator = n.identyfikator;
        
        return *this;
    }
};

class Samolot {

public:
    Radio& pradio;
    Silnik psilnik;
    double paliwo;
    double dystans;
    double x;
    double y;
    double z;
    double wysokosc;
    char* Sygnatura;
    const double masa;

    Samolot();
    Samolot(double mpaliwo, double mdystans, double mx, double my, double mz, double mwysokosc) {
        this->paliwo = mpaliwo;
        this->dystans = mdystans;
        this->x = mx;
        this->y = my;
        this->z = mz;
        this->wysokosc = mwysokosc;
        cout << "konstruktor wieloargumentowy\n";
    }

    Samolot& operator=(const Samolot& n) {
        
        paliwo = n.paliwo;
        dystans = n.dystans;
        x = n.x;
        y = n.y;
        z = n.z;
        wysokosc = n.wysokosc;
        return *this;
    }

};

void f5(Samolot s1) {
    cout << s1.x << " " << s1.z << " " << s1.z << endl;
}

Samolot f6(Samolot s1, double w) {
    s1.wysokosc -= w;
    return s1;
}


int main()
{
    Samolot s1;
    Samolot s2;
    
    s1.dystans = 1000;
    s1.paliwo = 20000;
    s1.x = 10.2;
    s1.y = 20.4;
    s1.z = 90.11;
    s1.wysokosc = 1000;
    f5(s1);
    f6(s1, 100);
    s2 = s1;
}