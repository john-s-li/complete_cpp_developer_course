#include <iostream>
#include "Node.hpp"

using namespace std;

Node<int>* createChain();
void deleteChain(Node<int>*& head);
void printChain(Node<int>* head);
void reverseChain(Node<int>*& head);

int main()
{
    Node<int>* headPtr;

    headPtr = createChain();
    printChain(headPtr);

    cout << "Reversing the list\n";
    reverseChain(headPtr);
    printChain(headPtr);

    cout << "Now deleting the chain. . .\n";
    deleteChain(headPtr);

    return 0;
}

Node<int>* createChain()
{
    Node<int>*headPtr = nullptr; // so code can compile

    for(int i = 0; i < 25; i++)
    {
        headPtr = new Node<int>(i, headPtr); // First node points to null (will be last element of list)
    }

    return headPtr;
}

void deleteChain(Node<int>*& head)
{
    Node<int>* nodeToDelete;

    while(head != nullptr)
    {
        nodeToDelete = head;
        head = head->getNext();
        delete nodeToDelete;
    }
}

void printChain(Node<int>* head)
{
    int count = 0;
    Node<int>* walker = head;

    while(walker != nullptr)
    {
        cout << walker->getData() << endl;
        walker = walker->getNext();
        count++;
    }

    cout << "Num elements = " << count << endl;
}

void reverseChain(Node<int>*& head)
{
    Node<int>* prevNode = nullptr;
    Node<int>* nextNode = nullptr;
    Node<int>* currNode = head;

    while( currNode != nullptr )
    {
        nextNode = currNode->getNext();
        currNode->setNext(prevNode);
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}