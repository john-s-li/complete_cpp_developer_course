#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile;
    inputFile.open("fileInputIntro.txt");

    int sum = 0;
    int currNum;
    vector<int> saveNums;

    while(!(inputFile.eof()))
    {
        inputFile >> currNum;
        sum += currNum;
        saveNums.push_back(currNum);
    }

    cout << "Sum = " << sum << endl;

    for(int i = 0; i < saveNums.size(); i++)
    {
        cout << saveNums[i] << endl;
    }

    return 0;
}