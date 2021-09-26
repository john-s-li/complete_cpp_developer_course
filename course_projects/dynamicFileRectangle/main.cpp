#include <fstream>
#include <iostream>
#include <vector>
#include "rectangle.h"

using namespace std;

// Function prototypes
void populateVector(vector<rectangle*>& rectVectPtrs, int length, int width);
void printRectData(const rectangle* rectPtr);
void clearVector(vector<rectangle*>& rectVectPtrs);

int main()
{
    int tempLength;
    int tempWidth;

    ifstream inFile;

    vector<rectangle*> rectVectPtrs;

    inFile.open("rectangles.txt");

    if( !inFile )
    {
        cout << "Error reading file. Aborting. . .\n";
        return 1;
    }

    while( !(inFile.eof()) )
    {
        inFile >> tempLength;
        inFile >> tempWidth;

        populateVector(rectVectPtrs, tempLength, tempWidth);
        printRectData(rectVectPtrs.back()); // vec.back() returns a reference
    }

    inFile.close();
    clearVector(rectVectPtrs);

    return 0;
}

// Function definitions
void populateVector(vector<rectangle*>& rectVectPtrs, int length, int width)
{
    // The reference is passed in already...NOT a pointer to this vector
    // so no need to -> notation

    // Dynamically create the pointer to the rectangle class
    rectangle* rectPtr = new rectangle(width, length);
    // Add pointers to vector of pointers
    rectVectPtrs.push_back(rectPtr);
}

void printRectData(const rectangle* rectPtr)
{
    // Pass in a const pointer to a rectangle object
    cout << "Area = " << rectPtr->getArea() << endl;
    cout << "Perimeter = " << rectPtr->getPerimeter() << endl;
}

void clearVector(vector<rectangle*>& rectVectPtrs)
{
    for(int i = 0; i < rectVectPtrs.size(); i++)
    {
        // Delete the pointer
        delete rectVectPtrs[i];
        rectVectPtrs[i] = nullptr;
    }

    rectVectPtrs.clear(); // clear the vector
}