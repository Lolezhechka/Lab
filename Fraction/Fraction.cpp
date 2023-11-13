//
// Created by Loleg on 13.11.2023.
//
#include "Fraction.h"
#include <iostream>

using namespace std;

void Fraction::printF() {
    if (_b < 0) {
        _b = (-1) * _b;
        _a = (-1) * _a;
    }
    if (_a < 0) {
        cout << "-(" << (-1) * _a << "/" << _b << ")";
    } else {
        cout << "(" << _a << "/" << _b << ")";
    }
}
Fraction::Fraction(int valuea, int valueb) {
    if (valueb == 0) {
        cout << "NONONONO" << endl;
        valueb = 1;
    }
    _a = valuea;
    _b = valueb;
    simp();
}
Fraction::Fraction(const Fraction &F) {
    this->_a = F._a;
    this->_b = F._b;
}
int gcd(int a, int b) {
    if (b < a)
        swap(a, b);
    while (a != 0) {
        int t = b % a;
        b = a;
        a = t;
    }
    return b;
}
void Fraction::simp() {
    _a = _a/ gcd(_a,_b);
    _b = _b/ gcd(_b,_a);

}
int Fraction::get_a() {
    return _a;
};
int Fraction::get_b() {
    return _b;
};
Fraction Fraction::operator+(Fraction &F) {
    int A, B;
    Fraction res(_a * F._b + _b * F._a,_b * F._b);
    res.simp();
    return res;
}
Fraction Fraction::operator-(Fraction &F) {
    int A, B;
    Fraction res(_a * F._b - _b * F._a,_b * F._b);
    res.simp();
    return res;
}
Fraction Fraction::operator*(Fraction &F) {
    int A, B;
    Fraction res(_a * F._a,_b * F._b);
    res.simp();
    return res;
}
Fraction Fraction::operator/(Fraction &F) {
    int A, B;
    if (F._a == 0) {
        cout << "NONONONO" << endl;
        F._a = 1;
    }
    Fraction res(_a * F._b,_b * F._a);
    res.simp();
    return res;
}
istream& operator>>(istream& in,Fraction& F) {
    in >> F._a >> F._b;
    if (F._b == 0) {
        cout << "NONONONO" << endl;
        F._b= 1;
    }
    return in;
}
ostream& operator<<(ostream& out,Fraction F) {
    if (F._b < 0) {
        F._b = (-1) * F._b;
        F._a = (-1) * F._a;
    }
    if (F._a < 0) {
        out << "-(" << (-1) * F._a << "/" << F._b << ")";
    } else {
        out << "(" << F._a << "/" << F._b << ")";
    }
    return out;
}