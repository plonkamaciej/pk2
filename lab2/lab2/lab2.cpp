#include <iostream>
#include <list>
#include "zespolona.h"

using namespace std;

int main()
{
    list<Zespolona> lista;
    Zespolona z1(0.9, 1.2);
    Zespolona z2(1.3, -2.1);
    lista.push_back(z1);
    lista.push_back(z2);
    cout << z1 - z2;
}
