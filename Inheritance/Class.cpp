#include "Class.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int l(0);
Student::Student(string name, int course, int group, int number) : id(l++) {
    this->course = course;
    this->group = group;
    this->name =new char[name.size()];
    for (int i=0;i<name.size();i++) {
        this->name[i]=name[i];
    }
    this->number=number;
    this->nameSize = name.size();
}
Student::Student(const Student &F) : id(l++) {
    this->course = F.course;
    this->group = F.group;
    this->nameSize=F.nameSize;
    this->number=F.number;
    this->name = new char[F.nameSize];
    for (int i=0;i<nameSize;i++) {
        this->name[i]=F.name[i];
    }
}

int Student::get_course() {
    return course;
}

int Student::get_group() {
    return group;
}

int Student::get_id() {
    return id;
}

int Student::get_number() {
    return number;
}

char *Student::get_name() {
    return name;
}
ostream &operator<<(ostream &out, Student F) {\
    cout << "Id: " << F.id << endl;
    cout << "Name: ";
    for(int i=0;i<F.nameSize; i++) {
        cout << F.name[i];
    }
    cout << endl;
    cout << "Number: " << F.number<<endl;
    cout <<"Group: " << F.group<<endl;
    cout<<"Course: "<<F.course<<endl;
    return out;
}

int Student::get_nameSize() const {
    return nameSize;
}

void Student::set_course(int a) {
    this->course=a;
}

void Student::set_group(int a) {
    this->group=a;
}

void Student::set_name(string name) {
    this->name =new char[name.size()];
    for (int i=0;i<name.size();i++) {
        this->name[i]=name[i];
    }
    this->nameSize = name.size();
}

StudentAft1session::StudentAft1session(Student &F,int a,int b,int c,int d):Student(name,course,group,number) {
    this->course = F.get_course();
    this->group = F.get_group();
    this->name = F.get_name();
    this->number=F.get_number();
    this->nameSize = F.get_nameSize();
    marks[0]=a;
    marks[1]=b;
    marks[2]=c;
    marks[3]=d;
}

StudentAft1session::StudentAft1session(StudentAft1session &F):Student(name,course,group,number)  {
    this->course = F.get_course();
    this->group = F.get_group();
    this->name =F.get_name();
    this->number=F.number;
    this->nameSize=F.get_nameSize();
    this->marks[0]=F.marks[0];
    this->marks[1]=F.marks[1];
    this->marks[2]=F.marks[2];
    this->marks[3]=F.marks[3];
}

ostream &operator<<(ostream &out, const StudentAft1session& F) {\
    cout << "Id: " << F.id << endl;
    cout << "Name: ";
    for(int i=0;i<F.nameSize; i++) {
        cout << F.name[i];
    }
    cout << endl;
    cout << "Number: " << F.number<<endl;
    cout <<"Group: " << F.group<<endl;
    cout<<"Course: "<<F.course<<endl;
    cout <<"Marks after 1 session: ";
    for (int i=0;i<4;i++) {
        cout << F.marks[i]<<" ";
    }
    cout << endl;
    return out;
}

StudentAft1session::StudentAft1session(string name, int course, int group, int number, int a, int b, int c, int d):Student(name,course,group,number) {
    this->course = course;
    this->group = group;
    this->name =new char[name.size()];
    for (int i=0;i<name.size();i++) {
        this->name[i]=name[i];
    }
    this->number=number;
    this->nameSize = name.size();
    this->marks[0]=a;
    this->marks[1]=b;
    this->marks[2]=c;
    this->marks[3]=d;
}

int StudentAft1session::get_1mark() {
    return marks[0];
}

int StudentAft1session::get_2mark() {
    return marks[1];
}

int StudentAft1session::get_3mark() {
    return marks[2];
}

int StudentAft1session::get_4mark() {
    return marks[4];
}

void StudentAft1session::set_1mark(int a) {
    this->marks[0]=a;
}

void StudentAft1session::set_2mark(int b) {
    this->marks[1]=b;
}

void StudentAft1session::set_3mark(int c) {
    this->marks[2]=c;
}

void StudentAft1session::set_4mark(int d) {
    this->marks[3]=d;
}

double StudentAft1session::get_avgMarkAft1session() {
    double sum;
    sum = marks[0]+marks[1]+marks[2]+marks[3];
    return (sum/4);
}

ostream &operator<<(ostream &out, StudentAft2session F) {\
    cout << "Id: " << F.id << endl;
    cout << "Name: ";
    for(int i=0;i<F.nameSize; i++) {
        cout << F.name[i];
    }
    cout << endl;
    cout << "Number: " << F.number<<endl;
    cout <<"Group: " << F.group<<endl;
    cout<<"Course: "<<F.course<<endl;
    cout <<"Marks after 1 session: ";
    for (int i=0;i<4;i++) {
        cout << F.marks[i]<<" ";
    }
    cout << endl;
    cout <<"Marks after 2 session: ";
    for (int i=0;i<5;i++) {
        cout << F.nmarks[i]<<" ";
    }
    cout << endl;
    return out;
}

StudentAft2session::StudentAft2session(StudentAft2session &F): StudentAft1session(name,course,group,number,marks[0],marks[1],marks[2],marks[3]) {
    this->course = F.get_course();
    this->group = F.get_group();
    this->name =F.get_name();
    this->number=F.number;
    this->nameSize=F.get_nameSize();
    this->marks[0]=F.marks[0];
    this->marks[1]=F.marks[1];
    this->marks[2]=F.marks[2];
    this->marks[3]=F.marks[3];
    this->nmarks[0]=F.nmarks[0];
    this->nmarks[1]=F.nmarks[1];
    this->nmarks[2]=F.nmarks[2];
    this->nmarks[3]=F.nmarks[3];
    this->nmarks[4]=F.nmarks[4];
}

StudentAft2session::StudentAft2session(StudentAft1session &F, int a, int b, int c, int d, int e): StudentAft1session(name,course,group,number,marks[0],marks[1],marks[2],marks[3]) {
    this->course = F.get_course();
    this->group = F.get_group();
    this->name = F.get_name();
    this->number=F.get_number();
    this->nameSize = F.get_nameSize();
    this->marks[0]=F.get_1mark();
    this->marks[1]=F.get_2mark();
    this->marks[2]=F.get_3mark();
    this->marks[3]=F.get_4mark();
    this->nmarks[0]=a;
    this->nmarks[1]=b;
    this->nmarks[2]=c;
    this->nmarks[3]=d;
    this->nmarks[4]=e;
}

int StudentAft2session::get_1nmark() {
    return nmarks[0];
}

int StudentAft2session::get_2nmark() {
    return nmarks[1];
}

int StudentAft2session::get_3nmark() {
    return nmarks[2];
}

int StudentAft2session::get_4nmark() {
    return nmarks[3];
}

int StudentAft2session::get_5nmark() {
    return nmarks[4];
}

void StudentAft2session::set_1nmark(int a) {
    this->nmarks[0]=a;
}

void StudentAft2session::set_2nmark(int b) {
    this->nmarks[1]=b;
}

void StudentAft2session::set_3nmark(int c) {
    this->nmarks[2]=c;
}

void StudentAft2session::set_4nmark(int d) {
    this->nmarks[3]=d;
}

void StudentAft2session::set_5nmark(int e) {
    this->nmarks[4]=e;
}

double StudentAft2session::get_avgMarkAft2Session() {
    double sum;
    sum = marks[0]+marks[1]+marks[2]+marks[3]+nmarks[0]+nmarks[1]+nmarks[2]+nmarks[3]+nmarks[4];
    return (sum/9);
}
