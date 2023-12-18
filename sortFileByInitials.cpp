#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream outputFile;
    ofstream sortedOutputFile;
    fstream outputFileWithAsciiSum;

    outputFile.open("outputFile.txt");
    sortedOutputFile.open("sortedOutputFile.txt");
    outputFileWithAsciiSum.open("outputFileWithAsciiSum.txt");
    string word, meaning, inputFileName, outputFileName;
    string index, wordInitial, searchedWord, all, firstWordAsciiValue;
    string indexSelected, wordSelected, firstWordAsciiValueSelected, allSelected;
    string tempWord, tempFirstWordAsciiValueSelected, tempAllSelected;
    int asciiFirstWord;

    while (getline(outputFile, index, '\t'))
    {
        getline(outputFile, word, '\t');
        getline(outputFile, all);

        asciiFirstWord = word[0];

        outputFileWithAsciiSum << index << '\t' << word << '\t' << asciiFirstWord << '\t' << all << endl;

        asciiFirstWord = 0;
    }

    // reset file pointer
    outputFileWithAsciiSum.clear();
    outputFileWithAsciiSum.seekp(0);

    // TODO: add sorting word capabilities (sort by alphabet????)

    getline(outputFileWithAsciiSum, indexSelected, '\t');
    getline(outputFileWithAsciiSum, wordSelected, '\t');
    while (getline(outputFileWithAsciiSum, firstWordAsciiValueSelected, '\t'))
    {
        getline(outputFileWithAsciiSum,  allSelected);

        while(getline(outputFileWithAsciiSum, index, '\t'))
        {
            getline(outputFileWithAsciiSum, word, '\t');
            getline(outputFileWithAsciiSum, firstWordAsciiValue, '\t');
            getline(outputFileWithAsciiSum, all);

            if(firstWordAsciiValueSelected > firstWordAsciiValue)
            {
                
            }
        }
    }

    return 0;
}
