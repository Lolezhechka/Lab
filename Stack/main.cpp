#include <iostream>
#include "Stack.h"
using namespace std;
int main() {
    int e;
    int *a=new int [3]{1,2,3};
//    Stack A(array);
    Stack<int> C;
    C << 'a';
    C << 'b';
    C << 'c';
    C.print();
    C>>e;
    cout << e << endl;
    C.print();
    Stack<int> D;
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