#pragma once
#include "Calc.h"
bool is_lbracket(string c) {
    return c=="(";
}
bool is_lbracket(char c) {
    return c=='(';
}
bool is_rbracket(string c) {
    return c==")";
}
bool is_rbracket(char c) {
    return c==')';
}
bool is_operator(string c) {
    if ((c=="+")||(c=="-")||(c=="*")||(c=="/")||(c=="^")) {
        return true;
    } else {
        return false;
    }
}
bool is_operator(char c) {
    if ((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='^')) {
        return true;
    } else {
        return false;
    }
}
bool is_number (string c) {
    return (!is_lbracket(c)&&!is_operator(c)&&!is_rbracket(c));
}
bool is_number (char c) {
    return (!is_lbracket(c)&&!is_operator(c)&&!is_rbracket(c));
}
double operation(double a,double b, string c) {
    if (c=="+") {
        return a+b;
    }
    if (c=="-") {
        return a-b;
    }
    if (c=="*") {
        return a*b;
    }
    if (c=="/") {
        return a/b;
    }
    if (c=="^") {
        return pow(a,b);
    }
}
vector <string> Parser(string Calc) {
    vector <string> Pars;
    string p;
    for (int i=0;i<Calc.size();i++) {
        if (Calc[i]=='+' || Calc[i]=='-' || Calc[i]=='/' || Calc[i]=='*' || Calc[i]=='^' || Calc[i]=='(' || Calc[i]==')') {
            if (p.size()!=0) {
                Pars.push_back(p);
                p.clear();
            }
            p+=Calc[i];
            Pars.push_back(p);
            p.clear();
        } else {
            p+=Calc[i];
        }
    }
    Pars.push_back(p);
    return Pars;
}
Calculator::Calculator(std::string c) {
    this->Calc=c;
    this->Parsed= Parser(c);
    Priority["+"]=1;
    Priority["-"]=1;
    Priority["*"]=2;
    Priority["/"]=2;
    Priority["^"]=3;
}

bool Calculator::is_correct() {
    bool Correct(true);
    string p;
    string previous;
    previous.clear();
    int numberr(0);
    int numberl(0);
    if (is_operator(Calc[Calc.size()-1])) {
        Correct = false;
    }
    for (int i=0;i<Calc.size();i++) {
        if (is_operator(Calc[i])&& is_operator(previous)) {
            Correct=false;
        }
        if (Calc[i]=='(') {
            numberl++;
        }
        if (Calc[i]==')') {
            numberr++;
        }
    }
    if (numberl!=numberr) {
        Correct=false;
    }
    return Correct;
}

void Calculator::Calculate() {
    if (!is_correct()) {
        cout << "Incorrect equation";
    } else {
        for (int i=0; i < Parsed.size()-1; i++) {
            if (is_number(Parsed[i])) {
                Numbers<<stod(Parsed[i]);
            } else
            if ((is_operator(Parsed[i]) && (Operators.is_empty() || Priority[Operators.top()] < Priority[Parsed[i]]))) {
                Operators << Parsed[i];
            } else
            if (is_lbracket(Parsed[i])) {
                Operators << Parsed[i];
            } else
            if (is_operator(Parsed[i]) && !Operators.is_empty()) {
                while (!Operators.is_empty() &&Priority[Operators.top()]>=Priority[Parsed[i]]) {
                    if (!is_lbracket(Operators.top()) &&Priority[Operators.top()]>=Priority[Parsed[i]]) {
                        double a, b;
                        string c;
                        Numbers >> b;
                        Numbers >> a;
                        Operators >> c;
                        Numbers << operation(a, b, c);
                    }
                }
                Operators << Parsed[i];
            } else
            if (is_rbracket(Parsed[i])) {
                while (!is_lbracket(Operators.top())) {
                    double a,b;
                    string c;
                    Numbers>>b;
                    Numbers>>a;
                    Operators>>c;
                    Numbers<<operation(a,b,c);
                }
                string c;
                Operators>>c;
            }
        }
        if (!Operators.is_empty()) {
            while (!Operators.is_empty()) {
                double a,b;
                string c;
                Numbers>>b;
                Numbers>>a;
                Operators>>c;
                Numbers<<operation(a,b,c);
            }
        }
        double answer;
        Numbers>>answer;
        cout << Calc << "=" << answer;
    }
}

void Calculator::Enter() {
    cout << "Enter the equation"<<endl;
    cin >> Calc;
}