#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string word, wordInitial, meaning, inputFileName, outputFileName;

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
        cout << "5: Rearrange file" << endl;
        cout << "6: Sort file alphabetically" << endl
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

                cout << "output file successfully generated." << endl;
            }
            else
            {
                cout << "you can only generate output file once";
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

                if(word == "")
                {
                    break;
                }

                cout << word << '\t' << meaning << endl;
            }

            break;
        }
        case 3:
        {
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
                        cout << word << ": " << meaning << endl;

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

            if (outputFile.eof())
            {
                cout << "word not found in the dictionary" << endl;

                // clear fail and eof bits
                outputFile.clear();
                // reset output file pointer to top left of file
                outputFile.seekp(0);

                // searched if theres any word similar to the word being searched
                string searchedWordSubstr = "", wordSubstr = "";

                // formatting so that the searchedWord match the format of word in outputfile
                for (int i = 0; i < searchedWord.length(); i++)
                {
                    searchedWordSubstr += tolower(searchedWord[i]);
                }
                searchedWordSubstr[0] = toupper(searchedWordSubstr[0]);

                while (searchedWordSubstr.length() != 0)
                {
                    while (getline(outputFile, word, '\t'))
                    {
                        getline(outputFile, wordInitial, '\t');
                        getline(outputFile, meaning);

                        wordSubstr = word.substr(0, searchedWordSubstr.length());

                        if (searchedWordSubstr == wordSubstr)
                        {
                            cout << "do you mean: " << word << " ?" << endl;
                            searchedWordSubstr = "";
                            break;
                        }

                        wordSubstr = "";
                    }

                    searchedWordSubstr = searchedWordSubstr.substr(0, searchedWordSubstr.length() - 1);

                    // clear fail and eof bits
                    outputFile.clear();
                    // reset output file pointer to top left of file
                    outputFile.seekp(0);
                }

                break;
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
            string back_dict = "", lineToBeRearranged, front_dict = "", line;
            int currentLine, newLine, lineCounter = 1;

            // get line to be rearranged
            cout << "enter line to be rearrange: ";
            cin >> currentLine;

            // get the new line number
            cout << "enter the new line you want to put it in: ";
            cin >> newLine;

            // in case new line and current line is same then theres no need to rearrange
            if (currentLine == newLine)
            {
                break;
            }

            // clear fail and eof bits
            outputFile.clear();
            // reset output file pointer to top left of file
            outputFile.seekp(0);

            while (getline(outputFile, line))
            {
                line += '\n';

                if (lineCounter == currentLine)
                {
                    lineToBeRearranged = line;
                }
                else if (newLine < currentLine)
                {
                    if (lineCounter < newLine)
                    {
                        back_dict += line;
                    }
                    else if ( lineCounter >= newLine)
                    {
                        front_dict += line;
                    }
                }
                else if (newLine > currentLine)
                {
                    if (lineCounter <= newLine)
                    {
                        back_dict += line;
                    }
                    else if (lineCounter > newLine)
                    {
                        front_dict += line;
                    }
                }

                // increment line counter by 1
                lineCounter++;
            }

            // destroy all content in output file then rewrite
            outputFile.close();
            outputFile.open("outputFile.txt", ios::out | ios::trunc);
            outputFile << back_dict << lineToBeRearranged << front_dict;
            outputFile.close();

            // reopen in normal read write mode
            outputFile.open("outputFile.txt");

            break;
        }
        case 6:
        {
            // sort file alphbetically

            fstream File1("sortedWord.txt", ios::out);
            fstream File2("unsortedWord.txt", ios::out);

            outputFile.clear();
            outputFile.seekp(0);

            while (getline(outputFile, word, '\t'))
            {
                File2 << word << endl;
                getline(outputFile, wordInitial, '\t');
                getline(outputFile, meaning);
            }

            outputFile.close();
            outputFile.open("outputFile.txt");

            File1.close();
            File2.close();

            File1.open("sortedWord.txt");
            File2.open("unsortedWord.txt");

            string file1Word, file2Word;

            while (getline(File2, file2Word))
            {
                string back_dict = "", front_dict = "";
                while (getline(File1, file1Word))
                {
                    file1Word += '\n';
                    if (file1Word < file2Word)
                    {
                        back_dict += file1Word;
                    }
                    else if (file1Word > file2Word)
                    {
                        front_dict += file1Word;
                    }
                }

                file2Word += '\n';

                File1.close();
                File1.open("sortedWord.txt", ios::out | ios::trunc);
                File1 << back_dict << file2Word << front_dict;
                File1.close();
                File1.open("sortedWord.txt");
            }

            ofstream sortedOutputFile("sortedOutputFile.txt");

            while (getline(File1, file1Word))
            {
                while (getline(outputFile, word, '\t'))
                {
                    getline(outputFile, wordInitial, '\t');
                    getline(outputFile, meaning);

                    if (word == file1Word)
                    {
                        sortedOutputFile << word << '\t' << wordInitial << '\t' << meaning << endl;
                        break;
                    }
                }

                outputFile.clear();
                outputFile.seekp(0);
            }

            ifstream sortedInputFile("sortedOutputFile.txt");
            string line;

            outputFile.close();
            outputFile.open("outputFile.txt", ios::out | ios::trunc);

            // copy sortedOutputFile to outputFile
            while (getline(sortedInputFile, line))
            {
                outputFile << line << endl;
            }

            outputFile.close();

            // reopen in normal R/W mode
            outputFile.open("outputFile.txt");

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