#include "ArrayList.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void tryAdding(ArrayList &myList, int entry, int position);

int main()
{
    int userLength;

    cout << "How long would you like your array to be?" << endl;
    cin >> userLength;

    ArrayList myList(userLength);

    for(int i = 0; i < userLength; i++)
    {
        myList.add(i*2);
    }

    cout << "Printing out list ---\n";
    myList.printList();

    cout << "Removing an element ---\n";
    myList.remove(5);
    myList.printList();

    cout << "Adding an element ---\n";
    myList.add(555, 2);
    myList.printList();

    try
    {   
        cout << "Try to catch an exception!\n";
        tryAdding(myList, 69, 100);

    }
    catch(const out_of_range& err)
    {
        std::cerr << err.what() << '\n';
    }
    
    return 0;
}


void tryAdding(ArrayList &myList, int entry, int position)
{
    try
    {
        myList.add(entry, position);
    }
    catch(const out_of_range& e)
    {
        throw;
    }
}