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
    int course;
    int group;
    const int id;
    int number;
    char* name;
public:
    string classname = "Student";
    virtual double get_avgMarkAft1session(){};
    virtual double get_avgMarkAft2session(){};
    Student(char* name, int course, int group, int number);
    Student (const Student &F);
    int get_course() const;
    void set_course(int a);
    int get_group() const;
    void set_group(int a);
    int get_id();
    int get_number() const;
    char * get_name() const;
    void set_name(char* name);
    friend ostream& operator<<(ostream& out,Student F);
};
class StudentAft1session :public Student {
protected:
    int marks[4];
public:
    string classname = "StudentAft1session";
    double get_avgMarkAft1session() override;
    int get_1mark() const;
    void set_1mark(int a);
    int get_2mark() const;
    void set_2mark(int b);
    int get_3mark() const;
    void set_3mark(int c);
    int get_4mark() const;
    void set_4mark(int d);
    StudentAft1session(char* name, int course, int group, int number,int a,int b,int c,int d);
    StudentAft1session(const StudentAft1session &F);
    StudentAft1session(const Student &F,int a,int b,int c,int d);
    friend ostream& operator<<(ostream& out,const StudentAft1session& F);
};
class StudentAft2session : public StudentAft1session {
private:
    int nmarks[5];
public:
    string classname = "StudentAft2session";
    double get_avgMarkAft2session() override;
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
    StudentAft2session(const StudentAft2session &F);
    StudentAft2session(const StudentAft1session &F,int a,int b,int c,int d,int e);
    friend ostream& operator<<(ostream& out,StudentAft2session F);
};

#endif //INHERITANCE_CLASS_H
