#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;

    string tempString;
    int tempInt;

    inFile1.open("names.txt");
    inFile2.open("ages.txt");

    outFile.open("output.txt");

    // Do an error check for the input files
    if (!inFile1 || !inFile2)
    {
        cout << "There was an error...terminating program.\n";
        return 1;
    }

    while( !(inFile1.eof()) && !(inFile2.eof()) )
    {
        getline(inFile1, tempString);
        inFile2 >> tempInt;

        outFile << tempString << " " << tempInt << endl;
    }

    cout << "Writing to outfile done!\n";

    inFile1.close();
    inFile2.close();
    outFile.close();

    return 0;
}