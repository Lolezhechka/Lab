#include <iostream>
#include "Class.h"
#include <vector>
#include <cstring>
using namespace std;
void avgGroupAft1(vector <Student*> Students,int n) {
    double avg(0);
    int k(0);
    for (int i=0;i<Students.size();i++) {
        if ((Students[i]->classname.compare("StudentAft1session")==0||Students[i]->classname.compare("StudentAft2session")==0)&&Students[i]->get_group()==n) {
            avg+=Students[i]->get_avgMarkAft1session();
            k+=1;
        }
    }
    if (k==0) {
        cout << "Group "<<n<<" is empty."<<endl;
    }
    else {
        cout <<"Average mark of the "<<n<<" group after 1 session is "<<(avg/k);
    }
}
void avgGroupMarkAft2(vector <Student*> Students,int n) {
    double avg(0);
    int k(0);
    for (int i=0;i<Students.size();i++) {
        if (Students[i]->classname=="StudentAft2session"&&Students[i]->get_group()==n) {
            avg+=Students[i]->get_avgMarkAft2session();
            k+=1;
        }
    }
    if (k==0) {
        cout << "Group "<<n<<" is empty."<<endl;
    }
    else {
        cout <<"Average mark of the "<<n<<" group atfer 2 session is "<<(avg/k);
    }
}
int main() {
    vector<Student*> Students;
    Student A("Alex",5,6,123);
    cout <<A;
    StudentAft1session B("Alex",4,4,3,1,2,3,4);
    StudentAft1session C(A,2,3,4,5);
    Students.push_back(&A);
    Students.push_back(&B);
    Students.push_back(&C);
    //avgGroupAft1(Students,6);
    avgGroupAft1(Students,4);
    return 0;
}