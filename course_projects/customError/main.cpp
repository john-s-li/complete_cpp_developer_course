#include <iostream>
#include "warpDriveOverheating.h"

using namespace std;

void wrapTest(int temp);

int main()
{
    int warpDriveTemp;

    cout << "Please enter the temperature of the warp drive.\n";
    cin >> warpDriveTemp;

    try
    {
        wrapTest(warpDriveTemp);
    }
    catch(const warpDriveOverheating& err)
    {
        cerr << err.what() << '\n';
    }
    
    return 0;
}

void wrapTest(int temp)
{
    if (temp > 80)
    {
        throw warpDriveOverheating();
    }

    cout << "Warp drive operating as normal.\n";
}