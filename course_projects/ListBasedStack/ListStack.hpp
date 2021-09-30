#ifndef LIST_STACK_H
#define LIST_STACK_H

#include "LinkedList.hpp"
#include "Stack.h"

using namespace std;

class ListStack : public LinkedList , public Stack
{
    public:

        ListStack() : _head(nullptr) , _numElements(0)
        {}

        virtual ~ListStack()
        {}

        void push(int newEntry)
        {
            LinkedList::add(newEntry);
        }

        int pop()
        {
            return remove(0);
        }

        int peek()
        {
            // will be the most recent node
            return remove(0);
        }

        bool isEmpty() const
        {
            return LinkedList::isEmpty();
        }

        void makeEmpty()
        {
            LinkedList::makeEmpty();
        }

    private:
        Node* _head;
        int _numElements;

}; // end class

#endif