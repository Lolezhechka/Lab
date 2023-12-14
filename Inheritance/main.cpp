#include <iostream>
#include "Class.h"
#include <vector>
#include <cstring>
using namespace std;
void avgGroupAft1(vector <Student*> Students,int n) {
    double avg(0);
    int k(0);
    for (int i=0;i<Students.size();i++) {
        if (Students[i]->get_group()==n) {
            avg+=Students[i]->get_avgMarkAft1session();
            k+=1;
        }
    }
    if (k==0) {
        cout << "Group "<<n<<" is empty."<<endl;
    }
    else {
        cout <<"Average mark of the "<<n<<" group after 1 session is "<<(avg/k) <<endl;
    }
}
void avgGroup(vector <Student*> Students) {
    double avg(0);
    int k(0);
    for (int i=0;i<Students.size();i++) {
        avg+=(Students[i]->get_avgMarkAft1session())*(4.0/9.0);
        avg+=Students[i]->get_avgMarkAft2session()*(5.0/9.0);
        k+=1;
    }
    if (k==0) {
        cout << "Group is empty."<<endl;
    }
    else {
        cout <<"Average mark is "<<(avg/k) <<endl;
    }
}
void avgGroupAft2(vector <Student*> Students,int n) {
    double avg(0);
    int k(0);
    for (int i=0;i<Students.size();i++) {
        if (Students[i]->get_group()==n) {
            avg+=Students[i]->get_avgMarkAft2session();
            k+=1;
        }
    }
    if (k==0) {
        cout << "Group "<<n<<" is empty."<<endl;
    }
    else {
        cout <<"Average mark of the "<<n<<" group atfer 2 session is "<<(avg/k) <<endl;
    }
}
int main() {
    vector<Student*> Students;
    Student A("Alex",5,6,123);
    StudentAft1session B("Alex",4,4,3,1,2,3,4);
    StudentAft1session C(A,2,3,4,5);
    StudentAft2session D(C,2,3,5,4,3);
    cout<<A;
    cout<<B;
    cout<<C;
    cout<<D;
    Students.push_back(&A);
    Students.push_back(&B);
    Students.push_back(&C);
    Students.push_back(&D);
    avgGroupAft1(Students,6);
    avgGroupAft1(Students,4);
    avgGroupAft2(Students,4);
    avgGroupAft2(Students,6);
    avgGroup(Students);
    return 0;
}