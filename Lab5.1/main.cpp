#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    fstream infile1("..\\File1.txt");
    fstream infile2("..\\File2.txt");
    ofstream onfile3("..\\File3.txt");
    ifstream infile3("..\\File3.txt");
    bool b = true;
    if (!infile1.is_open() || !infile2.is_open()) {
        throw runtime_error("Unable to open the file");
    }
    string buff1;
    string buff2;
    infile1.seekg(0, infile1.end);
    infile2.seekg(0, infile2.end);
    infile1 << "\n";
    infile2 << "\n";
    infile1.seekg(0, infile1.beg);
    infile2.seekg(0, infile2.beg);
    cout << "File 1:" << endl;
    while (getline(infile1, buff1)) {
        cout << buff1 << endl;
    }
    cout << "File 2:" << endl;
    while (getline(infile2, buff1)) {
        cout << buff1 << endl;
    }
    infile1.clear();
    infile2.clear();
    infile1.seekg(0, infile1.beg);
    infile2.seekg(0, infile2.beg);
    string word1, word2;
    getline(infile1, word1);
    getline(infile2, word2);
    while (!infile1.eof() && !infile2.eof()) {
        if (word2 < word1) {
            onfile3 << word2 << endl;
            getline(infile2, word2);
        } else {
            onfile3 << word1 << endl;
            getline(infile1, word1);
        }
    }
    while (!infile1.eof()) {
        onfile3 << word1 << endl;
        getline(infile1, word1);
    }
    while (!infile2.eof()) {
        onfile3 << word2 << endl;
        getline(infile2, word2);
    }
    cout << "File 3:" << endl;
    while (getline(infile3, buff1)) {
        cout << buff1 << endl;
    }
    return 0;
}