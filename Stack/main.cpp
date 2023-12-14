#include <iostream>
#include "Stack.h"
using namespace std;
int main() {
    char e;
    int *a=new int [3]{1,2,3};
//    Stack A(array);
    Stack<char> C;
    C << 'a';
    C << 'b';
    C << 'c';
    C.print();
    C>>e;
    cout << e << endl;
    C.print();
    Stack<char> D;
    D=C;
    C>>e;
    if (D>C) {
        D.print();
    }
    if (C<D) {
        D.print();
    }
    cout <<D[1];
    return 0;
}