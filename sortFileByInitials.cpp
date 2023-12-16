#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream outputFile;
    outputFile.open("outputFile.txt");
    string word, meaning, inputFileName, outputFileName;
    string index, wordInitial, searchedWord, all;
    cout << "enter word to be searched: ";
    cin >> searchedWord;

    if (outputFile)
    {
        while (getline(outputFile, index, '\t'))
        {
            getline(outputFile, word, '\t');

            if (word == searchedWord)
            {
                getline(outputFile, wordInitial, '\t');
                // since no delimiter is assign the file would be read until a breakline the pointed onto the next line
                getline(outputFile, meaning);
                cout << meaning << endl;
                break;
            }
            else
            {
                if (outputFile.eof())
                {
                    cout << "Sorry, the word is not yet available in the dictionary, would you like to add it?";
                    // reset file pointer
                    outputFile.seekp(0);
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        cout << "output file did not exist" << endl;
    }
}
