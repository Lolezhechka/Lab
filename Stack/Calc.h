#pragma once
#ifndef STACK_CALC_H
#define STACK_CALC_H
using namespace std;
#include "Stack.h"
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
bool is_lbracket(string c);
bool is_lbracket(char c);
bool is_rbracket(string c);
bool is_rbracket(char c);
bool is_operator(string c);
bool is_operator(char c);
bool is_number (string c);
bool is_number (char c);
double operation(double a,double b, string c);
vector <string> Parser(string Calc);
class Calculator{
private:
    map <string,int> Priority;
    Stack<double> Numbers;
    Stack<string> Operators;
    string Calc;
    vector <string> Parsed;
public:
    void Enter();
    Calculator(string c);
    void Calculate();
    bool is_correct();
};
#endif //STACK_CALC_H