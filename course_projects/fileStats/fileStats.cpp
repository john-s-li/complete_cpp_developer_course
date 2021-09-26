#include <iostream>
#include <fstream>

using namespace std;

const int LARGE_NUM =  100000000;
const int SMALL_NUM = -100000000;

int main()
{
    ifstream inFile;
    inFile.open("scores.txt");

    int tempNum;
    int min = LARGE_NUM;
    int max = SMALL_NUM;
    int sum = 0;
    int count = 0;
    double average;

    if(!inFile)
    {
        cout << "File read-in error. Terminating program. . .\n";
        return 1;
    }
  
    while( !(inFile.eof()) )
    {
        inFile >> tempNum;

        if (! (tempNum >= 0 && tempNum <= 100) )
        {
            continue;
        }

        sum += tempNum;
        // Track min
        if (tempNum < min) { min = tempNum; }
        // Track max
        if (tempNum > max) { max = tempNum; }
        
        count++;
    }

    average = (double)sum / count;

    cout << "Statistics:\n";
    cout << "\tMin = " << min << endl;
    cout << "\tMax = " << max << endl;
    cout << "\tAverage = " << average << endl;

    inFile.close();

    return 0;
}