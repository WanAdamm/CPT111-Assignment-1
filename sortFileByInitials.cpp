#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream inputFile;
    fstream sortedDict;

    // Sort and store sorted dictionary on temporary file
    // Insertion sort used to sort the dictionary
    string line; // Temporary varible for storing lines of dictionary

    inputFile.open("inputFile copy.txt", ios::in);
    sortedDict.open("sorted_dict.txt", ios::out | ios::trunc);
    sortedDict.close(); // Remove all the previous content in file

    while (getline(inputFile, line))
    { // Loop through all lines in inputFile
        sortedDict.open("sorted_dict.txt", ios::in);
        string sorted_line, front_dict = "", back_dict = ""; // Temporary varible for storing the parts of dictionary
        while (getline(sortedDict, sorted_line))
        {
            sorted_line += '\n';
            if (line < sorted_line)
            {                             // Word is more closer to A. Word would inserted before this line
                back_dict += sorted_line; // Append the line to backward
            }
            else
            {                              // Word is more closer to Z. Word would inserted after this line
                front_dict += sorted_line; // Append the line to forward
            }
        }
        sortedDict.close();
        // Replace the file including the new line
        sortedDict.open("sorted_dict.txt", ios::out | ios::trunc);
        sortedDict << front_dict << line << endl
                   << back_dict;
        sortedDict.close();
    }
    inputFile.close();
    return 0;
}
