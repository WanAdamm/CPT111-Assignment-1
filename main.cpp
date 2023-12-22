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

    // open output file in normal read write mode
    outputFile.open("outputFile.txt");

    bool run = true;

    while (run)
    {
        //  menu creation section
        cout << endl
             << endl;
        cout << "--------------------------------------------------------\n";
        cout << "                   Simple Dictionary\n";
        cout << "--------------------------------------------------------\n";

        cout << "1: Generate output files (this should only be run the first time you run the program !)" << endl;
        cout << "2: Display dictionary file" << endl;
        cout << "3: Search for word's meaning" << endl;
        cout << "4: Add new word" << endl;
        cout << "5: Rearrange file" << endl
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
            // case for generating output file

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
                }

                cout << "output file generated."  << endl;
            }
            else
            {
                cout << "The file did not exist.";
            }

            break;
        }
        case 2:
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
        case 3:
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
                        cout << endl
                             << "meaning: " << meaning << endl;

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
        case 4:
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

            break;
        }
        case 5:
        {
            // TODO: rearrange word
            string back_dict = "", line, front_dict = "", lineofWordSelected, wordToBeRearranged, wordToBeRearrangedLowerCase = "", wordLowerCase = "";
            int lineCounter, lineAfterWordRearranged;
            bool wordExist = false;

            cout << "enter word to be rearranged: ";
            cin >> wordToBeRearranged;

            cout << "enter the new line in which you want to put the word in: ";
            cin >> lineAfterWordRearranged;

            // convert both wordToBeRearranged to lowercase to make it case-insensitive
            for (int i = 0; i < wordToBeRearranged.length(); i++)
            {
                wordToBeRearrangedLowerCase += tolower(wordToBeRearranged[i]);
            }

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

            // clear fail and eof bits
            outputFile.clear();
            // reset output file pointer to top left of file
            outputFile.seekp(0);

            while (!outputFile.eof())
            {
                getline(outputFile, word, '\t');

                getline(outputFile, meaning);

                // convert word to lower case so that it is case-insensitive
                for (int i = 0; i < word.length(); i++)
                {
                    wordLowerCase += tolower(word[i]);
                }

                if (wordToBeRearrangedLowerCase == wordLowerCase)
                {
                    wordExist = true;
                    break;
                }
                else if (outputFile.eof())
                {
                    cout << "sorry, no such word in the dictionary" << endl;
                    break;
                }

                // reset wordToBeRearrangedLowerCase and wordLowerCase
                wordToBeRearrangedLowerCase = "", wordLowerCase = "";
            }

            // clear fail and eof bits
            outputFile.clear();
            // reset output file pointer to top left of file
            outputFile.seekp(0);

            // set lineCounter to 1;
            lineCounter = 1;
            while (getline(outputFile, line))
            {
                line += '\n';
                if (lineCounter < lineAfterWordRearranged)
                {
                    back_dict += line;
                }
                else if (lineCounter > lineAfterWordRearranged)
                {
                    front_dict += line;
                }
                else if (lineCounter == lineAfterWordRearranged)
                {
                    lineofWordSelected = line;
                }

                lineCounter++;
            }

            // clear fail and eof bits
            outputFile.clear();
            // reset output file pointer to top left of file
            outputFile.seekp(0);

            if (wordExist)
            {
                outputFile.close();
                // reopen it and truncate everything inside outFile
                outputFile.open("outputFile.txt", ios::out | ios::trunc);
                // rewrite content
                outputFile << back_dict << lineofWordSelected << front_dict;
                outputFile.close();

                // reopen in normal read write mode
                outputFile.open("outputFile.txt");
            }

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