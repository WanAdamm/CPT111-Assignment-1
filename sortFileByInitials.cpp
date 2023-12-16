#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream outputFile;
    ofstream sortedOutputFile;
    ofstream outputFileWithAsciiSum;

    outputFile.open("outputFile.txt");
    sortedOutputFile.open("sortedOutputFile.txt");
    outputFileWithAsciiSum.open("outputFileWithAsciiSum.txt");
    string word, meaning, inputFileName, outputFileName;
    string index, wordInitial, searchedWord, all;
    int asciiSum;

    // TODO: add sorting word capabilities (sort by alphabet????)

    while (getline(outputFile, index, '\t'))
    {
        getline(outputFile, word, '\t');
        getline(outputFile, all);

        for (auto &ch : word)
        {
            cout << ch << endl;
            asciiSum += ch;
        }

        outputFileWithAsciiSum << index << '\t' << word << '\t' << asciiSum << '\t' << all << endl;

        asciiSum = 0;
    }

    return 0;
}
