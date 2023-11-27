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
        throw runtime_error("0 cant be divergent");
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
    int A, B;
    A = abs(a);
    B = abs(b);
    while (A != 0 && B != 0) {
        if (A >= B) {
            A = A % B;
        } else if (B >= A) {
            B = B % A;
        }
    }
    return A + B;
}

void Fraction::simp() {
    int k = gcd(_a, _b);
    _a = _a / k;
    _b = _b / k;

}

int Fraction::get_a() {
    return _a;
};

int Fraction::get_b() {
    return _b;
};

Fraction Fraction::operator+(Fraction &F) {
    Fraction res(_a * F._b + _b * F._a, _b * F._b);
    res.simp();
    return res;
}

Fraction Fraction::operator-(Fraction &F) {
    Fraction res(_a * F._b - _b * F._a, _b * F._b);
    res.simp();
    return res;
}

Fraction Fraction::operator*(Fraction &F) {
    Fraction res(_a * F._a, _b * F._b);
    res.simp();
    return res;
}

Fraction Fraction::operator/(Fraction &F) {
    if (F._a == 0) {
        throw runtime_error("0 cant be divergent");
    }
    Fraction res(_a * F._b, _b * F._a);
    res.simp();
    return res;
}

istream &operator>>(istream &in, Fraction &F) {
    in >> F._a >> F._b;
    if (F._b == 0) {
        throw runtime_error("0 cant be divergent");
    }
    return in;
}

ostream &operator<<(ostream &out, Fraction F) {
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