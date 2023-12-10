#pragma once
#ifndef INHERITANCE_CLASS_H
#define INHERITANCE_CLASS_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
class Student {
protected:
    int nameSize;
    int course;
    int group;
    const int id;
    int number;
    char* name;
public:
    Student(string name, int course, int group, int number);
    Student (const Student &F);
    int get_course();
    void set_course(int a);
    int get_group();
    void set_group(int a);
    int get_id();
    int get_number();
    int get_nameSize() const;
    char* get_name();
    void set_name(string name);
    friend ostream& operator<<(ostream& out,Student F);
};
class StudentAft1session : protected Student {
protected:
    int marks[4];
public:
    double get_avgMarkAft1session();
    int get_1mark();
    void set_1mark(int a);
    int get_2mark();
    void set_2mark(int b);
    int get_3mark();
    void set_3mark(int c);
    int get_4mark();
    void set_4mark(int d);
    using Student::get_course;
    using Student::get_group;
    using Student::get_name;
    using Student::get_number;
    using Student::get_nameSize;
    StudentAft1session(string name, int course, int group, int number,int a,int b,int c,int d);
    StudentAft1session(StudentAft1session &F);
    StudentAft1session(Student &F,int a,int b,int c,int d);
    friend ostream& operator<<(ostream& out,const StudentAft1session& F);
};
class StudentAft2session : StudentAft1session {
private:
    int nmarks[5];
public:
    double get_avgMarkAft2Session();
    int get_1nmark();
    void set_1nmark(int a);
    int get_2nmark();
    void set_2nmark(int b);
    int get_3nmark();
    void set_3nmark(int c);
    int get_4nmark();
    void set_4nmark(int d);
    int get_5nmark();
    void set_5nmark(int e);
    StudentAft2session(StudentAft2session &F);
    StudentAft2session(StudentAft1session &F,int a,int b,int c,int d,int e);
    friend ostream& operator<<(ostream& out,StudentAft2session F);
};

#endif //INHERITANCE_CLASS_H
