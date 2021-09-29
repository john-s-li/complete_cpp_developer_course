#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "Stack.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayStack : public Stack
{
    public:
        // Constructor
        ArrayStack(int s = 16) : _MAX_SIZE(s)
        {
            this->_top = -1; // indicate that there's no elements
            this->_array = new int[this->_MAX_SIZE];
        }

        void push(int newEntry)
        {
            if(this->_top == this->_MAX_SIZE-1)
            {
                throw out_of_range("Array Stack already full.");
            }
            this->_top++; // go from -1 to 0
            this->_array[this->_top] = newEntry;
        }

        int pop()
        {
            if(this->isEmpty())
            {
                throw out_of_range("Array Stack is empty.");
            }
            int data = this->_array[this->_top];
            this->_top--;

            return data;
        }

        int peek() const
        {
            if(this->isEmpty())
            {
                cout << "Stack is empty. . .\n";
            }
            return this->_array[this->_top];
        }

        bool isEmpty() const
        {
            return this->_top == -1;
        }

        void makeEmpty()
        {
            this->_top = -1;
        }

    private:
        int _MAX_SIZE;
        int* _array;
        int _top;

}; // end class

#endif