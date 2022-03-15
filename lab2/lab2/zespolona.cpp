#include "zespolona.h"
#include <iostream>

Zespolona::Zespolona(const Zespolona& zesp) {
    Re = zesp.Re;
    Im = zesp.Im;
}


Zespolona& Zespolona::operator = (const Zespolona& zesp) {
    Re = zesp.Re;
    Im = zesp.Im;
    return *this;
}


Zespolona Zespolona::operator + (const Zespolona& zesp) {
    Zespolona tmp;
    tmp.Re = Re + zesp.Re;
    tmp.Im = Im + zesp.Im;
    return tmp;
}


Zespolona Zespolona::operator - (const Zespolona& zesp) {
    Zespolona tmp;
    tmp.Re = Re - zesp.Re;
    tmp.Im = Im - zesp.Im;
    return tmp;
}


Zespolona Zespolona::operator * (const Zespolona& zesp) {
    Zespolona tmp;
    tmp.Re = Re * zesp.Re - Im * zesp.Im;
    tmp.Im = Re * zesp.Im + Im * zesp.Re;
    return tmp;
}


Zespolona Zespolona::operator / (const Zespolona& zesp) {
    Zespolona tmp;
    double mianownik = zesp.Re * zesp.Re + zesp.Im * zesp.Im;
    tmp.Re = (Re * zesp.Re + Im * zesp.Im) / mianownik;
    tmp.Im = (Im * zesp.Re - Re * zesp.Im) / mianownik;
    return tmp;
}


double& Zespolona::operator [] (int i)
{
    if (i == 0) return Re;
    else if (i == 1) return Im;
}

std::istream& operator >> (std::istream& os, Zespolona& ze)
{
    std::cout << "Enter Real Part ";
    os >> ze.Re;
    std::cout << "Enter Imaginary Part ";
    os >> ze.Im;
    return os;
}

std::ostream& operator << (std::ostream& os, const Zespolona& ze)
{
    os << ze.Re << ' ' << ze.Im << 'i';
    return os;
}
