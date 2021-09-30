#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "Queue.h"

using namespace std;

// Node Class (doubly linked) -----------------------------------------------------
class Node
{
    public:
        Node(int data, Node* next, Node* prev)
            : _data(data),
              _prev(prev),
              _next(next)
        {}

        void setData(int data) { this->_data = data; }
        void setNext(Node* next) { this->_next = next; }
        void setPrevious(Node* prev) { this->_prev = prev; }

        int getData() const { return this->_data; }

        Node* getNext() const { return this->_next; }
        Node* getPrevious() const { return this->_prev; }

    private:
        Node* _prev;
        Node* _next;
        int _data;

}; // end class


// Linked Queue Class -------------------------------------------------------------

class LinkedQueue : public Queue
{
    public:
        LinkedQueue()
            : _head(nullptr),
              _end(nullptr)
        {}

        virtual ~LinkedQueue()
        {
            this->makeEmpty();
        }

        void enqueue(int newEntry)
        {
            // Adds to the back
            Node* toAdd = new Node(newEntry, this->_end, nullptr); // No back
            if(this->_end == nullptr)
            {
                this->_head = toAdd;

            }
            else
            {
                this->_end->setNext(toAdd);
            }
            this->_end = toAdd;
        }

        int dequeue()
        {
            if(this->isEmpty())
            {
                cout << "Cannot dequeue from empty queue list." << endl;
                return -1;
            }

            int val = this->_head->getData();

            // Now delete this head...
            Node* temp = this->_head;
            this->_head = temp->getNext(); // = nullptr when @ end, following is previous
            delete temp;

            // If front becomes null, also change back to null
            if(this->_head == nullptr)
            {
                this->_end = nullptr;
            }
            else
            {
                this->_head->setPrevious(nullptr);
            }

            return val;
        }

        int peekFront() const
        {
            if(this->isEmpty())
            {
                cout << "Cannot peak at empty queue.\n";
                return -1;
            }
            // Return what is in the front
            return this->_head->getData();
        }

        bool isEmpty() const
        {
            return this->_head == this->_end;
        }

        void makeEmpty()
        {
            // Delete all Nodes
            while(!(this->isEmpty()))
            {
                this->dequeue();
            }
        }

    private:
        Node* _head;
        Node* _end;

}; // end class

#endif