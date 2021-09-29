#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "List.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Node Class ------------------------------------------------------------------------
class Node
{
    public:
        // Constructor
        Node(int data, Node* next) : _data(data) , _next(next) {}
        // Member functions
        int getData() const { return this->_data; }
        void setData(int data) { this->_data = data; }
        Node* getNext() const { return this->_next; }
        void setNext(Node* next) { this->_next = next; }

    private:
        int _data;
        Node* _next;

}; // end class

// Linked List Class -----------------------------------------------------------------
class LinkedList : public List
{
    public:

        LinkedList() : _head(nullptr) , _numElements(0) {}

        virtual ~LinkedList() // always make destructors virtual (good habit)
        {
            this->makeEmpty();
        }

        void add(int newEntry)
        {
            Node* nextPtr = new Node(newEntry, this->_head);
            this->_head = nextPtr;
            this->_numElements++;
        }

        void add(int newEntry, int position)
        {
            if (position < 0 || position > this->_numElements) // can add @ the end
            {
                throw out_of_range("Add. Position invalid.");
            }

            if (position == 0)
            {
                Node* insertNode = new Node(newEntry, this->_head);
                this->_head = insertNode;
                this->_numElements++;
                return;
            }

            // Walk through the Linked List
            int step = 0;
            Node* after = this->_head->getNext();
            Node* before = this->_head;

            for(int i = 0; i < position - 1; i++)
            {
                // Catch the node right before position & save it
                before = before->getNext();
                // Now get node right after and save it
                after = before->getNext();
            }
            Node* insertNode = new Node(newEntry, after);
            before->setNext(insertNode);

            this->_numElements++;
        }

        void set(int newEntry, int position)
        {
            if (position < 0 || position > this->_numElements)
            {
                throw out_of_range("Set. Position invalid.");
            }

            Node* walker = this->_head;
            int step = 0;

            while(walker != nullptr)
            {
                if (step == position)
                {
                    walker->setData(newEntry);
                    break;
                }
            }
        }

        bool contains(int entry)
        {
            Node* walker = this->_head;

            while(walker != nullptr)
            {
                if (walker->getData() == entry)
                {
                    return true;
                }
                walker = walker->getNext();
            }
            return false;
        }

        int find(int entry)
        {
            Node* walker = this->_head;

            int idx = 0;
            while(walker != nullptr)
            {
                if(walker->getData() == entry)
                {
                    return idx;
                }
                walker = walker->getNext();
                idx++;
            }
            return -1;
        }

        void remove(int position)
        {
            if (position < 0 || position > this->_numElements)
            {
                throw out_of_range("Add. Position invalid.");
            }

            // Walk through the Linked List
            int step = 0;
            Node* walker = this->_head;
            Node* previous = nullptr;

            // Need to keep track of the previous Node as well
            while(walker != nullptr)
            {
                if (step == position)
                {
                    // Make a temp of the next Node of the Node to be deleted
                    Node* tempNode = walker->getNext();
                    previous->setNext(tempNode);
                    delete walker;
                    walker = nullptr;
                    break;
                }
                else
                {
                    previous = walker;
                    walker = walker->getNext();
                }
                step++;
            }
            this->_numElements--;
        }

        void makeEmpty()
        {
            Node* next = this->_head->getNext();
            Node* current = this->_head;

            while(next != nullptr)
            {
                delete current;
                current = nullptr;

                current = next;
                next = next->getNext();
            }
        }

        int size() const { return this->_numElements; }

        bool isEmpty() const { return this->_numElements == 0; }

        void printList() const
        {
            cout << "Printing list: \n";
            Node* walker = this->_head;
            for(int i = 0; i < this->_numElements; i++)
            {
                cout << walker->getData() << endl;
                walker = walker->getNext();
            }
            cout << endl;
        }

        void reverseList()
        {
            Node* previous = nullptr;
            Node* current = this->_head;
            Node* next = nullptr;

            while(current != nullptr)
            {
                next = current->getNext();
                current->setNext(previous);
                previous = current;
                current = next;
            }
            this->_head = previous;
        }

    private:
        Node* _head;
        int _numElements;

}; // end class

#endif