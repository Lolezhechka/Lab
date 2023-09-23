#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(NULL));
    int realsize,fill,a,imin,imax,z,l,summ,ubound,lbound,number,nnumber,buf,buf1,buf2;
    long composition;
    const int size = 100;
    z = 0;
    number = 0;
    nnumber = 0;
    imin = -1;
    imax = -1;
    summ = 0;
    cout << "Enter the number of array elements." << endl;
    cin >> realsize;
    l = realsize-1;
    if (realsize > size) {
        cout << "Incorrect number of elements.";
    }
    else {
        cout << "Enter 1 if you want to enter an array from the keyboard. Enter 2 if you want to fill in the array automatically." << endl;
        cin >> fill;
        int arr[size];
        if (fill == 1) {
            cout << "Enter the array elements" << endl;
            for (int i=0;i<realsize;i++) {
                cin >> arr[i];
            }
        }
        if (fill == 2) {
            cout << "Enter the upper and lower bounds of the generation." << endl;
            cin >> ubound >> lbound;
            for (int i=0;i<realsize;i++) {
                arr[i] = rand()%(ubound-lbound+1)+lbound;
            }
        }
        if (fill != 1 && fill != 2) {
            cout << "Incorrect input.";
        }
        else {
            composition = 1;
            for (int k=2;k<=realsize - 1;k+=2) {
                composition = composition*arr[k];
            }
            while (arr[z] != 0 && z < realsize - 1) {
                z = z + 1;
            }
            if (arr[z] == 0 ) {
                imin = z;
            }
            while (arr[l] != 0 && l >= 0) {
                l = l - 1;
            }
            if (arr[l] == 0) {
                imax = l;
            }
            for (int y = imin; y <= imax; y++) {
                summ = summ + arr[y];
            }
            cout << "Array:" << endl;
            for (int i=0;i<realsize;i++) {
                cout << arr[i] << " ";
            }
            if (realsize < 3) {
                cout << "Not enough elements.";
            }
            else {
                cout << endl << "Multiplication of elements with even numbers." << endl << composition << endl;
            }
            cout << "Amount of elements between first and last zero." << endl;
            if (imin == (-1) && imax == (-1)) {
                cout << "There are no zeros." << endl;
            }
            if (imin == imax && imin != -1) {
                cout << "There is only one zero." << endl;
            }
            if (imin != imax && imin != (-1) && imax != (-1)) {
                cout << summ << endl;
            }
            cout << "Sorted array:" << endl;
            for (int i=0; i <= realsize-1 ; i++ ) {
                if (arr[i] < 0) {
                    buf1= arr[i];
                    for (int k=i; k > nnumber; k= k-1) {
                        arr[k] = arr[k-1];
                    }
                    arr[nnumber] = buf1;
                    nnumber += 1;
                }
            }
            for (int i=0;i<realsize;i++) {
                cout << arr[i] << " ";
            }
        }
    }
    return 0;
}