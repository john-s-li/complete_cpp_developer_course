#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void printFormatted(ofstream& outFile, int numVals)
{
    outFile.open("fileOutputIntro.txt");

    outFile << fixed << showpoint;

    for(int i = 0; i < numVals; i++)
    {
        outFile << setw(12) << setprecision(2) << (i * 3.14159) 
                << setw(12) << setprecision(4) << (i * 9.161996) << endl;
    }

    outFile.close();

    cout << "Done. Look for .txt file in directory." << endl;
}

int main()
{
    int userVal;

    cout << "Please enter how many numbers you'd like.\n";
    cin >> userVal;

    ofstream outFile;
    printFormatted(outFile, userVal);

    return 0;
}