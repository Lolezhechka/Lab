#include <iostream>
#include "Fraction.h"
using namespace std;
int main() {
    Fraction A(1,1);
    Fraction B(1,1);
    cout << "Enter first fraction" << endl;
    cin >> A;
    cout << "First fraction: " << A<< endl;
    cout << "Enter second fraction" << endl;
    cin >> B;
    cout << "Second Fraction: " << B << endl;
    cout << "Sum of the fractions" << endl;
    cout << (A+B) << endl;
    cout << "Product of the fractions" << endl;
    cout << (A*B) << endl;
    cout << "Quotient of the fractions" << endl;
    cout << (A/B) << endl;
    cout << "Difference of the fractions" << endl;
    cout << (A-B) << endl;
    return 0;
}