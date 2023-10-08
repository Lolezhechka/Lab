#include <iostream>
using namespace std;
char* _strcat (char* strDestination, const char* strSource) {
    int i = 0;
    int j = 0;
    while (strDestination[i] != '\0') {
        i++;
    }
    while (strSource[j] != '\0'){
        strDestination[i]=strSource[j];
        j++;
        i++;
    }
    strDestination[i] = '\0';
    return strDestination;

};
int main() {
    char strDestination[5] = {'f','w','j','y','\0'};
    char strSource[8] = {'f','w','\0','y','j','p','e','\0'};
    _strcat(strDestination,strSource);
    cout << strDestination;
    return 0;
}
