#include <fstream>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

bool inMap(unordered_map<string, int> shoppingList, string itemName);
void printList(unordered_map<string, int> shoppingList);

int main()
{
    string tempString;
    ifstream inFile;
    unordered_map<string, int> shoppingList;

    inFile.open("shopping.txt");

    if ( !inFile )
    {
        cout << "Error reading input file. Aborting. . .\n";
        return 1;
    }

    while( !(inFile.eof()) )
    {
        getline(inFile, tempString);

        if (!inMap(shoppingList, tempString))
        {
            shoppingList[tempString] = 1;
        }
        else
        {
            shoppingList[tempString] += 1;
        }
    }

    inFile.close();
    printList(shoppingList);

    return 0;
}

bool inMap(unordered_map<string, int> shoppingList, string itemName)
{
    if (shoppingList.find(itemName) == shoppingList.end())
    {
        return false;
    }

    return true;
}

void printList(unordered_map<string, int> shoppingList)
{
    for ( pair<string, int> iter : shoppingList)
    {
        cout << iter.first << " : " << iter.second << endl;
    }
}