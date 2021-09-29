#include "LinkedList.hpp"
#include <iostream>

using namespace std;

int main()
{
    int userLength;
    LinkedList myList;
    
    cout << "How long would you like your LinkedList to be?\n";
    cin >> userLength;

    for(int i = 0; i < userLength; i++)
    {
        myList.add(i);
    }
    myList.printList();

    cout << "Now adding a new entry @ beginning of Linked List\n";
    myList.add(20,0);
    myList.printList();

    cout << "Now removing an entry in Linked List index 1\n";
    myList.remove(1);
    myList.printList();

    cout << "Now adding an entry to back of Linked List\n";
    myList.add(69, myList.size());
    myList.printList();

    cout << "Reversing the Linked List\n";
    myList.reverseList();
    myList.printList();

    cout << "Now looking for 69 in Linked List\n";
    cout << "Index found = " << myList.find(69) << endl;

    return 0;
}