#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
    output file specs:
    4 columns separated by tab
    index
    word
    word initial
    meaning
*/

// TODO: maybe only stop program when user wants to?
// TODO: bug found, when looping program
// TODO: add rearranging files capabilities

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

    cout << "\n\nto end the program enter -1 when asked for a word\n" << endl;

    // cout << "\n\nenter input file name: ";
    // cin >> inputFileName;

    // create an input and output file object
    ifstream inputFile;
    inputFile.open("inputFile.txt");
    fstream outputFile;
    outputFile.open("outputFile.txt");

    // set line counter to 1
    int lineCounter = 1;

    // check if input file exist or not
    if (inputFile)
    {
        // this particular while loop generate the output file

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
    bool addNewWord;

    cout << "enter word to be searched: ";
    cin >> searchedWord;

    if (outputFile)
    {
        // reset output file pointer to top left of file
        outputFile.seekp(0);

        while (!outputFile.eof())
        {
            // check if user wanted to end the program
            if(searchedWord == "-1") {
                break;
            }

            getline(outputFile, index, '\t');
            getline(outputFile, word, '\t');

            if (word == searchedWord)
            {
                getline(outputFile, wordInitial, '\t');

                // only get meaning if word matched searched word
                getline(outputFile, meaning);
                cout << meaning << endl;

                // clear fail and eof bits
                outputFile.clear();
                // reset output file pointer to top left of file
                outputFile.seekp(0);

                // ask user to search for a word
                cout << "enter word to be searched: ";
                cin >> searchedWord;
            }
            else
            {
                getline(outputFile, all);
                if (outputFile.eof())
                {
                    cout << "Sorry, the word is not yet available in the dictionary, would you like to add it?" << endl;
                    cout << "yes: 1\nno: 0\n";
                    cin >> addNewWord;

                    if (addNewWord)
                    {
                        // increment line counter by 1.
                        lineCounter++;

                        // close file then open it in append mode
                        outputFile.close();
                        outputFile.open("outputFile.txt", ios::app);

                        // get the meaning of the new word
                        cout << "enter meaning of word: ";
                        // remove undiserable character from the input buffer
                        cin.ignore();
                        getline(cin, meaning);

                        // output line number, word, and the initial of the word into the output file.
                        outputFile << lineCounter << '\t' << searchedWord << '\t' << searchedWord[0] << '\t';
                        // output meaning of word into the output file then point onto the next line.
                        outputFile << meaning << '\t' << endl;

                        // reset addNewWord to false so that it wouldnt trigger this if statement
                        addNewWord = 0;

                        // reopen the file in normal read write mode
                        outputFile.close();
                        outputFile.open("outputFile.txt");
                    }

                    // ask user to search for a word
                    cout << "enter word to be searched: ";
                    cin >> searchedWord;

                    // clear fail and eof bits
                    outputFile.clear();
                    // reset output file pointer to top left of file
                    outputFile.seekp(0);

                    continue;
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