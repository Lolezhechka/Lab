#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    ifstream infile1("..\\File1.txt");
    ifstream infile2("..\\File2.txt");
    ofstream onfile3("..\\File3.txt");
    string buff{};
    vector <string> File1;
    vector <string> File2;
    if (infile1.is_open()) {
        while (getline(infile1,buff)) {
            File1.emplace_back(buff);
        }
    }
    if (infile2.is_open()) {
        while (getline(infile2,buff)) {
            File2.emplace_back(buff);
        }
    }
    cout << "File 1:" << endl;
    for(int j = 0;j < File1.size(); j++) {
        cout << File1[j] << endl;
    }
    cout << "File 2:" << endl;
    for(int j = 0;j < File2.size(); j++) {
        cout << File2[j] << endl;
    }
    for (int n2=0; n2 < File2.size();n2++) {
        char word2 [File2[n2].length() + 1];
        File2[n2].copy(word2,File2[n2].length() + 1);
        int n1=0;
        while (n1 < File1.size()) {
            char word1 [File1[n1].length() + 1];
            File1[n1].copy(word1,File1[n1].length() + 1);
            if (strcmp(word2,word1) == -1) {
                break;
            }
            n1++;
        }
        vector <string>::iterator it =File1.begin() + n1;
        File1.insert(it,File2[n2]);
    }
    for (int i = 0; i < File1.size(); i++) {
        onfile3 << File1[i] << endl;
    }
    cout << "File 3:" << endl;
    for (int i = 0;i < File1.size();i++) {
        cout << File1[i] << endl;
    }
    infile1.close();
    infile2.close();
    onfile3.close();
    return 0;
}
