#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/*
    output file specs:
    4 columns separated by tab
    word
    word initial
    meaning
*/

// TODO: when entering neither 0 or 1 after asked if new word wanted to be added the program loop infinitely

int main()
{
    string word, meaning, inputFileName, outputFileName;

    cout << "This program is developed by: \n";
    cout << "WAN MUHAMMAD ADAM BIN WAN MOHD FAUZI \n22304170\n";
    cout << "Date: 24th December 2023.\n\n\n";

    // create an input and output file object
    ifstream inputFile;
    inputFile.open("inputFile.txt");
    fstream outputFile;
    outputFile.open("outputFile.txt");

    // check if input file exist or not
    if (inputFile)
    {
        // this particular while loop generate the output file

        // check if end of file and also pass the word into a string variable.
        while (getline(inputFile, word, '\t'))
        {
            // output line number, word, and the initial of the word into the output file.
            outputFile << word << '\t' << word[0] << '\t';
            getline(inputFile, meaning);
            // output meaning of word into the output file then point onto the next line.
            outputFile << meaning << '\t' << endl;
            // increment line counter by 1.
        }
    }
    else
    {
        cout << "The file did not exist.";
    }

    bool run = true;

    while (run)
    {
        //  menu creation section
        cout << endl
             << endl;
        cout << "--------------------------------------------------------\n";
        cout << "                   Simple Dictionary\n\n";
        cout << "    This program reads from file containing word\n    and its meaning separated by tab then output it\n    to a file after being processed\n";
        cout << "--------------------------------------------------------\n";

        cout << "1: Display dictionary file" << endl;
        cout << "2: Search for word's meaning" << endl;
        cout << "3: Add new word" << endl;
        cout << "4: Rearrange file" << endl
             << endl;
        cout << "to end the program just enter anything other than the above option" << endl
             << endl;

        int choices;
        cout << "choose a mode: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            // clear fail and eof bits
            outputFile.clear();
            // reset output file pointer to top left of file
            outputFile.seekp(0);

            // display the dictionary files
            while (getline(outputFile, word, '\t'))
            {
                getline(outputFile, meaning);

                cout << word << '\t' << meaning << endl;
            }

            break;
        case 2:
            // search for word
            string wordInitial, searchedWord, all;
            string wordLowerCase, searchedWordLowerCase;

            cout << "enter word to be searched: ";
            cin >> searchedWord;

            // clear fail and eof bits
            outputFile.clear();
            // reset output file pointer to top left of file
            outputFile.seekp(0);

            // check if outputfile is available
            if (outputFile)
            {

                while (!outputFile.eof())
                {
                    getline(outputFile, word, '\t');

                    // convert both word and searchedWord to lowercase to make it case insensitive
                    for (int i = 0; i < word.length(); i++)
                    {
                        wordLowerCase += tolower(word[i]);
                    }

                    for (int i = 0; i < searchedWord.length(); i++)
                    {
                        searchedWordLowerCase += tolower(searchedWord[i]);
                    }

                    if (wordLowerCase == searchedWordLowerCase)
                    {
                        getline(outputFile, wordInitial, '\t');

                        // only get meaning if word matched searched word
                        getline(outputFile, meaning);
                        cout << meaning << endl;

                        // clear fail and eof bits
                        outputFile.clear();
                        // reset output file pointer to top left of file
                        outputFile.seekp(0);

                        // reset wordLowerCase and searchedWordLowerCase
                        wordLowerCase = "";
                        searchedWordLowerCase = "";

                        // break from while loop
                        break;
                    }
                    else
                    {
                        // reset wordLowerCase and searchedWordLowerCase
                        wordLowerCase = "";
                        searchedWordLowerCase = "";

                        // get the rest of the line and set pointer to next line if word doenst match
                        getline(outputFile, all);

                        // break the loop
                        continue;
                    }
                }
            }
            else
            {
                cout << "output file did not exist" << endl;
            }

            break;
        }
        case 3:
        {
            // add new word

            string newWord, newWordMeaning;

            // clear error state of input stream
            cin.clear();

            // clear input buffer
            cin.ignore();

            // close file then open it in append mode
            outputFile.close();
            outputFile.open("outputFile.txt", ios::app);

            // get the meaning of the new word
            cout << "enter word: ";
            getline(cin, newWord);

            // capitalise first letter of word
            newWord[0] = toupper(newWord[0]);

            // get the meaning of the new word
            cout << "enter meaning of word: ";
            getline(cin, newWordMeaning);

            // output line number, word, and the initial of the word into the output file.
            outputFile << newWord << '\t' << newWord[0] << '\t';
            // output meaning of word into the output file then point onto the next line.
            outputFile << newWordMeaning << '\t' << endl;

            // reopen the file in normal read write mode
            outputFile.close();
            outputFile.open("outputFile.txt");
        }
        case 4:
        {
            // TODO: rearrange word
            break;
        }
        default:
            run = false;
            break;
        }
    }

    // close both input and outputfile
    inputFile.close();
    outputFile.close();

    return 0;
}