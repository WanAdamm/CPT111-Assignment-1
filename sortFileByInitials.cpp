#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// compare input file with sorted file

int main()
{
    fstream File1("sorted_dict.txt");
    fstream File2("sorted_dict copy.txt");

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
        File1.open("sorted_dict.txt", ios::out | ios::trunc);
        File1 << back_dict << file2Word << front_dict;
        File1.close();
        File1.open("sorted_dict.txt");
        
        
    }

    return 0;
}
