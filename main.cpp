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
    string word, meaning, inputFileName, outputFileName;

    cout << "This program is developed by: \n";
    cout << "WAN MUHAMMAD ADAM BIN WAN MOHD FAUZI \n22304170\n";
    cout << "Date: 24th December 2023.\n\n\n";

    //  menu creation section
    cout << "--------------------------------------------------------\n";
    cout << "                   Simple Dictionary\n\n";
    cout << "    This program reads from file containing word\n    and its meaning separated by tab then output it\n    to a file after being processed\n";
    cout << "--------------------------------------------------------\n";
    // TODO: add rearranging files capabilities
    // cout << "\n\nenter input file name: ";
    // cin >> inputFileName;

    // create an input and output file object
    ifstream inputFile;
    inputFile.open("inputFile.txt");
    fstream outputFile;
    outputFile.open("outputFile.txt");

    // check if input file exist or not
    if (inputFile)
    {
        // this particular while loop generate the output file

        // set line counter to 1
        int lineCounter = 1;

        // check if end of file and also pass the word into a string variable.
        while (getline(inputFile, word, '\t'))
        {
            // output line number, word, and the initial of the word into the output file.
            outputFile << lineCounter << '\t' << word << '\t' << word[0] << '\t';
            getline(inputFile, meaning);
            // output meaning of word into the output file then point onto the next line.
            outputFile << meaning << '\t' << endl;
            // increment line counter by 1.
            lineCounter++;
        }
    }
    else
    {
        cout << "The file did not exist.";
    }

    // function for searching through files
    string index, wordInitial, searchedWord, all;

    cout << "enter word to be searched: ";
    cin >> searchedWord;

    // TODO: should we read from input or output file.
    // reset output file pointer to top left of file
    outputFile.seekp(0);
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
                    // TODO: add word adding capabilities
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

    // close both input and outputfile
    inputFile.close();
    outputFile.close();

    return 0;
}