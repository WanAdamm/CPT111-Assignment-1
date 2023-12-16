#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// use this file for sanity check in mainfile output

int main()
{
    string line, token;
    ifstream File("outputFile.txt");

    if(File)
    {
        while (getline(File, line))
        {
            // create a string stream
            istringstream ss(line);
            // read the string stream and break at tab
            while (getline(ss, token, '\t'))
            {
                cout << token << endl;
            }
            
            
        }
        
    }

    return 0;
}
