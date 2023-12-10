#include <iostream>
#include "Class.h"
using namespace std;
int main() {
    vector <vector <double> >
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