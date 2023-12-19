#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/*
    output file specs:
    4 columns separated by tab
    index
    word
    word initial
    meaning
*/

int main()
{
    string word, wordUpperCase = "";

    cin >> word;

    for (int i = 0; i < word.length(); i++)
    {
        wordUpperCase += toupper(word[i]);
    }

    cout << wordUpperCase;

    return 0;
}