#include "Class.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int l(0);
Student::Student(char* name, int course, int group, int number) : id(l++) {
    this->course = course;
    this->group = group;
    this->name =new char[strlen(name)];
    strcpy(this->name,name);
    this->number=number;
}
Student::Student(const Student &F) : id(l++) {
    this->course = F.course;
    this->group = F.group;
    this->number=F.number;
    this->name = new char[strlen(F.name)];
    strcpy(this->name,F.name);
}

int Student::get_course() const {
    return course;
}

int Student::get_group() const {
    return group;
}

int Student::get_id() {
    return id;
}

int Student::get_number() const {
    return number;
}

char * Student::get_name() const {
    return name;
}
ostream &operator<<(ostream &out, Student F) {
    cout << "Id: " << F.id << endl;
    cout << "Name: " << F.name << endl;
    cout << "Number: " << F.number<<endl;
    cout <<"Group: " << F.group<<endl;
    cout<<"Course: "<<F.course<<endl;
    return out;
}

void Student::set_course(int a) {
    this->course=a;
}

void Student::set_group(int a) {
    this->group=a;
}

void Student::set_name(char* name) {
    this->name =new char[strlen(name)];
    strcpy(this->name,name);
}

char *Student::get_namecopy() const {
    size_t len = strlen(name);
    char* new_name = new char[len];
    strcpy(new_name,name);
    return new_name;
}

StudentAft1session::StudentAft1session(const Student &F,int a,int b,int c,int d):Student(F) {
    marks[0]=a;
    marks[1]=b;
    marks[2]=c;
    marks[3]=d;
}

StudentAft1session::StudentAft1session(const StudentAft1session &F):Student(F)  {
    this->marks[0]=F.marks[0];
    this->marks[1]=F.marks[1];
    this->marks[2]=F.marks[2];
    this->marks[3]=F.marks[3];
}

ostream &operator<<(ostream &out, const StudentAft1session& F) {\
    cout << "Id: " << F.id << endl;
    cout << "Name: ";
    for(int i=0;i< strlen(F.name); i++) {
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

StudentAft1session::StudentAft1session(char* name, int course, int group, int number, int a, int b, int c, int d):Student(name,course,group,number) {
    this->marks[0]=a;
    this->marks[1]=b;
    this->marks[2]=c;
    this->marks[3]=d;
}

int StudentAft1session::get_1mark() const {
    return marks[0];
}

int StudentAft1session::get_2mark() const {
    return marks[1];
}

int StudentAft1session::get_3mark() const {
    return marks[2];
}

int StudentAft1session::get_4mark() const {
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
    for(int i=0;i< strlen(F.name); i++) {
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

StudentAft2session::StudentAft2session(const StudentAft2session &F): StudentAft1session(F) {
    this->nmarks[0]=F.nmarks[0];
    this->nmarks[1]=F.nmarks[1];
    this->nmarks[2]=F.nmarks[2];
    this->nmarks[3]=F.nmarks[3];
    this->nmarks[4]=F.nmarks[4];
}

StudentAft2session::StudentAft2session(const StudentAft1session &F, int a, int b, int c, int d, int e): StudentAft1session(F) {
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

double StudentAft2session::get_avgMarkAft2session() {
    double sum;
    sum = marks[0]+marks[1]+marks[2]+marks[3]+nmarks[0]+nmarks[1]+nmarks[2]+nmarks[3]+nmarks[4];
    return (sum/9);
}
