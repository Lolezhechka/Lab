#include <iostream>
#include "Class.h"
using namespace std;
int main() {
    Student A("Alex",5,6,123);
    cout <<A;
    Student B(A);
    cout <<B;
    StudentAft1session C(A,1,2,3,4);
    cout << C;
    cout << C.get_avgMarkAft1session();
    for (int i=0;i<Groups.size();i++) {
        int Avg=0;
        for (int j=0;j<Groups[i].size();j++){
            Avg+=Groups[i][j];
        }
        cout << "Average mark of the " << i+1 <<" group: " <<Avg/Groups[i].size() << endl;
    }
    return 0;
}