#include <iostream>
#include <stdexcept>

using namespace std;

void processPositive(int num);
void doSomething(int num);

int main()
{
    int myInt;

    cout << "Please enter a positive integer." << endl;
    cin >> myInt;

    try
    {
        doSomething(myInt);
    }
    catch(const invalid_argument& err)
    {
        cout << "main says something is wrong." << endl;
        cerr << err.what() << endl;
    }
    catch(const out_of_range& err)
    {
        cout << "main says something is wrong." << endl;
        cerr << err.what() << endl;
    }

    return 0;
}

void processPositive(int num)
{
    if (num >= 0 && num < 100)
    {
        cout << "Successful input passed in." << endl;
    }
    else if (num > 100)
    {
        throw out_of_range("Input is out of range. . .");
    }
    else
    {
        throw invalid_argument("Non-positive integer passed in."); 
    }
}

void doSomething(int num)
{
    try
    {
        processPositive(num);
    }
    catch(const invalid_argument& err)
    {
        throw;
    }
    catch(const out_of_range& err)
    {
        throw;
    }
}