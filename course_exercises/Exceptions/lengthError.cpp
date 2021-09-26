#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    vector<int> myVector;

    // Try to resize it past allowable size
    try
    {
        myVector.resize(myVector.max_size() + 1);
        cout << "Yay! I have a big vector!" << endl;
    }
    catch(const length_error& err)
    {
        cout << err.what() << endl;
        // cerr allows for redirect away from console
        cerr << "Cannot resize vector past max allowable size." << endl;
    }    
    
    return 0;
}