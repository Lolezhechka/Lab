#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    const int ARR_SIZE = 300;
    char a[ARR_SIZE] = {};
    vector <char> word;
    vector <char> min_word;
    cout << "Enter the string" << endl;
    cin.getline(a,ARR_SIZE);
    cout << "The word with the least number of different characters" << endl;
    int position_in_string,position_in_word,word_size,min_word_size,cur_word_size,number_of_matches;
    bool found;
    position_in_string = 0;
    position_in_word = 0;
    word_size = 0;
    min_word_size = ARR_SIZE;
    cur_word_size = 0;
    while (position_in_string < ARR_SIZE) {
        char cur_char = a[position_in_string];
        if (cur_char != ' ' && cur_char != '\000') {
            found = false;
            position_in_word = 0;
            for (int i = 0; i < cur_word_size - 1; i++) {
                if (word[position_in_word] == cur_char) {
                    found = true;
                }
            }
            if (!found) {
                cur_word_size++;
            }
            word.push_back(cur_char);
        } else {
            if (cur_word_size < min_word_size && cur_word_size > 0 ) {
                min_word_size = cur_word_size;
                min_word.swap(word);
            }
            word.clear();
            cur_word_size=0;
            word_size=0;
        }
        position_in_string++;
    }
    int j = 0;
    while (j < min_word.size()) {
        cout << min_word[j];
        j++;
    }
    return 0;
}