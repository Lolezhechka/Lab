#pragma once
#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
template <typename T>
class Stack {
private:
    T* array;
    int size;
public:
    Stack():array(nullptr),size(0){};
    void print() {
        for (int i(0);i<size;i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void operator<<(T A) {
        T* b=new T[size];
        for (int i(0);i<size;i++) {
            b[i]=array[i];
        }
        array= new T[size + 1];
        for (int i(0);i<size;i++) {
            array[i]=b[i];
        }
        array[size]=A;
        size++;
        delete[] b;
    };
    bool operator>(Stack A) {
        if (size>A.size) {
            return true;
        } else {
            return false;
        }
    }
    bool operator<(Stack A) {
        if (size<A.size) {
            return true;
        } else {
            return false;
        }
    }
    T operator[] (int l) {
        return array[l];
    };
    bool operator==(Stack A) {
        if (size==A.size) {
            return true;
        } else {
            return false;
        }
    }
    bool operator>=(Stack A) {
        if (size>=A.size) {
            return true;
        } else {
            return false;
        }
    }
    bool operator<=(Stack A) {
        if (size<=A.size) {
            return true;
        } else {
            return false;
        }
    }
    void operator>>(T &A) {
        A=array[size-1];
        T* b=new T[size];
        for (int i(0);i<size-1;i++) {
            b[i]=array[i];
        }
        array= new T[size -1];
        for (int i(0);i<size-1;i++) {
            array[i]=b[i];
        }
        size--;
        delete[]b;
    };
    void operator=(const T& A) {
        array = new T[A.size];
        for (int i(0);i<A.size-1;i++) {
            array[i]=A.array[i];
        }
        size=A.size;
    }
};
#endif //STACK_STACK_H
