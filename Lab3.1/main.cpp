#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(NULL));
    int  p, ubound, lbound,n,number,h,max,a,b;
    double average,summ,i,c,min;
    p = 0;
    h = 0;
    number = 0;
    cout << "Enter the number of columns and rows in square matrix." << endl;
    cin >> i;
    if (i > 10) {
        cout << "Wrong number of columns or rows.";
    } else {
        vector<vector<int> > v3(i, vector<int>(i));
        cout << "Enter the upper and lower bounds of the generation." << endl;
        cin >> ubound >> lbound;
        for (int k = 0; k < i; k++) {
            for (int z = 0; z < i; z++) {
                v3[k][z] = rand() % (ubound - lbound + 1) + lbound;
            }
        }
        for (int k = 0; k < i; k++) {
            for (int z = 0; z < i; z++) {
                v3[k][z] = v3[z][k];
            }
        }
        for (int k = 0; k < i; k++) {
            for (int z = 0; z < i; z++) {
                if (v3[k][z] >= 0) {
                    cout << " " << v3[k][z] << " ";
                } else {
                    cout << v3[k][z] << " ";
                }
            }
            cout << endl;
        }
        for (int k = 0; k < i; k++) {
            n = 0;
            max = lbound;
            for (int z = 0; z < i; z++) {
                if (v3[z][k] >= max) {
                    max = v3[z][k];
                }
                if (v3[z][k] <= 0) {
                    n = n + 1;
                }
            }
            if (n == i) {
                p = p + 1;
                cout << "Maximal non-positive element in " << k+1 << " column is " << max << endl;
            }

        }
        if (p == 0) {
            cout << "All columns contain positive elements." << endl;
        }
        min = ubound;
        while (number < i-1) {
            summ = 0;
            a = number;
            b = 0;
            while (a >= 0) {
                summ = summ + v3[a][b];
                a = a - 1;
                b = b + 1;
            }
            average = summ /(number+1);
            cout << "Average value in " << number + 1 << " diagonal is " << average << endl;
            number = number + 1;
            if (average < min) {
                min = average;
            }
        }
        number = i + 1;
        c = 1;
        while (number <= (2*i - 1)) {
            summ = 0;
            a = c;
            b = i - 1;
            while (a <= i - 1 ) {
                summ = summ + v3[a][b];
                a = a + 1;
                b = b - 1;
            }
            average = summ/(i-c);
            c = c + 1;
            cout << "Average value in " << number  << " diagonal is " << average << endl;
            number = number + 1;
            if (average < min) {
                min = average;
            }
        }
        cout << "Minimum among the average values of the diagonal elements " << min;
    }
        return 0;
}