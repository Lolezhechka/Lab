
#pragma once
#ifndef LAB6_1_POINT_H
#define LAB6_1_POINT_H

#include <iostream>
#include <stdexcept>

using namespace std;
int gcd(int a, int b);
class Fraction {
private:
    int _a;
    int _b;
    void simp();
public:
    Fraction(int valuea, int valueb);
    Fraction(const Fraction &F);
    int get_a();
    int get_b();
    void printF();
    Fraction operator+(Fraction &F);
    Fraction operator-(Fraction &F);
    Fraction operator*(Fraction &F);
    Fraction operator/(Fraction &F);
    friend istream& operator>>(istream& in,Fraction& F);
    friend ostream& operator<<(ostream& out,Fraction F);
};


#endif //LAB6_1_POINT_H

