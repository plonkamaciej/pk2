#ifndef _ZESPOLONA_H_
#define _ZESPOLONA_H_
#include <iostream>


class Zespolona {
    double Re, Im;
public:
    Zespolona() :Re(0.0), Im(0.0) {};
    Zespolona(double re, double im) { Re = re; Im = im; };
    Zespolona(const Zespolona& zesp);
    void set(double re, double im) { Re = re; Im = im; };
    double getRe() { return Re; };
    void setRe(double re) { Re = re; };
    double GetIm() { return Im; };
    void setIm(double im) { Im = im; };
    Zespolona& operator = (const Zespolona& zesp);
    Zespolona  operator + (const Zespolona& zesp);
    Zespolona  operator - (const Zespolona& zesp);
    Zespolona  operator * (const Zespolona& zesp);
    Zespolona  operator / (const Zespolona& zesp);
    double& operator [] (int i);
    Zespolona& operator += (const Zespolona& zesp) { *this = *this + zesp; return *this; };
    Zespolona& operator -= (const Zespolona& zesp) { *this = *this - zesp; return *this; };
    Zespolona& operator *= (const Zespolona& zesp) { *this = *this * zesp; return *this; };
    Zespolona& operator /= (const Zespolona& zesp) { *this = *this / zesp; return *this; };
    friend std::istream& operator >> (std::istream& os, Zespolona& ze);
    friend std::ostream& operator << (std::ostream& os, const Zespolona& ze);
};

#endif

