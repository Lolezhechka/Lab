#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double k,x,summ,nead,num,realfish,diff,realdiff;
    cout << "Enter the k"; // k - кол-во совпадающих чисел
    cin >> k;
    cout << "Enter the x"; // x - степень, в которую мы возводим экспоненту
    cin >> x;
    summ = 0.0;
    nead = 1.0;
    diff= pow(10,-1*(k));
    num = 1.0;
    realfish = exp(x);
    realdiff = 1;
    while (abs(realdiff)>=diff)  {
            summ = summ + nead;
            nead = nead*x/num;
            num = num + 1.0;
            realdiff = realfish - summ;
    } //прибавляем члены ряда пока разница между настоящим значением и тем, которое мы получили, не станет меньше 10^-k
    cout << fixed;
    cout << setprecision(k);
    cout << "Received value ";
    cout << summ << endl << "Real value     "<< realfish;
    return 0;
}
